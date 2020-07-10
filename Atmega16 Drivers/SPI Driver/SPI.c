//****************************************************************************
#include "SPI.h"


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static void (*volatile G_SPI_STC)(void) ='\0' ;



/*******************************************************************************
 *									ISRs	    	                           *
 *******************************************************************************/
ISR(SPI_STC_vect)
{
	if (G_SPI_STC!='\0')
	{
		(*G_SPI_STC)();
	}
}


/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
  void SPI_Init (void)
 {
	 //Check that the SPI is Enabled by the User
	 #if (SPI_Enable == 1)
	 
		//Set the Clock Polarity
		 #if (Clock_Polarity == 1)
			SET_BIT(SPCR,CPOL);
		 #elif (Clock_Polarity == 0)
			 CLR_BIT(SPCR,CPOL);
		 #endif
		 
		 //Set the Clock Phase
		  #if (Clock_Phase == 1)
			SET_BIT(SPCR,CPHA);
		  #elif (Clock_Phase == 0)
			CLR_BIT(SPCR,CPHA);
		  #endif
		
		//Configure as Master or Slave
		 #if (Master_Slave_Select == 1)
			SET_BIT(SPCR,MSTR);
		 #elif (Master_Slave_Select == 0)
			CLR_BIT(SPCR,MSTR);
		 #endif
		 
		 //Set the Clock rate
		  #if (Clock_Rate == 0)

		  #elif (Clock_Rate == 1)
		  #elif (Clock_Rate == 2)
		  
		  #elif (Clock_Rate == 3)
			//Prescaler 16
			SET_BIT(SPCR,SPR0);
			CLR_BIT(SPCR,SPR1);
			CLR_BIT(SPSR,SPI2X);
			
		  #elif (Clock_Rate == 4)
		  #elif (Clock_Rate == 5)
		  #elif (Clock_Rate == 6)

		  #endif
		 
		 //Set the Data Order
		 #if (Data_Order == 1)
			SET_BIT(SPCR,DORD);
		 #elif (Data_Order == 0)
			CLR_BIT(SPCR,DORD);
		 #endif	
		
		 //Enable the SPI
		 SET_BIT(SPCR,SPE);	
			
		 //Check that the Interrupt by the SPI is Enabled
		 #if (SPI_Interrupt_Enable == 1)
			SET_BIT(SPCR,SPIE);
			asm volatile ("SEI");	//sei();
		#endif

	#endif
 }
 
 
 void SPI_Transmit(u8 data)
 {
	//Writing to the register initiates data transmission. 
	SPDR = data;
 }
 
 
 u8 SPI_Read(void)
 {
	//Reading the register causes the Shift Register Receive buffer to be read.
	return SPDR;
 }
 
   
/*
 * calling back function enable you to use SPI_ISR
 * Any function passed to callback function will be
 * called in ISR
 */
void SPI_STC_Callback(void(*function_ptr) (void))
{
	G_SPI_STC = function_ptr ;
}




 //****************************************************************************