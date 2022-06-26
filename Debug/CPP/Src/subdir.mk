################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CPP/Src/button.cpp \
../CPP/Src/control.cpp \
../CPP/Src/encoder.cpp \
../CPP/Src/led.cpp \
../CPP/Src/main.cpp \
../CPP/Src/map.cpp \
../CPP/Src/motor.cpp \
../CPP/Src/motorControl.cpp \
../CPP/Src/position.cpp \
../CPP/Src/robot.cpp \
../CPP/Src/sensorSide.cpp 

OBJS += \
./CPP/Src/button.o \
./CPP/Src/control.o \
./CPP/Src/encoder.o \
./CPP/Src/led.o \
./CPP/Src/main.o \
./CPP/Src/map.o \
./CPP/Src/motor.o \
./CPP/Src/motorControl.o \
./CPP/Src/position.o \
./CPP/Src/robot.o \
./CPP/Src/sensorSide.o 

CPP_DEPS += \
./CPP/Src/button.d \
./CPP/Src/control.d \
./CPP/Src/encoder.d \
./CPP/Src/led.d \
./CPP/Src/main.d \
./CPP/Src/map.d \
./CPP/Src/motor.d \
./CPP/Src/motorControl.d \
./CPP/Src/position.d \
./CPP/Src/robot.d \
./CPP/Src/sensorSide.d 


# Each subdirectory must supply rules for building sources it contributes
CPP/Src/%.o: ../CPP/Src/%.cpp CPP/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Lucas Martins/STM32CubeIDE/workspace_1.7.0/Rufus_CPP/Rufus_CPP/CPP/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

