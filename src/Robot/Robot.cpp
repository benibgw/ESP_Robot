#include "Robot.h"

RobotClass::RobotClass(){}

void RobotClass::begin(){
  WebPage.begin();
}

void RobotClass::update(){
  WebPage.update();

  if(WebPage.query() == "FORWARD"){
    Right_Motor.FadeForward();
    Left_Motor.FadeForward();
  }
  else if(WebPage.query() == "BACKWARD"){
    Right_Motor.FadeBackward();
    Left_Motor.FadeBackward();
  }
  else if(WebPage.query() == "RIGHT"){
    Right_Motor.FadeBackward();
    Left_Motor.FadeForward();
  }
  else if(WebPage.query() == "LEFT"){
    Right_Motor.FadeForward();
    Left_Motor.FadeBackward();
  }
  else if(WebPage.query() == "FORWARD_RIGHT"){
    Right_Motor.FadeForward(127);
    Left_Motor.FadeForward(255);
  }
  else if(WebPage.query() == "FORWARD_LEFT"){
    Right_Motor.FadeForward(255);
    Left_Motor.FadeForward(127);
  }
  else if(WebPage.query() == "BACKWARD_RIGHT"){
    Right_Motor.FadeBackward(127);
    Left_Motor.FadeBackward(255);
  }
  else if(WebPage.query() == "BACKWARD_LEFT"){
    Right_Motor.FadeBackward(255);
    Left_Motor.FadeBackward(127);
  }
  else{
    Right_Motor.FadeStop();
    Left_Motor.FadeStop();
  }

  Right_Motor.update();
  Left_Motor.update();
}

RobotClass Robot;
