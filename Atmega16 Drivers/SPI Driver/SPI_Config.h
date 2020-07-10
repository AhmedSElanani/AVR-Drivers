//****************************************************************************
 #ifndef	SPI_CONFIG_H_
 #define	SPI_CONFIG_H_
 
 
//	Define CPU Clock
#ifndef	F_CPU
#define	F_CPU											16000000UL		//16MHz
#endif

#define		SPI_Enable									1				// (1) to Enable, (0) to Disable
#define		SPI_Interrupt_Enable						1				// (1) to Enable, (0) to Disable
#define		Data_Order									0				// (1) for LSB first, (0) for MSB first
#define		Master_Slave_Select							1				// (1) to Configure as Master, (0) to Configure as Slave 
#define		Clock_Polarity								0				// (1) for High when Idle, (0) for Low when Idle
#define		Clock_Phase									1				// (1) for Sample on Trailing Edge, (0) for Sample on Setup Edge

/* In Case of Master only */ 
#define		Clock_Rate									3				// From (0) to (6)


#endif
//****************************************************************************