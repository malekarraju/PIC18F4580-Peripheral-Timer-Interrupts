#include <p18f4580.h>
#define Led PORTCbits.RC2

void main(void)
{
	TRISCbits.RC2 = 0; // port direction

	// Peripheral Interrupt (TIMER2)
	RCONbits.IPEN = 0; // disable interrupt level
	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 1;
	// Enable TIMER2 interrupt 
	PIE1bits.TMR2IE = 1;
	// COng TIMER2
	T2CON = 0x0E; // T2 on, Prescale 1:16, Potscale 1:2
	// Load preload value to PR2 register 
	PR2 = 0x9C;
	
	Led = 0;
	while(1)
	{
	}
}

#pragma code T2_Intr = 0x08
#pragma interrupt T2_Intr

void T2_Intr(void)
{
	PR2 = 0x9C; // again load
	 Led = ~Led; // led toggle
	PIR1bits.TMR2IF = 0; // clear intrrupt flag bit
}