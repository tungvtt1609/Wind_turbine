################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/driver/controller/driver_pwm_boost.c 

OBJS += \
./app/driver/controller/driver_pwm_boost.o 

C_DEPS += \
./app/driver/controller/driver_pwm_boost.d 


# Each subdirectory must supply rules for building sources it contributes
app/driver/controller/%.o app/driver/controller/%.su: ../app/driver/controller/%.c app/driver/controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/STM32G4xx_HAL_Driver/Inc" -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"C:/Users/Thanh Tung/STM32Cube/Repository/STM32Cube_FW_G4_V1.5.1/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app-2f-driver-2f-controller

clean-app-2f-driver-2f-controller:
	-$(RM) ./app/driver/controller/driver_pwm_boost.d ./app/driver/controller/driver_pwm_boost.o ./app/driver/controller/driver_pwm_boost.su

.PHONY: clean-app-2f-driver-2f-controller

