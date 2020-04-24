#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>
#include <driverlib/interrupt.h>
#include <driverlib/systick.h>
#include <inc/hw_memmap.h> // GPIO_PORTN_BASE, GPIO_PORTJ_AHB_BASE
#include <inc/tm4c1294ncpdt.h>

// HAL libraries
#include "hal/uart/uart.h"
#include "hal/nvic/nvic.h"

//FreeRTOS headers
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

// function prototypes
//extern void xPortSysTickHandler(void);
static void hardware_setup(void);
static void taskButtonPressed(void * taskParameters);
static void taskReceive(void * taskParameters);
static void taskTransmit(void * taskParameters);

/**
 * Constant specifying the length of the message, i.e.
 * number of bytes to be received (Rx) or send (Tx).
 *
 * It is preferable to use enums instead of
 * #define messageLength_
 *
 * The underscore (_) is a naming convention.
 * It tells us that the type is not public, i.e.
 * it will not be used outside of this file.
 */
enum GreetingMessageLength_ {
    greetingMessageLength_ = 30
};

enum UartAreaMemorySize_ {
    uartAreaMemorySize_ = 20
};

enum echoBufferSize_ {
    echoBufferSize_ = 30
};

/**
 * Static variables will not be seen outside
 * of their compilation unit.
 */
// extra character for the '\0' termination of the string
//static char messageBuffer_[greetingMessageLength_];
static char const greetingMessage_[greetingMessageLength_ + 1] = "##### Echo! Echo! Echo! #####\n";

static char uartMemoryAreaTx_[uartAreaMemorySize_];
static char uartMemoryAreaRx_[uartAreaMemorySize_];


// structure containing parameters passed to TaskPeriodic function
typedef struct{
    HalUartCoreStateHandle * handle;        // pointer to handle core initialization
    QueueHandle_t MessageQueue;             // queue handle
} TPParams_;


static TaskHandle_t xHandlingButtons = NULL;
static TaskHandle_t xHandlingReceive = NULL;

/* ISR for the 2 buttons on evaluation board */
void INT_Handler_Port_J(void)
{
    BaseType_t xHigherPriorityTaskWoken;

    GPIOIntClear(GPIO_PORTJ_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_0);

    /* We have not woken a task at the start of the ISR. */
    xHigherPriorityTaskWoken = pdFALSE;

    vTaskNotifyGiveFromISR( xHandlingButtons, &xHigherPriorityTaskWoken );

    /* Force a context switch if xHigherPriorityTaskWoken is now set to pdTRUE.
    The macro used to do this is dependent on the port and may be called
    portEND_SWITCHING_ISR. */
    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}


/********************** Main-function ******************************/
int main(void) {

    unsigned int sentBytesCount;

    TPParams_ TPprint1;

    // UART driver initialization
    halUartDriverInit();

    // GPIO initialization with Interrupts
    hardware_setup();

    // UART2 core initialization parameters
    enum HalUartBaudRate uartBaudRate = halUartBaudRate115200;
    enum HalUartWordLength uartWordlength = halUartEightBits;
    enum HalUartStopBit uartStopBit = halUartOneStopBit;
    enum HalUartParity uartParity = halUartNoParity;

    // UART core initialization
    HalUartCoreStateHandle handle = halUartCoreInit(halUart0RxPA0TxPA1,
                                                    uartBaudRate,
                                                    uartWordlength,
                                                    uartStopBit,
                                                    uartParity,
                                                    &uartMemoryAreaTx_[0],
                                                    uartAreaMemorySize_,
                                                    &uartMemoryAreaRx_[0],
                                                    uartAreaMemorySize_);

    TPprint1.handle = &handle;
    TPprint1.MessageQueue = xQueueCreate(echoBufferSize_, sizeof(char));

    for(sentBytesCount = 0; sentBytesCount < strlen(greetingMessage_); sentBytesCount++)             // send greetingMessage via queue to taskTransmit
    {
        xQueueSendToBack( TPprint1.MessageQueue, &greetingMessage_[sentBytesCount], 0 );
    }


    xTaskCreate(taskButtonPressed, "taskButtonPressed", 200, NULL, tskIDLE_PRIORITY + 1, &xHandlingButtons);
    xTaskCreate(taskReceive,  "receive",  200, (void *)& TPprint1, tskIDLE_PRIORITY+2, &xHandlingReceive);
    xTaskCreate(taskTransmit, "transmit", 200, (void *)& TPprint1, tskIDLE_PRIORITY+1, NULL);

    // start FreeRTOS scheduler
    vTaskStartScheduler();

    while(1);
}


/********************** test task for UART receive ****************************/
void taskReceive(void * taskParameters)
{
    volatile uint32_t lv;
    char receiveBuffer[echoBufferSize_];
    unsigned int receivedBytesCount, receivedBytesCountOld;

    // parameter variable cast
    TPParams_ const * const taskParametersCast = (TPParams_ *)taskParameters;
    HalUartCoreStateHandle handle = *taskParametersCast->handle;
    QueueHandle_t const MessageQueue = taskParametersCast->MessageQueue;

    while(1)
    {
        ulTaskNotifyTake( pdTRUE, pdMS_TO_TICKS( 1000 ) );     // Blocked until Task Notification (from taskButtonPressed) or 1 s passed

        receivedBytesCount = 0;
        receivedBytesCountOld = 0;
        while (receivedBytesCount < echoBufferSize_) {
            receivedBytesCount += halUartRx(
                    &receiveBuffer[receivedBytesCount],
                    echoBufferSize_ - receivedBytesCount,
                    handle);
            if(receivedBytesCount != receivedBytesCountOld)     // check if new data was received
            {
                receivedBytesCountOld = receivedBytesCount;
            }
            else
            {
                break;                                         // break if no new data is available
            }
        }
        for(lv = 0; lv < receivedBytesCount; lv++)             // send received data via queue to taskTransmit
        {
            xQueueSendToBack( MessageQueue, &receiveBuffer[lv], 0 );
        }
    }
}

/********************** test task for UART transmit ****************************/
void taskTransmit(void * taskParameters)
{
    volatile uint32_t lv;
    char lReceivedValue;
    // parameter variable cast
    TPParams_ const * const taskParametersCast = (TPParams_ *)taskParameters;
    QueueHandle_t const MessageQueue = taskParametersCast->MessageQueue;

    HalUartCoreStateHandle handle = *taskParametersCast->handle;

    while(1)
    {
        while (xQueueReceive( MessageQueue, &lReceivedValue, portMAX_DELAY ) != 0)
        {
            halUartTx(&lReceivedValue, 1, handle);
        }
    }
}


/************************ Butten pressed Task ******************************/
/* communicates via Task Notification from Button ISR and sends a receive request to taskReceive */
static void taskButtonPressed(void * taskParameters)
{
    while(1)
    {
        ulTaskNotifyTake( pdTRUE, portMAX_DELAY );              // Blocked until Task Notification (from Button ISR)

        if(!GPIOPinRead(GPIO_PORTJ_AHB_BASE, GPIO_PIN_0))       // Button 1 pressed
        {
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 | GPIO_PIN_0, 2);
        }

        if(!GPIOPinRead(GPIO_PORTJ_AHB_BASE, GPIO_PIN_1))       // Button 2 pressed
        {
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 | GPIO_PIN_0, 1);
        }

        while(GPIOPinRead(GPIO_PORTJ_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_0) != 0x03)        // Wait for button release
        vTaskDelay(pdMS_TO_TICKS( 10 ));                                                                 // small delay for debouncing
        xTaskNotifyGive(xHandlingReceive);                                              // Notify taskReceive to get data
    }
}


/************* setup LEDs Outputs and button inputs ******************************/
void hardware_setup(void)
{
//    SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |         // currently not support by UART driver
//                       SYSCTL_CFG_VCO_480, 120000000);


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION));
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ));

    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1 | GPIO_PIN_0);
    GPIOPinTypeGPIOInput(GPIO_PORTJ_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_0);

    GPIOPadConfigSet(GPIO_PORTJ_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_0,
                     GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    GPIOIntTypeSet(GPIO_PORTJ_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_0,
                   GPIO_FALLING_EDGE);

//    GPIOIntRegister(GPIO_PORTJ_AHB_BASE, INT_Handler_Port_J);
    GPIOIntEnable(GPIO_PORTJ_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_0);
    IntEnable(INT_GPIOJ);
    NVIC_EN1_R |= (1 << 0x13);      // enable PortJ interrupt (Int#33/Vec#20) in NVIC
//    SysTickIntRegister(xPortSysTickHandler);

    IntMasterEnable();
}

