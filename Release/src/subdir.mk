################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ArbolKD.cpp \
../src/Archivo.cpp \
../src/Byte.cpp \
../src/Clave.cpp \
../src/kdNodo.cpp \
../src/kdNodoHoja.cpp \
../src/kdNodoInterno.cpp 

OBJS += \
./src/ArbolKD.o \
./src/Archivo.o \
./src/Byte.o \
./src/Clave.o \
./src/kdNodo.o \
./src/kdNodoHoja.o \
./src/kdNodoInterno.o 

CPP_DEPS += \
./src/ArbolKD.d \
./src/Archivo.d \
./src/Byte.d \
./src/Clave.d \
./src/kdNodo.d \
./src/kdNodoHoja.d \
./src/kdNodoInterno.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


