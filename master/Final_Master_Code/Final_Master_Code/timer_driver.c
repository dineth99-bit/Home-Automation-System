/*
 * timer_driver.c
 *
 * Created: 8/20/2023 12:02:47 AM
 *  Author: Dineth Jayakody
 */ 

#include "timer_driver.h"
#include <avr/io.h>

void timer0_initializeCTC(void)
{
	//Config OCR0
	//OCR0 = the value to compare with
	OCR1A = 78; //to achieve tick equal to 10
	
	//Set timer mode
	//Set the mode as Compare match
	SET_BIT(TCCR0A, WGM01);
	CLR_BIT(TCCR0A, WGM00);
	
	//Configure clock
	SET_BIT(TCCR0A, CS00);
	CLR_BIT(TCCR0A, CS01);
	SET_BIT(TCCR0A, CS02);
	
	//Enable global interrupts
	sei();
	
	//Enable timer 0 interrupt for compare match
	SET_BIT(TIMSK0, OCIE0A);
}

void timer0_stop(void)
{
	//disable the clock to stop the counter
	CLR_BIT(TCCR0A, CS00);
	CLR_BIT(TCCR0A, CS01);
	CLR_BIT(TCCR0A, CS02);
}
void timer_initializefastpwm(void)
{
	//Config OCR0
	//OCR0 = the value to compare with
	OCR1A = 128;
	
	//Set timer mode
	//adjust fast pulse width modulation mode
	SET_BIT(TCCR0A, WGM00);
	SET_BIT(TCCR0A, WGM01);
	
	//Enable global interrupts
	sei();
	
	SET_BIT(TCCR0A, COM0A1); //adjust non inverting mode
	
	//Enable timer0 interrupt for overflow mode
	SET_BIT(TIMSK0,TOIE0);
	
	//Configure clock
	
	SET_BIT(TCCR0A, CS00);
	CLR_BIT(TCCR0A, CS01);
	SET_BIT(TCCR0A, CS02);
}
void change_dutycycle(float64 duty)
{
	OCR1A = (duty / 100) * 256;//Set the OCR0 depending on the duty percentage
}

