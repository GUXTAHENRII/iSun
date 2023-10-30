#include <Servo.h>
Servo servo;
int eLDRPin = A0; 
int wLDRPin = A1;
int eastLDR = 0; 
int westLDR = 0;
int difference = 0; 
int error = 10;
int servoSet = 130; 
void setup() {
 servo.attach(9);
 Serial.begin(9600); 
}
void loop() {
 eastLDR = analogRead(eLDRPin); 
 westLDR = analogRead(wLDRPin);
 if (eastLDR < 400 && westLDR < 400) {
 while (servoSet <=140 && servoSet >=15) {
     servoSet ++;
     servo.write(servoSet);
     delay(100);
   }
 }
     servoSet ++;
     servo.write(servoSet);
 difference = eastLDR - westLDR ; 
 if (difference > 10) {
   if (servoSet <= 140) {
   }
 } else if (difference < -10) {
   if (servoSet >= 15) {
     servoSet --;
     servo.write(servoSet);
   }
 }
 Serial.print(eastLDR);
 Serial.print("   -   ");
 Serial.print(westLDR);
 Serial.print("   -   ");
 Serial.print(difference);
 Serial.print("   -   ");
 Serial.print(servoSet);
 Serial.print("   -   ");
 Serial.println(".");
 delay(100);}