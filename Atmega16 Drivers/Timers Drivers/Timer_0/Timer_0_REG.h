//****************************************************************************
 #ifndef	TIMER_0_REG_H_
 #define	TIMER_0_REG_H_
 
 
 
//	Timer_0 Registers
#ifndef	SFIOR
#define SFIOR						(*((volatile u8*)(0x50)))
#endif


#ifndef	OCR0
#define OCR0						(*((volatile u8*)(0x5C)))
#endif


#ifndef	TCNT0
#define TCNT0						(*((volatile u8*)(0x52)))
#endif

#ifndef	TCCR0
#define TCCR0						(*((volatile u8*)(0x53)))
#endif

#ifndef	TIFR
#define TIFR						(*((volatile u8*)(0x58)))
#endif

#ifndef	TIMSK
#define TIMSK						(*((volatile u8*)(0x59)))
#endif



//	Timer_0 Registers Bits
//  TCCR0 Register
#define			CS00								0
#define			CS01								1
#define			CS02								2
#define			WGM01								3
#define			COM00								4
#define			COM01								5
#define			WGM00								6
#define			FOC0								7


//  TIMSK Register
#define			TOIE0								0
#define			OCIE0								1


//  SFIOR Register
#define			PSR10								0

 
#endif
//****************************************************************************