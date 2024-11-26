#include <Servo.h>
Servo servo;
void setup() {
Serial.begin(9600); // Initialize the serial monitor
pinMode(D6, OUTPUT);//room 1
pinMode(D7, OUTPUT);//room 2
servo.attach(D0); // ac
}
void loop() {
if (Serial.available()) {
String receivedData = Serial.readString();
Serial.print("Received data: ");
Serial.println(receivedData);
if (receivedData == "turn on bedroom lights") {
digitalWrite(D3, HIGH);
}
else if (receivedData == "turn off bedroom lights") {
digitalWrite(D3, LOW);
}
else if (receivedData == "turn on living room lights") {
digitalWrite(D2, HIGH);
else if (receivedData == "turn off living room lights") {
digitalWrite(D2, LOW);
}
}
else if (receivedData == "turn on all lights") {
digitalWrite(D2, HIGH);
digitalWrite(D3, HIGH);
}
else if (receivedData == "turn off all lights") {
digitalWrite(D2, LOW);
digitalWrite(D3, LOW);
}
else if (receivedData == "turn on AC") {
servo.write(180);
}
else if (receivedData == "turn off AC") {
servo.write(100);
}
}
}