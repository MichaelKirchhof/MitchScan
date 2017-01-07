################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/OpenCvDemo.cpp \
../src/OpenCvTest.cpp \
../src/tFeatureDetector.cpp 

OBJS += \
./src/OpenCvDemo.o \
./src/OpenCvTest.o \
./src/tFeatureDetector.o 

CPP_DEPS += \
./src/OpenCvDemo.d \
./src/OpenCvTest.d \
./src/tFeatureDetector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/OpenCvTest.o: ../src/OpenCvTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/OpenCvTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


