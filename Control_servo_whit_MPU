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
  if(millis() - timer > 1000){
    
    int aci = map(mpu6050.getAngleY(), -35,60, 0,180);
    Serial.println(aci);
    srv.write(aci);
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

