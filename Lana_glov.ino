#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>

MPU6050 mpu6050(Wire);
long timer = 0;

Servo srvF1;
Servo srvF2;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  srvF1.attach(11);
  srvF2.attach(12);
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 1000){
    if(mpu6050.getAngleY() >= 20)
      Serial.println("Right");
    else if(mpu6050.getAngleY() <= -20)
      Serial.println("Left");
    else
      Serial.println("Midel");
    int pot1 = analogRead(A0);
    int pot2 = analogRead(A1);
    int fing1 = map(pot1, 0,1023, 0,180);
    int fing2 = map(pot2, 0,1023, 0,180);
    srvF1.write(fing1);
    srvF2.write(fing2);
    timer = millis();
  }

}
