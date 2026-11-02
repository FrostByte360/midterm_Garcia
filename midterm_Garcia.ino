/*=============================================================
             7-SEGMENT IR DEMO with LOGICAL MODES
===============================================================
Description:
    This program demonstrates the detection of infrared sensor
    input signals, with an additional logical binary mode feature
    that allows the counter to increment or decrement depending
    on the logical binary being switched onto. The count value is
    then displayed on two 7-segment displays, representing ones
    and tens.
    
    
Programmer:
    Mark Garcia

Date:
    29 Oct 2026
*/

// GPIO Pins
const uint8_t IR_PIN = 36;

const uint8_t SW1 = 21;
const uint8_t SW2 = 22;
// Para sa switches

const uint8_t LED_1[] = {19, 18, 5, 17, 16, 4, 0};
const uint8_t NUM_ONES = sizeof(LED_1) / sizeof(LED_1[0]);

const uint8_t LED_2[] = {32, 33, 25, 26, 27, 14, 12};
const uint8_t NUM_TENS = sizeof(LED_2) / sizeof(LED_2[0]);

// Variables
int ir_counter = 0;
int ir_previousState = 1;

bool SW1_state = 0;
bool SW2_state = 0;
// Default switch values.

#include "decoder.h"

void setup() {
    pinMode(IR_PIN, INPUT);

    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);

    for (int i = 0; i < NUM_ONES; i++) {
        pinMode(LED_1[i], OUTPUT);
    }

    for (int i = 0; i < NUM_TENS; i++) {
        pinMode(LED_2[i], OUTPUT);
    }

    ir_previousState = digitalRead(IR_PIN);
    displayCounter(ir_counter);
}

void loop() {
    decoder(ir_previousState);
}
