################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Hauptprogramm.cpp 

OBJS += \
./src/Hauptprogramm.o 

CPP_DEPS += \
./src/Hauptprogramm.d 


# Each subdirectory must supply rules for building sources it contributes
src/Hauptprogramm.o: ../src/Hauptprogramm.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/michael/opencvShare/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/Hauptprogramm.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


