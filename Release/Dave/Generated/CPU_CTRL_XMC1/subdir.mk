################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/CPU_CTRL_XMC1/cpu_ctrl_xmc1.c \
../Dave/Generated/CPU_CTRL_XMC1/cpu_ctrl_xmc1_conf.c 

C_DEPS += \
./Dave/Generated/CPU_CTRL_XMC1/cpu_ctrl_xmc1.d \
./Dave/Generated/CPU_CTRL_XMC1/cpu_ctrl_xmc1_conf.d 

OBJS += \
./Dave/Generated/CPU_CTRL_XMC1/cpu_ctrl_xmc1.o \
./Dave/Generated/CPU_CTRL_XMC1/cpu_ctrl_xmc1_conf.o 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/CPU_CTRL_XMC1/%.o: ../Dave/Generated/CPU_CTRL_XMC1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC1404_Q064x0200 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC1400_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -Os -ffunction-sections -fdata-sections -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m0 -mthumb -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

