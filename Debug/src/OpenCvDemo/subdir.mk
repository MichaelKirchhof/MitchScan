################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/OpenCvDemo/OpenCvDemo.cpp 

OBJS += \
./src/OpenCvDemo/OpenCvDemo.o 

CPP_DEPS += \
./src/OpenCvDemo/OpenCvDemo.d 


# Each subdirectory must supply rules for building sources it contributes
src/OpenCvDemo/%.o: ../src/OpenCvDemo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/michael/opencvShare/include/opencv2 -I/home/michael/opencvShare/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


