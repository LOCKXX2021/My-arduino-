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
void car_right(){
  //define a move to left function
  //左电机快转，右电机慢转
  motor_backmove(BIN1,BIN2);
  motor_full_move(AIN1,AIN2);
}
void car_left(){
  //define a move to right function
  //左电机慢转，右电机快转
  motor_backmove(AIN1,AIN2);
  motor_full_move(BIN1,BIN2);

}
void car_stop(){
  //define a stop function
  motor_stop(AIN1,AIN2);
  motor_stop(BIN1,BIN2);

}
void car_full_move(){
  //define a function let car full-speed move
  motor_full_move(AIN1, AIN2);
  motor_full_move(BIN1, BIN2);
}
void car_wait(){
  digitalWrite(STBY, LOW);
}


