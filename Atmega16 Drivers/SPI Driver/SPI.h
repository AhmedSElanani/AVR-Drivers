//****************************************************************************
 #ifndef	SPI__H_
 #define	SPI__H_

 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "SPI_Config.h"
 #include "SPI_REG.h"
 #include "avr/interrupt.h"
 
   
 //	Functions Prototypes
 void SPI_Init (void);
 void SPI_Transmit(u8 data);
 u8 SPI_Read(void);
 void SPI_STC_Callback(void(*function_ptr) (void));
 
 
#endif
//****************************************************************************