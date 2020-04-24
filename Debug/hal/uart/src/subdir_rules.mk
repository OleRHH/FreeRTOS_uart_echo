################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
hal/uart/src/uart.obj: /home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/hal/uart/src/uart.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/ole/CodeComposerStudio10/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/FreeRTOS_UART_Q" --include_path="/home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/utils/circularBuffer/include" --include_path="/home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/hal/uart/include" --include_path="/home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/hal/nvic/include" --include_path="/home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/rtos/FreeRTOS/source/portable/CCS/ARM_CM4F" --include_path="/home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/rtos/FreeRTOS/source/include" --include_path="/home/ole/CodeComposerStudio10/workspace/FreeRTOS_UART_Queues/extlibs/ti/TivaWare_C_Series-2.1.4.178" --include_path="/home/ole/CodeComposerStudio10/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="hal/uart/src/$(basename $(<F)).d_raw" --obj_directory="hal/uart/src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


