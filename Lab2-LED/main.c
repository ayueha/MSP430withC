#include "msp430.h"
//#include "msp430g2553.h"
//#include <stdio.h>
//#include <msp430.h>
/*definitions */
//#define LED_TOGGLE_CNT 0x7FFF // loop count of cnt
//#define LED_TOGGLE_CNT 0xC416 // Change duration of blink
//#define LED_TOGGLE_CNT 0x7FFF // Change duration of blink
//#define LED_TOGGLE_CNT_W 0xC416 // Change duration of blink

/*pinout */
//#define LED1 BIT0   /*LED pin No1*/
#define LED_RED BIT0   /*LED pin No1    bitwise 0000001*/
#define LED_GREEN BIT6   /*LED pin No1  bitwise 0100000*/
#define S2 BIT3
#define LEDs LED_RED+ LED_GREEN /* LEDs bitwise is 0100001*/

//unsigned long cnt;
volatile unsigned long i;
/**
 * main.c (Main loop)
 */
void main(void)
{
    //unsigned int cnt; //program counter


    //init system
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    P1REN &= ~LED_RED;
    P1DIR |= LED_RED;

    P1DIR &= ~S2;
    P1REN = P1REN |S2;
    P1OUT = P1OUT|S2;
	
    P1IFG &= ~S2;               //interruption Flag is default 0
    P1IES = P1IES |S2;          //
    P1IE = P1IE | S2;           //interruption

    _BIS_SR(GIE);                //Global function of intrruption  -- Enable
    __bis_SR_register(LPM2_bits + GIE);


    while(1)
     {
        // Main Looping process (the case of interruption no need to declare )
    }




    //configure LED1 as a digital output
    //P1REN &= ~LED1;          // P1REN :Port P1 resistor enable P1REN 027h (027h is memory address)
    //P1DIR |= LED1;           // P1DIR :Port P1 direction P1DIR 022h (022h is memory address) original codes
    //Port P1 output P1OUT 021h
    //When voltage on, initial  settings decide baseis of signals.
    //P1DIR = P1DIR | LED1_RED;  // Address P1DIR :Port P1 direction P1DIR 022h (022h is memory address) original codes //schematic decide it (several documentation shows)
    //P1REN &= ~LED1_RED;        // A; ddress code P1REN :Port P1 resistor enable P1REN 027h (027h is memory address)

    //P1DIR = P1DIR | LEDs;  // Address P1DIR :Port P1 direction P1DIR 022h (022h is memory address) original codes //schematic decide it (several documentation shows)
    //P1REN &= ~LEDs;        // Address code P1REN :Port P1 resistor enable P1REN 027h (027h is memory address)

    //P1DIR = P1DIR | LED_RED;
    //P1REN &=LED_RED;

    //P1DIR = P1DIR |LED_GREEN;
    //P1REN &=LED_GREEN;

    //P1DIR &= ~S2;          //
    //P1REN = P1REN |S2;     //


    //P2REN &= ~LED2_White;
    //P2DIR = P1DIR | LED2_White;

    //try interruption
    //set interruption Flag and init signals;

    //P1IE =
    //Enable interruption ;
    //set interruption Flag and init signals;
    //P1IFG =

    //test intrruption
    //confgure LED green
    //P1DIR = P1DIR |LEDs;   //direction both LEDs blink
    //P1REN &= ~LEDs;        //initial register disabled  (turn off)

    //P1DIR = P1DIR | LED_GREEN; //define direction port  NO1
    //P1REN &= ~LED_GREEN;       //initial register disables (turn off) port  NO1

    //configure S2 switch  ---- interruption programs-------- just portt1
    //P1DIR &= ~S2;               //S2 is initially disabled
    //P1REN = P1REN |S2;          //initial register enabled
    //P1OUT = P1OUT |S2;          //Output register enable
    //P1IFG &= ~S2;               //interruption Flag is default 0
    //P1IES = P1IES |S2;          //
    //P1IE = P1IE | S2;           //interruption

    //configure port NO2   ---- interruption programs --------- connection between port2------
    //P2DIR &=~BIT3;              //init port 2 direction as bit 00001000(same as S2) -->disabled
    //P2REN = P2REN |BIT3;        //register enable as bit 00001000( same as S2)
    //P2OUT = P1OUT |BIT3;        //output direction bit 00001000(same as S2)
    //P2IFG &= ~BIT3;             //interruption flg set bit 00001000(same as S2)  -->disabled
    //P2IES = P1IES |BIT3;        //
    //P2IE = P1IE | BIT3;         //



    //_BIS_SR(GIE);                //Global function of intrruption  -- Enable


    //while(1)
    // {
        // Main Looping process (the case of interruption no need to declare )
    //}
        //During interruption do nothing

        /*
        if ((P1IN & S2) == 0){
        //interruption flag catch
            P1OUT &=~LED_RED;
            P1OUT |=LED_GREEN;
        }else{
            //if (cnt++ == LED_TOGGLE_CNT){
                   //cnt =0;
            //P1OUT &=~LEDs;
            P1OUT |=LED_RED;
            P1OUT &=~LED_GREEN;
        */
        //}
            /*
       if (cnt++ == LED_TOGGLE_CNT_W){
            cnt =0;
           P2OUT ^=LED2_White;
        }
        */


    //}

    //------ array practie --------//
    //unsigned int j =0 ;
    //unsigned int l =0 ;

    //int arr[9] = {1,3,5,7,9,11,13,15,17,19};
    /*int arrNoTwo[9];
    int arrNoThree[9];

    while(j<10){
        arrNoTwo[j] = arr[j];
        arrNoThree[j] = arrNoTwo[j]+arr[j];
        j++;
    }
    */
    // --------two dimensions -------///

/*
    int twoDemensionsA[2][4] = {
         {1,2,3,4} ,
         {5,6,7,8}
    };

    int twoDemensionsB[2][4] = {
             {1,2,3,4} ,
             {5,6,7,8}
        };

    int towDemensionsC[2][4];

    while (j<3){
        while (l<5){
            towDemensionsC[j][l] = twoDemensionsA[j][l]+twoDemensionsB[j][l];
            l++;
        }
        l=0;
        j++;
    }

*/



    /*for ( j = 0; j < 9; j ++){
         //printf arr[j];
        arrNoTwo[j] = arr[j];
        arrNoThree[j] = arrNoTwo[j]+arrNoThree[j];
    }*/


} //end of main


   //----interruption
#pragma vector=PORT1_VECTOR  //Issues special commands to the compiler, using a standarized method
__interrupt void Port_1(void){ //enable interruption to port 1
    switch(P1IFG){
           case 8: //PIDIR binary is (000001000) -->2^3
               P1IFG &= ~S2;
               i = 150000;
                   while(i>0)
                       {
                           i--;  // Sleep the light while i>0 if i==0, omit the light
                       }
               P1OUT ^= LED_RED; // omit the light of LED
               break;
               default: //Disable S2
                   P1IFG &= S2;
               break;
     }
}

   /*
#pragma vector=PORT2_VECTOR //Issues special commands to the compiler, using a standarized method
__interrupt void Port_2(void){ //enable interruption to port 2
    switch(P2IFG){
           case 8: //PIDIR binary is (000001000) -->2^3
               P2IFG &= ~BIT3;
               P1OUT ^= LED_GREEN;
               break;
               default: //disable P2FLG
                   P2IFG &= BIT3;
               break;
     }
}
*/
