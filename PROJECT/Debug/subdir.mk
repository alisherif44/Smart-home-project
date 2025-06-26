################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DCM_program.c \
../DIO_prog.c \
../EEPROM_program.c \
../EXTI_program.c \
../GI_program.c \
../KPD_prog.c \
../LCD_program.c \
../LED_program.c \
../LM35_program.c \
../SERVO_program.c \
../TIMER0_prog.c \
../TIMER1_program.c \
../TWI_program.c \
../UART_program.c \
../main.c \
../smarthome_program.c 

OBJS += \
./ADC_program.o \
./DCM_program.o \
./DIO_prog.o \
./EEPROM_program.o \
./EXTI_program.o \
./GI_program.o \
./KPD_prog.o \
./LCD_program.o \
./LED_program.o \
./LM35_program.o \
./SERVO_program.o \
./TIMER0_prog.o \
./TIMER1_program.o \
./TWI_program.o \
./UART_program.o \
./main.o \
./smarthome_program.o 

C_DEPS += \
./ADC_program.d \
./DCM_program.d \
./DIO_prog.d \
./EEPROM_program.d \
./EXTI_program.d \
./GI_program.d \
./KPD_prog.d \
./LCD_program.d \
./LED_program.d \
./LM35_program.d \
./SERVO_program.d \
./TIMER0_prog.d \
./TIMER1_program.d \
./TWI_program.d \
./UART_program.d \
./main.d \
./smarthome_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


