#define ledPin 5
#define potPin A0
void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);// 改变A0引脚为输入模式
  pinMode(ledPin, OUTPUT);//改变第五引脚为输出模式
  Serial.begin(9600);//初始化波特率
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(A0);//创建状态变量 
  analogWrite(5,potValue/4 );
  Serial.print(potValue); //打印到串口监视器
  Serial.print(" ");
  Serial.println(potValue/4);// 将输出值打印
}
