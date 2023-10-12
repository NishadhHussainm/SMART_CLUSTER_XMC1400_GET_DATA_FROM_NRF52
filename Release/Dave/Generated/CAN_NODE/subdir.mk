################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/CAN_NODE/can_node.c \
../Dave/Generated/CAN_NODE/can_node_conf.c 

C_DEPS += \
./Dave/Generated/CAN_NODE/can_node.d \
./Dave/Generated/CAN_NODE/can_node_conf.d 

OBJS += \
./Dave/Generated/CAN_NODE/can_node.o \
./Dave/Generated/CAN_NODE/can_node_conf.o 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/CAN_NODE/%.o: ../Dave/Generated/CAN_NODE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC1404_Q064x0200 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC1400_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -Os -ffunction-sections -fdata-sections -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m0 -mthumb -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

