
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 6000000
unsigned char val;

void main()
{
    TRISC=0x5F; //0011 1111
    TRISB=0xF0; //1111 0000
    PORTB=0xF0; //1111 0000
    PORTC=0x00; //0000 0000
    while(1)
    {
        val=PORTB;
        switch(val)
        {
            case 0xE0:
                PORTC=0x20;  // 0010 0000
                break;
            case 0xD0:
                PORTC=0x80; // 1000 0000
                break;
            case 0xB0:
                PORTC=0xA0; // 1001 0000
                break;
            case 0x70:
                PORTC=0x00; // 0000 0000
                break;
        }
        
    }
}