#include "project.h"
void setup() {
  // put your setup code here, to run once:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(leftPin,INPUT);
  pinMode(rightPin,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:



/*
0.判断有无障碍物
  0.无障碍及在黑线上
  1.无障碍及左 or 右不在黑线上
  2.有障碍停

*/




//0.判断有无障碍物

if (distance()<10){                       //有障碍停
  car_stop();
  delay(10);
}
else{ 
  int leftValue = analogRead(leftPin);
  int rightValue = analogRead(rightPin);
  Serial.println(leftValue);
  Serial.println(rightValue);
  if (leftValue > 1000 and rightValue > 1000) {//0.无障碍及在黑线上
  car_full_move();//前进
  delay(20);
 
  }
  else if(leftValue>1000 and rightValue <= 1000){//1.右不在黑线上
  car_left();//左转
  delay(10);
  } 
  else if(rightValue>1000 and leftValue <= 1000){//2.左不在黑线上
  car_right();//右转
  } 
  else{//左右均不在黑线上
  car_wait();//待机
  }
}

}
