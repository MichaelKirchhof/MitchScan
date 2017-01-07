################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../trunk/OpenCvTest.cpp 

OBJS += \
./trunk/OpenCvTest.o 

CPP_DEPS += \
./trunk/OpenCvTest.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/%.o: ../trunk/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


