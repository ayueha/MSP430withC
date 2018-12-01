/*
 *main.c
 *Version: 1.0
 *Parker Dillmann
 *The Longhorn Engineer (c) 2013 
 *www.longhornengineer.com
 *
 *Check bottom of file for License.
 *
 *Test main.c for printf.
 *
*/

#include <msp430g2553.h>
#include "uart_fifo.h"					//Your UART header
#include "printf.h"


int main(void)
{
	WDTCTL = WDTPW + WDTHOLD; 			//Stop WDT
	BCSCTL1 = CALBC1_8MHZ; 				//Set DCO to 8Mhz
	DCOCTL = CALDCO_8MHZ; 				//Set DCO to 8Mhz

	__enable_interrupt();				//Interrupts Enabled

	uart_init();

	signed int si = -314;
	unsigned int ui = 150;
	signed long sl = -456310;
	unsigned long ul = 325650;

	uart_printf("Testing the printf Function!\r\n");
	uart_printf("signed int %i\r\n", si);
	uart_printf("unsigned int %u\r\n", ui);
	uart_printf("signed long %l\r\n", sl);
	uart_printf("unsigned long %n\r\n", ul);
	uart_printf("HEX %x\r\n", ui);
	uart_printf("Types Done!\r\n");

	while(1){
        char letters[10];
        uart_gets(&letters,10);
        uart_printf("Result of Inputs: %s \r\n",letters);

	}
}
