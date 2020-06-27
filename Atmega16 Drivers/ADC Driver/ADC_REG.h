//****************************************************************************
 #ifndef	ADC_REG_H_
 #define	ADC_REG_H_
 
 
 
//	ADC Registers
#define ADCL						(*((volatile u8*)(0x24)))
#define ADCH						(*((volatile u8*)(0x25)))
#define ADCSRA						(*((volatile u8*)(0x26)))
#define ADMUX						(*((volatile u8*)(0x27)))
#define SFIOR						(*((volatile u8*)(0x50)))






//	ADC Registers Bits
//ADMUX Register
#define			MUX0							0
#define			MUX1							1
#define			MUX2							2
#define			MUX3							3
#define			MUX4							4
#define			ADLAR							5
#define			REFS0							6		 
#define			REFS1							7 

//ADCSRA Register
#define			ADPS0							0
#define			ADPS1							1
#define			ADPS2							2
#define			ADIE							3
#define			ADIF							4
#define			ADATE							5
#define			ADSC							6								
#define			ADEN							7

//SFIOR Register
#define			ADTS0							5
#define			ADTS1							6
#define			ADTS2							7


 
 
#endif
//****************************************************************************