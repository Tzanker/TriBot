//
// Created by tevaz on 2022-07-10.
//

#ifndef TRIBOT_TRIBOT_H
#define TRIBOT_TRIBOT_H

#endif //TRIBOT_TRIBOT_H

#include <Arduino.h>
#include <Servo.h>

typedef struct Leg{

    Servo linear;
    Servo rotational;

    int linearPos = 90, rotationalPos =90,  linearPin,  rotationalPin;

    void setPins(int linPin, int rotPin){
        linearPin = linPin;
        rotationalPin = rotPin;
        linear.attach(linearPin);
        rotational.attach(rotationalPin);

    }

    void setPos(int lin, int rot){
        linearPos = lin;
        rotationalPos = rot;
        linear.write(lin);
        rotational.write(rot);
    }

    void moveToPos(int lin, int rot, int interPosDelay){
        int linDif = lin - linearPos;
        int rotDif = rot - rotationalPos;
        int maxDif = max(abs(linDif), abs(rotDif));
        float linInc = float (linDif) / float(maxDif);
        float rotInc = float (rotDif) / float(maxDif);
        float linCount = linearPos;
        float rotCount = rotationalPos;
        Serial.print(linDif);
        Serial.print(" ");
        Serial.print(rotDif);
        Serial.print(" ");
        Serial.print(maxDif);
        Serial.print(" ");
        Serial.print(linInc);
        Serial.print(" ");
        Serial.print(rotInc);
        Serial.print(" ");
        Serial.print(linCount);
        Serial.print(" ");
        Serial.println(rotCount);
        for(int i =0; i < maxDif; i++){
            linCount += linInc;
            rotCount += rotInc;
            setPos(linCount, rotCount);
            delay(interPosDelay);
        }


    }

} Leg;

class TriBot{
private:
    Leg leg1, leg2, leg3;
public:
    TriBot(Leg leg1, Leg leg2, Leg leg3);
    TriBot(){}
    void moveToState(int legLin1, int legRot1, int legLin2, int legRot2,int legLin3, int legRot3, int interPosDelay);
    void hopToLeg1();
    void hopToLeg2();
    void hopToLeg3();

};
