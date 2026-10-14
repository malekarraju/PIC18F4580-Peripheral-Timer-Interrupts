#include<p18f4580.h>
#define Led PORTCbits.RC1

void main()
{
	TRISCbits.RC1 = 0;

 //Interrupt
	RCONbits.IPEN = 0;   	  // Interrupt Level off
	INTCONbits.GIE = 1;		  // Global Interrupt
	INTCONbits.PEIE = 1;	  // Enable Peripheral Interrupt
	PIE2bits.TMR3IE = 1;	  // Timer0 Intr enable
	
// Timer Initialization
	T3CON = 0xF1; // 11110001

	TMR3H = 0X85;
	TMR3L = 0XED;

	Led = 0;

	while(1)
	{
	}
}

#pragma code T3_Intr = 0x08 					
#pragma interrupt T3_Intr

void T3_Intr(void)
{
	TMR3H = 0X85;
	TMR3L = 0XED;

	Led = ~Led; //Toggle Led

	PIR2bits.TMR3IF = 0; //CLEAR THE FLAG BIT
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