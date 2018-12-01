#include "msp430.h"
//#include "msp430g2553.h"
#define LED_PDIR P1DIR
#define LED_POUT P1OUT
#define LED_PIN BIT0
volatile unsigned long i;

/**
 * main.c
 */

void blinkInterrupt() {

        LED_PDIR |= LED_PIN;   // PIDIR   register  init by LED PIN as OR operator -->  bit 00000001
        LED_POUT &= ~LED_PIN;  // LEDOUT  register  init by LED PIN as NAND operator -->bit 00000000

        //ConfigTimerA(10000);  //Call function as freence value 10000


        while (1) { _bis_SR_register(LPM0_bits + GIE); }   //--- delay timer version





        //Low power mode 0
        //_bis_SR_register(unsigned short mask) is an instrinsic which maps to the assembly instruction: BIS mask, SR
        //CALL Global functions
}







void ConfigTimerA(unsigned int delayCycles) {
    TACCTL0 |= CCIE;          //Timer_A capture/compare control 0 init by register CCIE bit4 as interruption is disabled
                                  //CCIE Bit 4 Capture/compare interrupt enable.
                                  //This bit enables the interrupt request of the corresponding CCIFG flag. 0
                                  //Interrupt disabled 1 Interrupt enabled
    TACCR0 = delayCycles;     //set a timer

    TACTL |= TASSEL_1;        //Timer_A control
                                  //TASSELx Bits 9-8 Timer_A clock source select 00 TACLK 01
                                  //ACLK 10 SMCLK 11 INCLK (INCLK is device-specific and is often assigned to the inverted TBCLK) (see the devicespecific data sheet)
                                  // this case ACLK 01?
    BCSCTL3 |= LFXT1S1 ;      //Basic Clock control register No3 as OR operator
                                  //Low-frequency clock select and LFXT1 range select. These bits select between LFXT1 and VLO when XTS = 0, and select the frequency range for LFXT1 when XTS = 1.
                                  //LFXT1Sx definition for MSP430AFE2xx devices: 00 Reserved 01 Reserved 10 VLOCLK 11 Reserved
    BCSCTL1 |=DIVA_3 ;        //BCSCTL1, Basic Clock System Control Register 1 initalized by  as OR operator
                              //DIVAx Bits 5-4 Divider for ACLK 00 /1 01 /2 10 /4 11 /8
    TACTL |= MC_1;            //01 Up mode: the timer counts up to TACCR0
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0(void) {

    //use delay_cycles
    /*while(1)
    {
        LED_POUT ^= LED_PIN;        //turn on
        __delay_cycles (100);     //Wait for next blinking  use delay cycles
        LED_POUT &= ~LED_PIN;
    }
    */
    //use while looping
    unsigned int i;
    while(1){
        for ( i= 0; i <=1500; i++){
            if (i==1500){
                LED_POUT ^= LED_PIN;
                while(i>=0){
                    if (i==0){
                        LED_POUT &= ~LED_PIN;
                    }
                    i--;
                }
            }
        }
    }


}

void main(void) { blinkInterrupt(); }
