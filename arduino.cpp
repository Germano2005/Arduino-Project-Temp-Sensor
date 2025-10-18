#include <Servo.h>

int temp = 0;

Servo servo_6;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  servo_6.attach(6, 500, 2500);
  pinMode(5, OUTPUT);
}

void loop()
{
  Serial.println(temp);
  temp = (-40 + 0.488155 * (analogRead(A0) - 20));
  if (temp < 30) {
    digitalWrite(2, LOW);
    servo_6.write(0);
    noTone(5);
  }
  if (temp >= 30) {
    servo_6.write(30);
  }
  if (temp > 50) {
    digitalWrite(2, HIGH);
    tone(5, 5274, 1000); // play tone 100 (E8 = 5274 Hz)
    servo_6.write(0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}