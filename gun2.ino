#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>

MPU6050 mpu6050(Wire);
long timer = 0;

Servo srv;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  srv.attach(6);

  for(int i=3; i<=5; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  mpu6050.update();
 // Serial.println(analogRead(A0));
  int pot = map(analogRead(A0),5,1018, 0,180);
  Serial.println(pot);
  srv.write(pot);delay(10);
  if(millis() - timer > 1000){
    

    if(mpu6050.getAngleY() >= 20){
      Blue();
    }
    
    if(mpu6050.getAngleY() <= 0){
      Red();
    }
    if(mpu6050.getAngleY() < 20 && mpu6050.getAngleY() > 0)
    {
      Yellow();
    }
    
  }
}

void Blue(){
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,0);
}

void Red(){
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,1);
}

void Yellow(){
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
}

