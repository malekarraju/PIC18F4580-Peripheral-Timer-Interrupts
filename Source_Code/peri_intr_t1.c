// TIMER1
#include <p18f4580.h>
#define Led PORTCbits.RC0

// Global variable 
	int count = 0;

void main(void)
{
	TRISCbits.RC0 = 0;  // direction output

	// Peripheral Interrupt Initialization
	RCONbits.IPEN = 0; // disable priority level on interrupt
	INTCONbits.GIE = 1; // all unmasked interrupt
	INTCONbits.PEIE = 1; // Peripheral interrupt enable bit
	PIE1bits.TMR1IE = 1; // Enables the TMR1 overflow interrupt 

	// Configure Timer1 Register
	T1CON = 0xF1;

	
	TMR0H = 0xB6;
	TMR0L = 0xC1;

	Led = 0;

	while(1)
	{
		if(count==10)  // run for 1 second 
		{
			Led = ~Led;
			count=0;	
		}
	}
}

#pragma code T1_Intr = 0x08 // 0x08 High priority , 0x18 low priority
#pragma interrupt T1_Intr

void T1_Intr(void)
{
	TMR0H = 0xB6;
	TMR0L = 0xC1;

		count++;

 PIR1bits.TMR1IF = 0; //clear T1 interrupt flag
}
