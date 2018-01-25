################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Core/CornerDection.cpp \
../src/Core/Timer.cpp \
../src/Core/Typdef.cpp \
../src/Core/tFeatureDetector.cpp 

OBJS += \
./src/Core/CornerDection.o \
./src/Core/Timer.o \
./src/Core/Typdef.o \
./src/Core/tFeatureDetector.o 

CPP_DEPS += \
./src/Core/CornerDection.d \
./src/Core/Timer.d \
./src/Core/Typdef.d \
./src/Core/tFeatureDetector.d 


# Each subdirectory must supply rules for building sources it contributes
src/Core/%.o: ../src/Core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/michael/opencvShare/include/opencv2 -I/home/michael/opencvShare/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


