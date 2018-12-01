#include <msp430.h>

// Define LEDs
#define LED1 BIT0
#define LED2 BIT6
#define LEDs LED1+LED2

//Define Switch S2
#define S2 BIT3

volatile unsigned long i;

/*
* main.c
*/
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
	
	P1DIR |= LEDs; // LEDs as ouputs
	P1REN &= ~LEDs; // Pullup/down resistors disabled for LEDs
	
	P1DIR &= ~S2; // S2 as input
	P1OUT |= S2; // Pullup/down resistor configured as pullup on S2
	P1REN |= S2; // Pullup/down resistor enabled on S2
	P1IES |= S2; // Falling edge interrupt on S2
	P1IE |= S2; // Interrupt enable on S2
	P1IFG &= ~S2; // Clear interrupt flag on S2
	
	P2DIR &= ~BIT3; // P2.3 as input
	P2OUT |= BIT3; // Pullup/down resistor configured as pullup on P2.3
	P2REN |= BIT3; // Pullup/down resistor enabled on P2.3
	P2IES |= BIT3; // Falling edge interrupt on P2.3
	P2IE |= BIT3; //Interrupt enable on S2
	P2IFG &= ~BIT3; // Clear interrupt flag on P2.3
	
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
		         P1IFG &= ~S2;  // Clear interrupt flag on S2
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

// Port 2 interrupt service routine
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
	switch(P2IFG)
	{
		case 8:  //8 (00001000 in binary) in P2IFG means P2IFG.3 has been triggered
		         P2IFG &= ~BIT3; // clear interrupt flag on P2.3
				 P1OUT ^= LED2; // Toggle LED2
				 break;
		default: // If something else than case 8 in P2IFG
		         P2IFG &= BIT3;
				 break;
	}
}
