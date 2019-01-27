/* 
 * File:   Timer.c
 * Author: IBRAHIM LABS
 *
 * Website: http://ibrahimlabs.blogspot.com/
 *
 * Created on September 22, 2013, 7:42 AM
 */
#include <p32xxxx.h>

void InitializeTimer( void )
{

    T4CON = 0x0;            //Stop and Init Timer
    T4CON = 0x0060;         //prescaler=1:64,
                            //internal clock
    TMR4 = 0;               //Clear timer register
    PR4 = 0x7FFF;           //Load period register

    IPC4SET = 0x00000004;   // Set priority level=1 and
    IPC4SET = 0x00000001;   // Set subpriority level=1

    IFS0bits.T4IF = 0;
    IEC0bits.T4IE = 1;

    T4CONSET = 0x8000;      //Start Timer

    return;
}
