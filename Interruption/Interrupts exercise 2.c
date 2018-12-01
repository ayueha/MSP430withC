#include <msp430.h>

// Define LED
#define LED1 BIT0

//Define switch S2
#define S2 BIT3

volatile unsigned long i;

/*
* main.c
*/
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
	
	P1DIR |= LED1; // LED1 as ouputs
	P1REN &= ~LED1; // Pullup/down resistors disabled for LED1
	
	P1DIR &= ~S2; // S2 as input
	P1OUT |= S2; // Pullup/down resistor configured as pullup on S2
	P1REN |= S2; // Pullup/down resistor enabled on S2
	P1IES |= S2; // Falling edge interrupt on S2
	P1IE |= S2; // Interrupt enable on S2
	P1IFG &= ~S2; // Clear interrupt flag on S2
	
	_BIS_SR(GIE); // General interrupt enable
	
	while(1)
	{
		// Do nothing
	}
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	switch(P1IFG)
	{
		case 8:  // 8 (00001000 in binary) in P1IFG means P1IFG.3 has been triggered
		         P1IFG &= ~S2; // Clear interrupt flag on S2
				 i = 150000;
				 while(i>0)
				 {
					 i--;
				 }
				 P1OUT ^= LED1; //Toggle LED1
				 break;
		default: // If something else than case 8 in P1IFG
		         P1IFG &= S2;
				 break;
	}
}
