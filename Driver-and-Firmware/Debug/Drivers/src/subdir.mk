################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/ADC_STM32_DRIVER.c \
../Drivers/src/GPIO_STM32_DRIVER.c \
../Drivers/src/I2C_STM32_DRIVER.c \
../Drivers/src/TIMER25_STM32_DRIVER.c 

OBJS += \
./Drivers/src/ADC_STM32_DRIVER.o \
./Drivers/src/GPIO_STM32_DRIVER.o \
./Drivers/src/I2C_STM32_DRIVER.o \
./Drivers/src/TIMER25_STM32_DRIVER.o 

C_DEPS += \
./Drivers/src/ADC_STM32_DRIVER.d \
./Drivers/src/GPIO_STM32_DRIVER.d \
./Drivers/src/I2C_STM32_DRIVER.d \
./Drivers/src/TIMER25_STM32_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o Drivers/src/%.su Drivers/src/%.cyclo: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/media/kj-vivek/Projects/Driver-and-Firmware-STM32Disc/Drivers-and-Firmware-STM32Disc/Driver-and-Firmware/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-src

clean-Drivers-2f-src:
	-$(RM) ./Drivers/src/ADC_STM32_DRIVER.cyclo ./Drivers/src/ADC_STM32_DRIVER.d ./Drivers/src/ADC_STM32_DRIVER.o ./Drivers/src/ADC_STM32_DRIVER.su ./Drivers/src/GPIO_STM32_DRIVER.cyclo ./Drivers/src/GPIO_STM32_DRIVER.d ./Drivers/src/GPIO_STM32_DRIVER.o ./Drivers/src/GPIO_STM32_DRIVER.su ./Drivers/src/I2C_STM32_DRIVER.cyclo ./Drivers/src/I2C_STM32_DRIVER.d ./Drivers/src/I2C_STM32_DRIVER.o ./Drivers/src/I2C_STM32_DRIVER.su ./Drivers/src/TIMER25_STM32_DRIVER.cyclo ./Drivers/src/TIMER25_STM32_DRIVER.d ./Drivers/src/TIMER25_STM32_DRIVER.o ./Drivers/src/TIMER25_STM32_DRIVER.su

.PHONY: clean-Drivers-2f-src

