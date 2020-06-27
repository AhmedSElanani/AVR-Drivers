//****************************************************************************
 #ifndef	ADC_CONFIG_H_
 #define	ADC_CONFIG_H_
 
 
//	Define CPU Clock
#ifndef	F_CPU
#define	F_CPU											16000000UL		//16MHz
#endif

//	Select Voltage reference ( (0) for AREF, (1) for AVCC, (2) for Internal 2.56V)
#define		Voltage_Reference								1

//	Select ADC adjust ( (0) for Right Adjust , (1) for Left Adjust)
#define		ADC_Adjust										0

//	Select number of Bits ( (10) for 10-Bits , (8) for 8-Bits)
#define		Number_Of_Bits									10

//	Select Analog Channel
#define		Single_Ended_Input								1						// (0) For Differential gain Channels mode, (1) For Single Ended Input mode
//For Single Ended Input mode Only, choose from (0) to (7) to Enable from (ADC0) to (ADC7)
#define		Single_Input_Channel							0						
//For Differential gain channel mode Only, choose from (0) to (15) to Enable corresponding mode
#define		Differential_Gain_Channel						0	

//	Select Prescaler	(You need Clock around (50KHz-200KHz) )															
#define		Prescaler										128						//	Select Prescaler from (2,4,8,16,32,64,128)

//	ADC Trigger Mode
#define		ADC_AutoTrigger_Enable							0						//	Select (0) to Disable ADC Auto trigger, (1) to Enable ADC Auto trigger
//	In case you Enabled ADC Auto trigger mode only
#define		ADC_AutoTrigger_Source							0						//	Select from (0) to (7) to choose the corresponding ADC Auto trigger source

//	ADC Interrupt Enable
#define		ADC_Interrupt_Enable							1						//	Select (0) to Disable ADC Interrupt, (1) to Enable ADC Interrupt


			
/*************************************************
 ****	 You needn't modify this part	 *********
 *************************************************/ 
 //	Single Ended Channels
 #define ADC0							0
 #define ADC1							1
 #define ADC2							2
 #define ADC3							3
 #define ADC4							4
 #define ADC5							5
 #define ADC6							6
 #define ADC7							7
/**************************************************/


 //	Single Ended Channels
 static volatile u8 channels[] = {ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7};
 

#endif
//****************************************************************************