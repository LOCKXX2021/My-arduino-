const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH) {
   digitalWrite(ledPin,HIGH);
 }
 else {
 digitalWrite(ledPin, LOW);
 }
Serial.println(buttonState);
}
