/******************************************************************************
 * 
 * File: simpleLED.c
 * Author: Dustin Hodges (Motbots)
 * Microcontroller: PIC18F4525
 * Date: 06/01/2025
 * 
 * Project: A basic program to turn on and off an LED.
 * Hardware: We are using the microcontroller to switch an LED
 * ON and OFF. The following pins are used on the PIC18F4525:
 * 
 * RA0  --> "ON" Switch (SW1)
 * RA1  --> "OFF" Switch (SW2)
 * RB0  --> LED (LED1)
 *
 * Last Updated on June 1, 2025, 8:53 PM
 ******************************************************************************/

// PIC18F4525 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = INTIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (008000-00BFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (008000-00BFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void main(void) {
    
    // This is where the micro goes to find the first instruction of the program
    
    //////////////////////////////
    // MCU I/O initialization
    //////////////////////////////

    TRISA = 0xFF;       // Make all bits in TRISA a logic '1' which makes all bits on PORTA inputs 
    TRISB = 0x00;       // Make all bits in TRISB a logic '0' which makes all bits on PORTB outputs

    ADCON0 = 0x00;      // Makes all the bits in the ADCON0 logic '0'. This turns the ADC off
    ADCON1 = 0x0F;      // This makes bits 7, 6, 5, and 4 logic '0' and bits 3, 2, 1, and 0 logic '1'.
                        // This sets all the bits on PORTA and PORTB as digital bits (0b00001111)

    //////////////////////////////
    // Setting up the oscillator
    //////////////////////////////

    OSCCON = 0b01110100;    // This sets the internal oscillator to 8MHz and makes it stable
    
    // Test loop (forever loop) logic '1'. Micro will carry out the following instructions continuously)
    while(1) {
        
        Start: if(PORTAbits.RA0 == 1) goto On;  // If RA0 goes to logic '1' go to the label On
        if(PORTAbits.RA1 == 1) goto Off;        // If RA1 goes to logic '1' go to the label Off
        else goto Start;                        // If none of the switches are pressed go to the label Start
        
        On: PORTBbits.RB0 = 1;                  // Turn the LED on
        goto Start;                             // Go to the label Start
        
        Off: PORTBbits.RB0 = 0;                 // Turn the LED off
    }
}
