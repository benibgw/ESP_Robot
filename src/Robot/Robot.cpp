#include "Robot.h"

RobotClass::RobotClass(){}

void RobotClass::begin(){
  WebPage.begin();
  Serial.begin(9600);
}

void RobotClass::update(){
  WebPage.update();

  if(WebPage.query() == "FORWARD"){
    Right_Motor.FadeForward();
    Left_Motor.FadeForward();
    Serial.println("FORWARD");
  }
  else if(WebPage.query() == "BACKWARD"){
    Right_Motor.FadeBackward();
    Left_Motor.FadeBackward();
    Serial.println("BACKWARD");
  }
  else if(WebPage.query() == "RIGHT"){
    Right_Motor.FadeBackward();
    Left_Motor.FadeForward();
    Serial.println("RIGHT");
  }
  else if(WebPage.query() == "LEFT"){
    Right_Motor.FadeForward();
    Left_Motor.FadeBackward();
    Serial.println("LEFT");
  }
  else if(WebPage.query() == "FORWARD_RIGHT"){
    Right_Motor.FadeForward(127);
    Left_Motor.FadeForward(255);
    Serial.println("FORWARD_RIGHT");
  }
  else if(WebPage.query() == "FORWARD_LEFT"){
    Right_Motor.FadeForward(255);
    Left_Motor.FadeForward(127);
    Serial.println("FORWARD_LEFT");
  }
  else if(WebPage.query() == "BACKWARD_RIGHT"){
    Right_Motor.FadeBackward(127);
    Left_Motor.FadeBackward(255);
    Serial.println("BACKWARD_RIGHT");
  }
  else if(WebPage.query() == "BACKWARD_LEFT"){
    Right_Motor.FadeBackward(255);
    Left_Motor.FadeBackward(127);
    Serial.println("BACKWARD_LEFT");
  }
  else{
    Right_Motor.FadeStop();
    Left_Motor.FadeStop();
    Serial.println("STOPPED");
  }

  Right_Motor.update();
  Left_Motor.update();
}

RobotClass Robot;
