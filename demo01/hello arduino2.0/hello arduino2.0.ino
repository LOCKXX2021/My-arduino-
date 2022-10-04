int delaytime = 500;
int longSunTime = 1000;
int ShortSunTime = 500;
void setup() {

  pinMode(3,OUTPUT);
}


void loop() {
for(int i=1;i<=3;i++){
 digitalWrite(LED_BUILTIN, HIGH);
 delay(ShortSunTime);
 digitalWrite(LED_BUILTIN, LOW);
 delay(delaytime);
} 
for(int i=1;i<=3;i++){
 digitalWrite(LED_BUILTIN, HIGH);
 delay(longSunTime);
 digitalWrite(LED_BUILTIN, LOW);
 delay(delaytime);
}
}