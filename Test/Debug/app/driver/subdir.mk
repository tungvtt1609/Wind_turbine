################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/driver/driver_pwm_boost.c 

OBJS += \
./app/driver/driver_pwm_boost.o 

C_DEPS += \
./app/driver/driver_pwm_boost.d 


# Each subdirectory must supply rules for building sources it contributes
app/driver/%.o app/driver/%.su: ../app/driver/%.c app/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/STM32G4xx_HAL_Driver/Inc" -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/CMSIS/Include" -I"D:/7.GITHUB/Wind_turbine/Test/app" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app-2f-driver

clean-app-2f-driver:
	-$(RM) ./app/driver/driver_pwm_boost.d ./app/driver/driver_pwm_boost.o ./app/driver/driver_pwm_boost.su

.PHONY: clean-app-2f-driver

