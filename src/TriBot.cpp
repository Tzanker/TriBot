//
// Created by tevaz on 2022-07-10.
//

#include "TriBot.h"
#include <Arduino.h>
#include <Servo.h>
TriBot::TriBot(Leg leg1,Leg leg2,Leg leg3){
    this->leg1 = leg1;
    this->leg2 = leg2;
    this->leg3 = leg3;
}


void TriBot::moveToState(int legLin1, int legRot1, int legLin2, int legRot2,int legLin3, int legRot3, int interPosDelay){
    int linDif1 = legLin1 - leg1.linearPos;
    int rotDif1 = legRot1 - leg1.rotationalPos;
    int linDif2 = legLin2 - leg2.linearPos;
    int rotDif2 = legRot2 - leg2.rotationalPos;
    int linDif3 = legLin3 - leg3.linearPos;
    int rotDif3 = legRot3 - leg3.rotationalPos;
    int maxDif = max(max(abs(linDif1), abs(rotDif1)), max(max(abs(linDif2), abs(rotDif2)), max( abs(linDif3), abs(rotDif3))));
    float linInc1 = float (linDif1) / float(maxDif);
    float rotInc1 = float (rotDif1) / float(maxDif);
    float linInc2 = float (linDif2) / float(maxDif);
    float rotInc2 =  float (rotDif2) / float(maxDif);
    float linInc3 = float (linDif3) / float(maxDif);
    float rotInc3 = float (rotDif3) / float(maxDif);
    float linCount1 = leg1.linearPos;
    float rotCount1 = leg1.rotationalPos;
    float linCount2 = leg2.linearPos;
    float rotCount2 = leg2.rotationalPos;
    float linCount3 = leg3.linearPos;
    float rotCount3 = leg3.rotationalPos;
    for(int i =0; i < maxDif; i++){
        linCount1 += linInc1;
        rotCount1 += rotInc1;
        leg1.setPos(linCount1, rotCount1);
        linCount2 += linInc2;
        rotCount2 += rotInc2;
        leg2.setPos(linCount2, rotCount2);
        linCount3 += linInc3;
        rotCount3 += rotInc3;
        leg3.setPos(linCount3, rotCount3);
        delay(interPosDelay);
    }

}

void TriBot::hopToLeg1(){
    moveToState( 0,90 ,0 ,90+45,0, 90-45,  15); // Hop Towards leg 1
    moveToState(50,90 ,100 ,90-45,100, 90 + 45, 1);
}
void TriBot::hopToLeg2(){
    moveToState(0, 90-45, 0,90 , 0 ,90+45, 15); // Hop towards leg 2
    moveToState(100, 90 + 45, 50,90 , 100 ,90-45, 1);
}
void TriBot::hopToLeg3(){
    moveToState(0 ,90+45,0, 90-45, 0,90 ,  15); // Hop Towards leg 3
    moveToState(100 ,90-45,100, 90 + 45, 50,90 ,  1);
}
