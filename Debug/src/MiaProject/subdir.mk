################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MiaProject/MiaProject.cpp 

OBJS += \
./src/MiaProject/MiaProject.o 

CPP_DEPS += \
./src/MiaProject/MiaProject.d 


# Each subdirectory must supply rules for building sources it contributes
src/MiaProject/%.o: ../src/MiaProject/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/michael/opencvShare/include/opencv2 -I/home/michael/opencvShare/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


