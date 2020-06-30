//****************************************************************************
#include "Timer_0.h"



/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static volatile void (*G_TIMER0_OVF)   (void)='\0' ;
static volatile void (*G_TIMER0_COMP)  (void)='\0' ;



/*******************************************************************************
 *									ISRs	    	                           *
 *******************************************************************************/
ISR(TIMER0_OVF_vect)
{
	if (G_TIMER0_OVF!='\0')
	{
		(*G_TIMER0_OVF)();
	}
}


ISR(TIMER0_COMP_vect)
{
	if (G_TIMER0_COMP!='\0')
	{
		(*G_TIMER0_COMP)();
	}
}



/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
 void Timer0_Init(void)
{
	//	Waveform Generation Mode
	#if (Timer_0_MODE == 0)
		//Normal Mode
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	
	#elif (Timer_0_MODE == 1)
		//CTC Mode
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	
	#elif (Timer_0_MODE == 2)
		//Fast PWM Mode
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	
	#elif (Timer_0_MODE == 3)
		//Phase correct PWM
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#endif
	
	
	//	For Non PWM mode
	#if ((Timer_0_MODE == 0) || (Timer_0_MODE == 1))
		CLR_BIT(TCCR0,FOC0);
		
		//	Compare match Mode
		#if (COM_NonPWM == 0)
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		
		#elif (COM_NonPWM == 1)
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
			DIO_VidSetPinDirection(OC0,portB,OUTPUT);
		
		#elif (COM_NonPWM == 2)
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_VidSetPinDirection(OC0,portB,OUTPUT);
		
		#elif (COM_NonPWM == 3)
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_VidSetPinDirection(OC0,portB,OUTPUT);
		#endif
		
	#endif
	
	//	For Fast PWM mode
	#if (Timer_0_MODE == 2)
	
		//	Compare match Mode
		#if (COM_FastPWM == 0)
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
	
		#elif (COM_FastPWM == 1)
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_VidSetPinDirection(OC0,portB,OUTPUT);
	
		#elif (COM_FastPWM == 2)
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_VidSetPinDirection(OC0,portB,OUTPUT);
		#endif
	
	#endif
	
	
	//	For Phase correct PWM mode
	#if (Timer_0_MODE == 3)
		//	Compare match Mode
		#if (COM_PhasePWM == 0)
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
	
		#elif (COM_PhasePWM == 1)
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_VidSetPinDirection(OC0,portB,OUTPUT);
	
		#elif (COM_PhasePWM == 2)
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_VidSetPinDirection(OC0,portB,OUTPUT);
		#endif
	
	#endif
	
	
	//	Clock Select
	#if (Clock_Select == 0)
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);

	#elif (Clock_Select == 1)
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);

	#elif (Clock_Select == 2)
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);

	#elif (Clock_Select == 3)
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);

	#elif (Clock_Select == 4)
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);

	#elif (Clock_Select == 5)
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);

	#elif (Clock_Select == 6)
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);

	#elif (Clock_Select == 7)
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);

	#endif	


	// Output Compare Match Interrupt Enable
	#if (OutputCompare_Interrupt_Enable == 0)
		CLR_BIT(TIMSK,OCIE0);
	
	#elif (OutputCompare_Interrupt_Enable == 1)
		SET_BIT(TIMSK,OCIE0);
		asm volatile ("SEI");	//sei();
	#endif
	
	
	// Overflow Interrupt Enable
	#if (Overflow_Interrupt_Enable == 0)
		CLR_BIT(TIMSK,TOIE0);
	
	#elif (Overflow_Interrupt_Enable == 1)
		SET_BIT(TIMSK,TOIE0);
		asm volatile ("SEI");	//sei();
	#endif
	
}




void Timer0_disable(void)
{
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}




void Timer0_ChangePrescaler(u8 Prescaler)
{
	#if (Prescaler==1)
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);

	#elif (Prescaler==8)
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);

	#elif (Prescaler==64)
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);
		
	#elif (Prescaler==256)
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);
	
	#elif (Prescaler==1024)
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		//	Reset Prescaler
		SET_BIT(SFIOR,PSR10);
	#endif
}




void TCNT0_Write(u8 value)
{
	TCNT0 = value;
}



u8 TCNT0_Read(void)
{
	return TCNT0;
}




void OCR0_Write(u8 value)
{
	OCR0 = value;
}



u8 OCR0_Read(void)
{
	return OCR0;
}



/*
 * calling back function enable you to use Timer0_ISR
 * Any function passed to callback function will be
 * called in ISR
 */
void TIMER0_OVF_Callback(void(*function_ptr) (void))
{
	G_TIMER0_OVF=function_ptr ;
}



void TIMER0_COMP_Callback(void(*function_ptr) (void))
{
	G_TIMER0_COMP=function_ptr ;
}

 //****************************************************************************