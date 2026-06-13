#include "Motors.h"

MotorsClass::MotorsClass(int forward_pin, int backward_pin){
  Forward_PIN = forward_pin;
  Backward_PIN = backward_pin;
  pinMode(Forward_PIN, OUTPUT);
  pinMode(Backward_PIN, OUTPUT);
}

void MotorsClass::FadeForward(uint8_t speed){
  direction = FORWARD;
  targetSpeed = speed;
}

void MotorsClass::FadeBackward(uint8_t speed){
  direction = BACKWARD;
  targetSpeed = speed;
}

void MotorsClass::FadeStop(){
  direction = STOPPED;
  targetSpeed = 0;
}

void MotorsClass::Update(){
  if(currentSpeed == targetSpeed) return;
  if(millis() - lastUpdate < 10) return;
  lastUpdate = millis();

  if(currentSpeed < targetSpeed) currentSpeed++;
  else currentSpeed--;

  analogWrite(Forward_PIN, direction == FORWARD ? currentSpeed : 0);
  analogWrite(Backward_PIN, direction == BACKWARD ? currentSpeed : 0);
}

MotorsClass Right_Motor(RightForward_PIN, RightBackward_PIN); //Placeholders, colocar os PINS reais.
MotorsClass Left_Motor(LeftForward_PIN, LeftBackward_PIN); //Placeholders, colocar os PINS reais.
