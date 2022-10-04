int ledPin = 5;//创建ledPin变量
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);//初始化引脚状态
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0;i<=250;i+=5){//通过循环逐步增加PWM输出电压
    analogWrite(ledPin,i);
    delay(50);
  }
  for(int i = 255;i>5;i-=5){//通过循环逐步降低PWM输出电压
    analogWrite(ledPin,i);
    delay(50);
  }
}
