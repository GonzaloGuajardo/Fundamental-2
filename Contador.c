/*************************************************************************
* Gonzalo Alberto Guajardo Galindo *
* 
* Device: Atmega328P *
* Rev: 1 *
* Purpose of the activity: *
* Use the microcontroller ports with a 7-segment display
* Date: 15/09/22 *
************************************************************************/
// LIBRARIES
#include <avr/io.h>
#include <util/delay.h>
#include <cstdint>
#define F_CPU 1600000UL

// CONSTANTS
#define DELAY _delay_ms(500)

// MACROS
#define _BV(bit) (1 << (bit))

// INPUTS
#define Btns PINC
#define Btn1 PINC2
#define Btn1_press bit_is_set(PINC,Btn1)
#define Btn2 PINC3
#define Btn2_press bit_is_set(PINC,Btn2)

// OUTPUTS
#define Seg_A PORTB3
#define Seg_A_On PORTB &= ~_BV(Seg_A)
#define Seg_A_Off PORTB |= _BV(Seg_A)
#define Seg_B PORTB4
#define Seg_B_On PORTB &= ~_BV(Seg_B)
#define Seg_B_Off PORTB |= _BV(Seg_B)
#define Seg_C PORTD6
#define Seg_C_On PORTD &= ~_BV(Seg_C)
#define Seg_C_Off PORTD |= _BV(Seg_C)
#define Seg_D PORTD7
#define Seg_D_On PORTD &= ~_BV(Seg_D)
#define Seg_D_Off PORTD |= _BV(Seg_D)
#define Seg_E PORTB0
#define Seg_E_On PORTB &= ~_BV(Seg_E)
#define Seg_E_Off PORTB |= _BV(Seg_E)
#define Seg_F PORTB2
#define Seg_F_On PORTB &= ~_BV(Seg_F)
#define Seg_F_Off PORTB |= _BV(Seg_F)
#define Seg_G PORTB1
#define Seg_G_On PORTB &= ~_BV(Seg_G)
#define Seg_G_Off PORTB |= _BV(Seg_G)
#define Seg_DP PORTD5
#define Seg_DP_On PORTD &= ~_BV(Seg_DP)
#define Seg_DP_Off PORTD |= _BV(Seg_DP)

// ARRAY
uint8_t Numeros [16]={
0x3,    // 0
0x9F,   // 1
0x25,   // 2
0xD,    // 3
0x99,   // 4
0x49,   // 5
0x41,   // 6
0x1F,   // 7
0x1,    // 8
0x19,   // 9
0x11,   // A
0xC1,   // B
0x63,   // C
0x85,   // D
0x61,   // E
0x71    // F
};

// FUNCTIONS
void init_port (void);
void muestra_num (uint8_t x);
int main(void)
{
    init_port ();
    uint8_t x = 0;
    while (1)
    {
        while (x <= 16)
        {
            if (!Btn1_press && !Btn2_press)
            {
                muestra_num(0);
                DELAY;
            }
            else if(!Btn1_press && Btn2_press)
            {
                x++;
                muestra_num(x);
                DELAY;
            }
            else if (Btn1_press && !Btn2_press)
            {
                x--;
                muestra_num(x);
                DELAY;
            }
            else
            {
                x = x;
                muestra_num(x);
                DELAY;
            }
        }
    }
}

void init_port (void)
{
    // INPUTS
    DDRC &= ~_BV(Btn1);
    DDRC &= ~_BV(Btn2);

    // OUTPUTS
    DDRB |= (_BV(Seg_A) | _BV(Seg_B) | _BV(Seg_E) | _BV(Seg_F) | _BV(Seg_G));
    DDRD |= (_BV(Seg_C) | _BV(Seg_D) | _BV(Seg_DP));
}

void muestra_num (uint8_t salida)
{
    switch(salida)
    {
        case 0: // 0
        Seg_A_On;
        Seg_B_On;
        Seg_C_On;
        Seg_D_On;
        Seg_E_On;
        Seg_F_On;
        Seg_G_Off;
        Seg_DP_Off;
        break;
        case 1: // 1
        Seg_A_Off;
        Seg_B_On;
        Seg_C_On;
        Seg_D_Off;
        Seg_E_Off;
        Seg_F_Off;
        Seg_G_Off;
        Seg_DP_Off;
        break;
        case 2: // 2
        Seg_A_On;
        Seg_B_On;
        Seg_C_Off;
        Seg_D_On;
        Seg_E_On;
        Seg_F_Off;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 3: // 3
        Seg_A_On;
        Seg_B_On;
        Seg_C_On;
        Seg_D_On;
        Seg_E_Off;
        Seg_F_Off;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 4: // 4
        Seg_A_Off;
        Seg_B_On;
        Seg_C_On;
        Seg_D_Off;
        Seg_E_Off;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 5: // 5
        Seg_A_On;
        Seg_B_Off;
        Seg_C_On;
        Seg_D_On;
        Seg_E_Off;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 6: // 6
        Seg_A_On;
        Seg_B_Off;
        Seg_C_On;
        Seg_D_On;
        Seg_E_On;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 7: // 7
        Seg_A_On;
        Seg_B_On;
        Seg_C_On;
        Seg_D_Off;
        Seg_E_Off;
        Seg_F_Off;
        Seg_G_Off;
        Seg_DP_Off;
        break;
        case 8: // 8
        Seg_A_On;
        Seg_B_On;
        Seg_C_On;
        Seg_D_On;
        Seg_E_On;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 9: // 9
        Seg_A_On;
        Seg_B_On;
        Seg_C_On;
        Seg_D_Off;
        Seg_E_Off;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 10: // A
        Seg_A_On;
        Seg_B_On;
        Seg_C_On;
        Seg_D_Off;
        Seg_E_On;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 11: // B
        Seg_A_Off;
        Seg_B_Off;
        Seg_C_On;
        Seg_D_On;
        Seg_E_On;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 12: // C
        Seg_A_On;
        Seg_B_Off;
        Seg_C_Off;
        Seg_D_On;
        Seg_E_On;
        Seg_F_On;
        Seg_G_Off;
        Seg_DP_Off;
        break;
        case 13: // D
        Seg_A_Off;
        Seg_B_On;
        Seg_C_On;
        Seg_D_On;
        Seg_E_On;
        Seg_F_Off;
        Seg_G_On;
        Seg_DP_Off;
        break;
        case 14: // E
        Seg_A_On;
        Seg_B_Off;
        Seg_C_Off;
        Seg_D_On;
        Seg_E_On;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break; ;
        case 15: // F
        Seg_A_On;
        Seg_B_Off;
        Seg_C_Off;
        Seg_D_Off;
        Seg_E_On;
        Seg_F_On;
        Seg_G_On;
        Seg_DP_Off;
        break;
    }
}