#pragma once
#include <Arduino.h>

class MotorsClass{
  public:
    enum MotorDirection{STOPPED, FORWARD, BACKWARD};
    MotorsClass(int forward_pin, int backward_pin);
    void FadeForward(uint8_t speed = 255);
    void FadeBackward(uint8_t speed = 255);
    void FadeStop();
    void update();
  private:
    int Forward_PIN;
    int Backward_PIN;
    uint8_t currentSpeed = 0;
    uint8_t targetSpeed = 0;
    MotorDirection direction = STOPPED;
    unsigned long lastUpdate = 0;
};

extern MotorsClass Right_Motor;
extern MotorsClass Left_Motor;
