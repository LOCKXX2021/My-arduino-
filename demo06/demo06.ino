int trigPin = 7;    //Trig
int echoPin = 6;    //Echo
long duration, cm;
 
void setup() {
  //初始化串口
  Serial.begin (9600);
  //更改引脚模式
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop()
{
 
 

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);//稳定电位
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);//给10ms脉冲
  digitalWrite(trigPin, LOW);
 
  
  duration = pulseIn(echoPin, HIGH,50000);//读回响脉冲时间
 
 
  cm = duration/58;//计算距离，单位cm
 
  
  Serial.print(cm);//打印计算结果至串口
  Serial.print("cm");
  Serial.println();
  
  delay(100);//延迟100ms
}