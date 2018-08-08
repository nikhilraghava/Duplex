//
//  LCDUI.c
//
//  Created by Nikhil Raghavendra and Ong Jun Wen on 22/6/18.
//  Copyright � 2018 Nikhil Raghavendra and Ong Jun Wen. All rights reserved.
//
#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "amt.h"

// Cursor location
int cursorLocation = 0x00;

void initLCDUI() {
    // Initialize LCD panel
    LCD8init();
    // Clear display and cursor home
    LCD8send(0x01, 0);
}

void clearDisplay() {
    // Clear display and cursor home
    LCD8send(0x01, 0);
}

void moveCursorTo(int row, int col) {
    // Compute cursor location based on row and col
    // Defaults to first row given any number expect two 
    cursorLocation = ((row == 2) ? 0xBF + col : 0x7F + col);
    // Move cursor to specified location
    LCD8send(cursorLocation, 0);
}

void clearDisplayAndCursorTo(int row, int col) {
    // Clear the display
    clearDisplay();
    // Move cursor to specified location
    moveCursorTo(row, col);
}

void displayAlphaNumeric(char *message) {
    // Initialize buffers
    char buffer[16];
    // Format the alphanumeric message into string
    sprintf(buffer, message);
    // Move the cursor to the cursor location specified previously
    LCD8send(cursorLocation, 0);
    // Write data from buffer to LCD display
    for (int i=0; buffer[i] != 0; i++) LCD8send(buffer[i], 1);
}

void customGraphics(int selectedGraphic) {
    // 0 - delicate wash
    // 1 - heavy duty wash
    // 2 - tumble dry
    // 3 - spin dry
    LCD8send(0x00+selectedGraphic, 1);
}
