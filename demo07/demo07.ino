#define readPin A0//定义输入引脚
void setup() {
  // put your setup code here, to run once:
pinMode(readPin, INPUT);//初始化引脚
Serial.begin(9600);//初始化波特率 
}

void loop() {
  // put your main code here, to run repeatedly:
int readValue = analogRead(readPin);//定义读取电压值变量
if (readValue>=1000) {//逻辑判断黑白线
Serial.println('black');
}
else {
Serial.println('white');
}
}
}
