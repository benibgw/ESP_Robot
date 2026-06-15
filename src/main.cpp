#include <Arduino.h>
#include "Robot/Robot.h"

void setup(){
  Robot.begin();
}

void loop(){
  Robot.update();
}
