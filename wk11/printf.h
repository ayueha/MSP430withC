/*
 *printf.h
 *Version: 1.0
 *Parker Dillmann
 *The Longhorn Engineer (c) 2013 
 *www.longhornengineer.com
 *
 *Check bottom of file for License.
 *
*/

/*
 *uart_printf(char*)
 *Converts and formats values to be sent via char UART. Works similar to normal printf function.
 *INPUT: Char* EX: uart_printf("DATA: %i\r\n", datvar);
 *RETURN: None
 */
void uart_printf(char *format, ...);