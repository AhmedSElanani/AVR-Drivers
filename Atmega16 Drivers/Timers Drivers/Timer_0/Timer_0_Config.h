//****************************************************************************
 #ifndef	TIMER_0_CONFIG_H_
 #define	TIMER_0_CONFIG_H_
 
 
/* Define CPU Clock */
#ifndef	F_CPU
#define	F_CPU												16000000UL			   //16MHz
#endif


/* Select Timer_0 Mode */
#define		Timer_0_MODE									0					   // (0) for Normal mode, (1) for CTC, (2) for Fast PWM, (3) for Phase correct, 

/* Select Compare Match Mode */
//For NON PWM Mode only
#define		COM_NonPWM										0					   // (0)Disconnected, (1)Toggle, (2)Clear, (3)Set 
//For Fast PWM Mode only
#define		COM_FastPWM										0					   // (0)Disconnected, (1)Non Inverting, (2)Inverting
//For Phase Correct PWM Mode only
#define		COM_PhasePWM									0					   // (0)Disconnected, (1) , (2)

/* Select the Clock for Timer_0 */
#define		Clock_Select									0					   // From (0) to (7) 

/* Output Compare Match Interrupt Enable */
#define		OutputCompare_Interrupt_Enable					0					   // (0) to disable, (1) to Enable

/* Overflow Interrupt Enable */
#define		Overflow_Interrupt_Enable						0					   // (0) to disable, (1) to Enable


#endif
//****************************************************************************