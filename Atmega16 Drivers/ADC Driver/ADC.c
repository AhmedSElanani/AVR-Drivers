//****************************************************************************
#include "ADC.h"



 void ADC_Init(void)
{
	//Set Voltage reference
	#if (Voltage_Reference == 0)
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	
	#elif (Voltage_Reference == 1)
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);

	#elif (Voltage_Reference == 2)
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);

	#endif
	
	
	//Set Left Adjust or Right Adjust
	#if (ADC_Adjust == 0)
		CLR_BIT(ADMUX,ADLAR);
	
	#elif (ADC_Adjust == 1)
		SET_BIT(ADMUX,ADLAR);
	
	#endif
	
	
	//Set Channel Mode
	#if (Single_Ended_Input == 1)
		#if (Single_Input_Channel == 0)
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#elif (Single_Input_Channel == 1)
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#elif (Single_Input_Channel == 2)
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#elif (Single_Input_Channel == 3)
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#elif (Single_Input_Channel == 4)
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#elif (Single_Input_Channel == 5)
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#elif (Single_Input_Channel == 6)
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#elif (Single_Input_Channel == 7)
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);

		#endif
			
	#elif (Single_Ended_Input == 0)
		#if (Differential_Gain_Channel == 0)
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		
		//	Similarly fill all cases using DataSheet
		#elif (Differential_Gain_Channel == 1)
		#elif (Differential_Gain_Channel == 2)
		#elif (Differential_Gain_Channel == 3)
		#elif (Differential_Gain_Channel == 4)
		#elif (Differential_Gain_Channel == 5)
		#elif (Differential_Gain_Channel == 6)
		#elif (Differential_Gain_Channel == 7)
		#elif (Differential_Gain_Channel == 8)
		#elif (Differential_Gain_Channel == 9)
		#elif (Differential_Gain_Channel == 10)
		#elif (Differential_Gain_Channel == 11)
		#elif (Differential_Gain_Channel == 12)
		#elif (Differential_Gain_Channel == 13)
		#elif (Differential_Gain_Channel == 14)
		#elif (Differential_Gain_Channel == 15)
		
		#endif	
	
	#endif
	
	//Set Prescaler
	#if (Prescaler == 2)
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
	
	#elif (Prescaler == 4)
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
	
	#elif (Prescaler == 8)
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		
	#elif (Prescaler == 16)
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		
	#elif (Prescaler == 32)
		SET_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		
	#elif (Prescaler == 64)
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		
	#elif (Prescaler == 128)
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

	#endif 
	
	//ADC Auto trigger
	#if (ADC_AutoTrigger_Enable == 1)
		//Enable Auto Trigger
		SET_BIT(ADCSRA,ADATE);
		
		//ADC  Enable
		SET_BIT(ADCSRA,ADEN);

		#if (ADC_AutoTrigger_Source == 0)
			CLR_BIT(SFIOR,ADTS0);
			CLR_BIT(SFIOR,ADTS1);
			CLR_BIT(SFIOR,ADTS2);
			
			//start conversion
			SET_BIT(ADCSRA,ADSC);
		
		#elif (ADC_AutoTrigger_Source == 1)
			SET_BIT(SFIOR,ADTS0);
			CLR_BIT(SFIOR,ADTS1);
			CLR_BIT(SFIOR,ADTS2);
		
			//start conversion
			SET_BIT(ADCSRA,ADSC);

		#elif (ADC_AutoTrigger_Source == 2)
			CLR_BIT(SFIOR,ADTS0);
			SET_BIT(SFIOR,ADTS1);
			CLR_BIT(SFIOR,ADTS2);
			
			//start conversion
			SET_BIT(ADCSRA,ADSC);
		
		#elif (ADC_AutoTrigger_Source == 3)
			SET_BIT(SFIOR,ADTS0);
			SET_BIT(SFIOR,ADTS1);
			CLR_BIT(SFIOR,ADTS2);
			
			//start conversion
			SET_BIT(ADCSRA,ADSC);

		#elif (ADC_AutoTrigger_Source == 4)
			CLR_BIT(SFIOR,ADTS0);
			CLR_BIT(SFIOR,ADTS1);
			SET_BIT(SFIOR,ADTS2);
			
			//start conversion
			SET_BIT(ADCSRA,ADSC);

		#elif (ADC_AutoTrigger_Source == 5)
			SET_BIT(SFIOR,ADTS0);
			CLR_BIT(SFIOR,ADTS1);
			SET_BIT(SFIOR,ADTS2);
			
			//start conversion
			SET_BIT(ADCSRA,ADSC);

		#elif (ADC_AutoTrigger_Source == 6)
			CLR_BIT(SFIOR,ADTS0);
			SET_BIT(SFIOR,ADTS1);
			SET_BIT(SFIOR,ADTS2);
			
			//start conversion
			SET_BIT(ADCSRA,ADSC);

		#elif (ADC_AutoTrigger_Source == 7)
			SET_BIT(SFIOR,ADTS0);
			SET_BIT(SFIOR,ADTS1);
			SET_BIT(SFIOR,ADTS2);
			
			//start conversion
			SET_BIT(ADCSRA,ADSC);

		#endif

	#endif


	//ADC Interrupt 
	#if (ADC_Interrupt_Enable == 0)
		//ADC Interrupt	disable
		CLR_BIT(ADCSRA,ADIE);
	
	#elif (ADC_Interrupt_Enable == 1)
		//ADC Interrupt	Enable
		SET_BIT(ADCSRA,ADIE);
		asm volatile ("SEI");	//sei();

	#endif

		
}



void ADC_Start_Conversion(void)
{
	#if (ADC_AutoTrigger_Enable == 0)
		//ADC  Enable
		SET_BIT(ADCSRA,ADEN);
	
		//start conversion
		SET_BIT(ADCSRA,ADSC);
	#endif	
}



u16 ADC_Read(void)
{
	//Create a variable to hold ADC Value
	u16 ADC_Value= 0;
	
	#if (ADC_Interrupt_Enable == 0)
		//	Poll ADSC
		while(GET_BIT(ADCSRA,ADSC));		
	#endif


	#if (ADC_Adjust == 0)
		//this means right adjust
	
		#if (Number_Of_Bits == 10)
			ADC_Value = ADCL;
			ADC_Value |= ADCH<<8;
				
		#elif (Number_Of_Bits == 8)
			ADC_Value = ADCL;
			u8 temp = ADCH;
	
		#endif

	#elif (ADC_Adjust == 1)
		//this means left adjust
			
		#if (Number_Of_Bits == 10)
			ADC_Value = ADCL>>6;
			ADC_Value |= ADCH<<2;
	
		#elif (Number_Of_Bits == 8)
			ADC_Value = ADCH;
	
		#endif
	
	#endif
		
	//Disable ADC to save Power consumption
	#if (ADC_AutoTrigger_Enable == 0)
		//ADC  Disable
		CLR_BIT(ADCSRA,ADEN);
	#endif
	
	return ADC_Value;
}


void ADC_Switch_SingleChannel(u8 channel)
{
	switch(channel)
	{
		case ADC0:
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;

		case ADC1:
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		
		case ADC2:
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);		
			break;
		
		case ADC3:
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		
		case ADC4:
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;

		case ADC5:
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
		case ADC6:
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		
		case ADC7:
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
	}
	
}



void ADC_Disable(void)
{
	CLR_BIT(ADCSRA,ADEN);
}


 //****************************************************************************