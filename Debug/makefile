################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/ole/CodeComposerStudio10/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main_free_uart_queues.obj" \
"./startup_ccs.obj" \
"./hal/nvic/src/cpu.obj" \
"./hal/nvic/src/interrupt.obj" \
"./hal/nvic/src/nvic.obj" \
"./hal/uart/src/uart.obj" \
"./rtos/FreeRTOS/source/croutine.obj" \
"./rtos/FreeRTOS/source/event_groups.obj" \
"./rtos/FreeRTOS/source/list.obj" \
"./rtos/FreeRTOS/source/queue.obj" \
"./rtos/FreeRTOS/source/stream_buffer.obj" \
"./rtos/FreeRTOS/source/tasks.obj" \
"./rtos/FreeRTOS/source/timers.obj" \
"./rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/port.obj" \
"./rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/portasm.obj" \
"./rtos/FreeRTOS/source/portable/MemMang/heap_1.obj" \
"./utils/circularBuffer/src/circularBuffer.obj" \
"../tm4c1294ncpdt.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"/home/ole/CodeComposerStudio10/TivaWare_C_Series-2.1.4.178/driverlib/ccs/Debug/driverlib.lib" \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include hal/nvic/src/subdir_vars.mk
-include hal/uart/src/subdir_vars.mk
-include rtos/FreeRTOS/source/subdir_vars.mk
-include rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/subdir_vars.mk
-include rtos/FreeRTOS/source/portable/MemMang/subdir_vars.mk
-include utils/circularBuffer/src/subdir_vars.mk
-include subdir_rules.mk
-include hal/nvic/src/subdir_rules.mk
-include hal/uart/src/subdir_rules.mk
-include rtos/FreeRTOS/source/subdir_rules.mk
-include rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/subdir_rules.mk
-include rtos/FreeRTOS/source/portable/MemMang/subdir_rules.mk
-include utils/circularBuffer/src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
FreeRTOS_UART_Queues.out \

EXE_OUTPUTS__QUOTED += \
"FreeRTOS_UART_Queues.out" \

BIN_OUTPUTS += \
FreeRTOS_UART_Queues.hex \

BIN_OUTPUTS__QUOTED += \
"FreeRTOS_UART_Queues.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "FreeRTOS_UART_Queues.out"

# Tool invocations
FreeRTOS_UART_Queues.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"/home/ole/CodeComposerStudio10/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C1294NCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"FreeRTOS_UART_Queues.map" --heap_size=10000 --stack_size=10000 -i"/home/ole/CodeComposerStudio10/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/lib" -i"/home/ole/CodeComposerStudio10/TivaWare_C_Series-2.1.4.178/driverlib/ccs/Debug/driverlib.lib" -i"/home/ole/CodeComposerStudio10/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="FreeRTOS_UART_Queues_linkInfo.xml" --rom_model -o "FreeRTOS_UART_Queues.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

FreeRTOS_UART_Queues.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"/home/ole/CodeComposerStudio10/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armhex"  -o "FreeRTOS_UART_Queues.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main_free_uart_queues.obj" "startup_ccs.obj" "hal/nvic/src/cpu.obj" "hal/nvic/src/interrupt.obj" "hal/nvic/src/nvic.obj" "hal/uart/src/uart.obj" "rtos/FreeRTOS/source/croutine.obj" "rtos/FreeRTOS/source/event_groups.obj" "rtos/FreeRTOS/source/list.obj" "rtos/FreeRTOS/source/queue.obj" "rtos/FreeRTOS/source/stream_buffer.obj" "rtos/FreeRTOS/source/tasks.obj" "rtos/FreeRTOS/source/timers.obj" "rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/port.obj" "rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/portasm.obj" "rtos/FreeRTOS/source/portable/MemMang/heap_1.obj" "utils/circularBuffer/src/circularBuffer.obj" 
	-$(RM) "main_free_uart_queues.d" "startup_ccs.d" "hal/nvic/src/cpu.d" "hal/nvic/src/interrupt.d" "hal/nvic/src/nvic.d" "hal/uart/src/uart.d" "rtos/FreeRTOS/source/croutine.d" "rtos/FreeRTOS/source/event_groups.d" "rtos/FreeRTOS/source/list.d" "rtos/FreeRTOS/source/queue.d" "rtos/FreeRTOS/source/stream_buffer.d" "rtos/FreeRTOS/source/tasks.d" "rtos/FreeRTOS/source/timers.d" "rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/port.d" "rtos/FreeRTOS/source/portable/MemMang/heap_1.d" "utils/circularBuffer/src/circularBuffer.d" 
	-$(RM) "rtos/FreeRTOS/source/portable/CCS/ARM_CM4F/portasm.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

