//****************************************************************************
 #ifndef	ADC__H_
 #define	ADC__H_


 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "ADC_Config.h"
 #include "ADC_REG.h"
 #include "avr/interrupt.h"
 
  
 //	Functions Prototypes
void ADC_Init(void);
void ADC_Start_Conversion(void);
u16 ADC_Read(void);  
void ADC_Switch_SingleChannel(u8 channel);
void ADC_Disable(void);
  
 
#endif
//****************************************************************************