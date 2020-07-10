//****************************************************************************
 #ifndef	SPI_REG_H_
 #define	SPI_REG_H_
 
 
 
//	SPI Registers 
#ifndef	SPCR
#define SPCR						(*((volatile u8*)(0x2D)))
#endif

#ifndef	SPSR
#define SPSR						(*((volatile u8*)(0x2E)))
#endif

#ifndef	SPDR
#define SPDR						(*((volatile u8*)(0x2F)))
#endif



//	SPI Registers Bits
//SPCR Register
#define			SPR0							0
#define			SPR1							1
#define			CPHA							2
#define			CPOL							3
#define			MSTR							4
#define			DORD							5
#define			SPE 							6
#define			SPIE							7


//SPSR Register
#define			SPI2X							0		


 
#endif
//****************************************************************************
