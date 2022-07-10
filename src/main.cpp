//
// Created by tevaz on 2022-07-10.
//
#include <Arduino.h>
#include "TriBot.h"


int tick = 0;    // variable to store the servo position
bool dir = true;








Leg leg1, leg2, leg3;
TriBot bot;

void setup() {
    leg1.setPins(8,9);
    leg2.setPins(10,11);
    leg3.setPins(12,13);

    bot = TriBot(leg1, leg2, leg3);
    Serial.begin(9600);
}


void loop() {


    bot.hopToLeg1();


}