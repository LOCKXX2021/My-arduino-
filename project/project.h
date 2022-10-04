#include "HardwareSerial.h"
#include "Arduino.h"
//定义超声波模块
#define trigPin 7
#define echoPin 6
//脉冲时间变量

int distance(void){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);//稳定电位
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin,HIGH, 50000);//得到脉冲时间
  int distance_cm = duration/58;
  //Serial.println(distance_cm);
  return distance_cm;
}



//定义红外模块
#define leftPin A0
#define rightPin A1




//定义驱动模块
#define PWMA 3
#define AIN2 8
#define AIN1 9
#define STBY 10
#define BIN1 11
#define BIN2 12
#define PWMB 5

void motor_full_move(int IN1,int IN2){
  //define a move function
  digitalWrite(STBY, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  if(IN1 == AIN1){
  analogWrite(PWMA,80);
  }
  if(IN1 == BIN1){
  analogWrite(PWMB,80);
  
  }
}

void motor_backmove(int IN1,int IN2){
  //define a backmove function
  digitalWrite(STBY, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  if(IN1 == AIN1){
    analogWrite(PWMA,156);
  }
  if(IN1 == BIN1){
    analogWrite(PWMB,156);

  }

}
void motor_move(int IN1,int IN2){
  //define a backmove function
  digitalWrite(STBY, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  if(IN1 == AIN1){
  analogWrite(PWMA,255);
  }
  if(IN1 == BIN1){
  analogWrite(PWMB,255);
  }
}
void motor_stop(int IN1,int IN2){
  //define a stop function
  digitalWrite(STBY, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  if(IN1 == AIN1){
  digitalWrite(PWMA,LOW);
  }
  if(IN1 == BIN1){
  digitalWrite(PWMB,LOW);
  }
}
void car_right(void){
  //define a move to left function
  //左电机快转，右电机慢转
  motor_backmove(BIN1,BIN2);
  motor_full_move(AIN1,AIN2);
}
void car_left(void){
  //define a move to right function
  //左电机慢转，右电机快转
  motor_backmove(AIN1,AIN2);
  motor_full_move(BIN1,BIN2);

}
void car_stop(void){
  //define a stop function
  motor_stop(AIN1,AIN2);
  motor_stop(BIN1,BIN2);

}
void car_full_move(void){
  //define a function let car full-speed move
  motor_full_move(AIN1, AIN2);
  motor_full_move(BIN1, BIN2);
}
void car_wait(void){
  digitalWrite(STBY, LOW);
}

