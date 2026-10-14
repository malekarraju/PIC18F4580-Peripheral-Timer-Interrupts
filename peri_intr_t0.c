#include<p18f4580.h>
#define Led PORTCbits.RC3

// Global variable 
	unsigned int Preload;
	unsigned int Tdesired = 100; // enter desired time for half cycle in milli second 

void main()
{
	TRISCbits.RC3 = 0;

 //Interrupt
	RCONbits.IPEN = 0;   	  // Interrupt Level off
	INTCONbits.GIE = 1;		  // Global Interrupt
	INTCONbits.PEIE = 1;	  // Enable Peripheral Interrupt
	INTCONbits.TMR0IE = 1;	  // Timer0 Intr enable

 //2nd option
	// INTCON = 0xE0;
	
// Timer Initialization
	T0CON = 0x87;


	Preload = 65535 - (Tdesired/0.256);

	TMR0H = Preload >> 8 ;
	TMR0L = Preload;

	Led = 0;

	while(1)
	{
	}
}

#pragma code T0_Intr = 0x08 					
#pragma interrupt T0_Intr

void T0_Intr(void)
{
	TMR0H = Preload >> 8 ;
	TMR0L = Preload;

	Led = ~Led;

	INTCONbits.TMR0IF = 0;//CLEAR THE FLAG BIT
}


/*
	- Main program is running also timer0 countuing 
	- when timer0 reach to count limit timer0 intrrupt flag set
	- Interrupt condition match 
	- then controller halt the main program go to ISR function 
	- perform ISR funtcion and come back to main program where it left
	- then Timer interrupt flag clear , counting restart from zero again
	- again main program run upto timer0 counting reach to last limit (according to programmer time delay set)
*/

/*
### Working of Timer0 Interrupt in PIC18F4580

1. The main program executes while Timer0 counts simultaneously in the background.

2. When Timer0 reaches its maximum count (`0xFFFF`) and overflows, the hardware sets the Timer0 interrupt flag (`TMR0IF = 1`).

3. The controller checks the interrupt conditions: the Timer0 interrupt must be enabled (`TMR0IE = 1`) and global interrupts must be enabled (`GIE = 1`).

4. When the interrupt is accepted, the controller temporarily suspends the main program and jumps to the Interrupt Service Routine (ISR).

5. The ISR executes the required operations, such as reloading Timer0, toggling an LED, and clearing the Timer0 interrupt flag (`TMR0IF = 0`).

6. After the ISR completes, the controller returns to the point where the main program was interrupted and continues execution.

7. Timer0 continues counting. If the ISR reloads Timer0 with a predefined value, counting continues from that value rather than necessarily from zero.

8. This process repeats whenever Timer0 overflows and the interrupt conditions are satisfied.
*/