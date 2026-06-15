#pragma once
#include <Arduino.h>
#include "../Hardware/Motors/Motors.h"
#include "../WebPage/WebPage.h"

class RobotClass{
  public:
    RobotClass();
    void begin();
    void update();
};

extern RobotClass Robot;
