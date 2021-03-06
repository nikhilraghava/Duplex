//
//  test.c
//
//  Created by Nikhil Raghavendra and Ong Jun Wen on 22/6/18.
//  Copyright � 2018 Nikhil Raghavendra and Ong Jun Wen. All rights reserved.
///
#include <xc.h>
#include <stdio.h>
#include "amt.h"
#include "LCDUI.h"

#pragma config XINST = OFF
#pragma config FOSC = HS
#pragma config WDT = OFF


void interrupt HighIsr(void) // High priority interrupt
{

}

void interrupt low_priority LowIsr(void) //Low priority interrupt
{
    
}

void main(void) {
    // Initialize LCD panel
    initLCDUI();
    // Move cursor to row 1, col 1
    moveCursorTo(1, 1);
    // Display text
    displayAlphaNumeric("Hello!");
    // Delay for 2 seconds
    delay_ms(2000);
    // Move cursor to row 2, col 1
    clearDisplayAndCursorTo(2, 1);
    // Display the first custom graphic icon - delicate wash
    for (int i = 0; i < 4; i++) {
        customGraphics(i);
        delay_ms(1000);
    }
    // Short delay
    delay_ms(2000);
    // Clear display
    clearDisplay();
    // Cursor to row 1, col 1
    moveCursorTo(1, 1);
    // Display bye message
    displayAlphaNumeric("Bye!");
    while(1);
}