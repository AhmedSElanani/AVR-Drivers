//****************************************************************************
 #ifndef	TIMER_0_H_
 #define	TIMER_0_H_

 #include "DIO_INIT.h"
 #include "avr/interrupt.h"
 #include "Timer_0_Config.h"
 #include "Timer_0_REG.h"
 
 
 //	Constants
 #define		OC0									3			//Define Output Pin
 
  
 //	Functions Prototypes
void Timer0_Init(void);
void Timer0_disable(void);
void Timer0_ChangePrescaler(u8 Prescaler);
void TCNT0_Write(u8 value);
u8 TCNT0_Read(void);
void OCR0_Write(u8 value);
u8 OCR0_Read(void);
void TIMER0_OVF_Callback(void(*function_ptr) (void));
void TIMER0_COMP_Callback(void(*function_ptr) (void));


#endif
//****************************************************************************