#include "stepper_interface.h"
#include "AccelStepper.h"
#include "defines.h"
AccelStepper stepperR(AccelStepper::DRIVER, STEPPER_RIGHT_STEP_PIN, STEPPER_RIGHT_DIR_PIN);
AccelStepper stepperL(AccelStepper::DRIVER, STEPPER_LEFT_STEP_PIN, STEPPER_LEFT_DIR_PIN);
void initSteppers(void){
    
    stepperR.setMinPulseWidth(0);
    stepperL.setMinPulseWidth(0);
    
    //enable steppers
    pinMode(PORTD+11, OUTPUT);
    digitalWrite(PORTD+11, HIGH);
    
    setSteppingMode(MICROSTEPS_8);

    pinMode(STEPPER_RIGHT_DIR_PIN, OUTPUT);
    pinMode(STEPPER_RIGHT_STEP_PIN, OUTPUT);
    pinMode(STEPPER_LEFT_DIR_PIN, OUTPUT);
    pinMode(STEPPER_LEFT_STEP_PIN, OUTPUT);
    pinMode(PORTD+15, OUTPUT);
    
    pinMode(PORTE+9, OUTPUT);
    setStepperMaxSpeed(MAXSPEED);
    setStepperAccel(MAXACCEL);
    
    
    pinMode(PORTD+12, OUTPUT);//led
    

    
}
void stepperMove(int16_t offset){
    stepperR.move(offset);
    stepperL.move(offset);
    
}
void stepperRun(void){
    stepperR.run();
    stepperL.run();
}
int32_t stepperCurrentPosition(void){
    return stepperL.currentPosition();
    
}
void stepperMoveTo(int16_t position){
        stepperR.moveTo(position);
        stepperL.moveTo(position);
}
void setStepperMaxSpeed(uint16_t maxSpeed){
        stepperR.setMaxSpeed(maxSpeed);
        stepperL.setMaxSpeed(maxSpeed);
}
void setStepperCurrentPosition(uint16_t position){
        stepperR.setCurrentPosition(position);
        stepperL.setCurrentPosition(position);
}

void setStepperAccel(uint16_t accel){
        stepperR.setAcceleration(accel);
        stepperL.setAcceleration(accel);
}
void setStepperSpeed(float speed){
        stepperR.setSpeed(speed);
        stepperL.setSpeed(speed);
}
void dWrite(uint8_t pin, uint8_t mode){
        digitalWrite(pin, mode);
}

void runSpeed(){
        stepperR.runSpeed();
        stepperL.runSpeed();
}

void setSteppingMode(uint8_t mode){
    
    pinMode(STEPPER_RIGHT_M0_PIN, OUTPUT);
    pinMode(STEPPER_RIGHT_M1_PIN, OUTPUT);
    pinMode(STEPPER_LEFT_M0_PIN, OUTPUT);
    pinMode(STEPPER_LEFT_M1_PIN, OUTPUT);
    
    
    digitalWrite(STEPPER_RIGHT_M0_PIN, LOW);
    digitalWrite(STEPPER_RIGHT_M1_PIN, LOW);
    digitalWrite(STEPPER_LEFT_M0_PIN, LOW);
    digitalWrite(STEPPER_LEFT_M1_PIN, LOW);
    
    switch(mode)
        {
        case MICROSTEPS_1: 
            digitalWrite(STEPPER_RIGHT_M0_PIN, LOW);
            digitalWrite(STEPPER_RIGHT_M1_PIN, LOW);
            digitalWrite(STEPPER_LEFT_M0_PIN, LOW);
            digitalWrite(STEPPER_LEFT_M1_PIN, LOW);
        break;
        case MICROSTEPS_2: 
            digitalWrite(STEPPER_RIGHT_M0_PIN, HIGH);
            digitalWrite(STEPPER_RIGHT_M1_PIN, LOW);
            digitalWrite(STEPPER_LEFT_M0_PIN, HIGH);
            digitalWrite(STEPPER_LEFT_M1_PIN, LOW);
        break;
        case MICROSTEPS_4:
            pinMode(STEPPER_RIGHT_M0_PIN, INPUT);
            digitalWrite(STEPPER_RIGHT_M1_PIN, LOW);
            pinMode(STEPPER_LEFT_M0_PIN, INPUT);
            digitalWrite(STEPPER_LEFT_M1_PIN, LOW);
        break;
        case MICROSTEPS_8: 
            digitalWrite(STEPPER_RIGHT_M0_PIN, LOW);
            digitalWrite(STEPPER_RIGHT_M1_PIN, HIGH);
            digitalWrite(STEPPER_LEFT_M0_PIN, LOW);
            digitalWrite(STEPPER_LEFT_M1_PIN, HIGH);
        break;
        case MICROSTEPS_16: 
            digitalWrite(STEPPER_RIGHT_M0_PIN, HIGH);
            digitalWrite(STEPPER_RIGHT_M1_PIN, HIGH);
            digitalWrite(STEPPER_LEFT_M0_PIN, HIGH);
            digitalWrite(STEPPER_LEFT_M1_PIN, HIGH);
        break;
        case MICROSTEPS_32:
            pinMode(STEPPER_RIGHT_M0_PIN, INPUT);
            digitalWrite(STEPPER_RIGHT_M1_PIN, HIGH);
            pinMode(STEPPER_LEFT_M0_PIN, INPUT);
            digitalWrite(STEPPER_LEFT_M1_PIN, HIGH);
        break;
    
    }
}

void stepperProgram(void){
    //setStepperSpeed(F);
    runSpeed();

}

