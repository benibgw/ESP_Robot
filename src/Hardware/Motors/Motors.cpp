#include "Motors.h"

MotorsClass::MotorsClass(int forward_pin, int backward_pin, int pwm_pin){
  Forward_PIN = forward_pin;
  Backward_PIN = backward_pin;
  PWM_PIN = pwm_pin;
  pinMode(Forward_PIN, OUTPUT);
  pinMode(Backward_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
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

void MotorsClass::update(){
  if(currentSpeed == targetSpeed) return;
  if(millis() - lastUpdate < 10) return;
  lastUpdate = millis();

  if(currentSpeed < targetSpeed) currentSpeed++;
  else currentSpeed--;

  digitalWrite(Forward_PIN, direction == FORWARD ? HIGH : LOW);
  digitalWrite(Backward_PIN, direction == BACKWARD ? HIGH : LOW);
  analogWrite(PWM_PIN, currentSpeed);
}

MotorsClass Right_Motor(12, 13, 26);
MotorsClass Left_Motor(14, 27, 25);
