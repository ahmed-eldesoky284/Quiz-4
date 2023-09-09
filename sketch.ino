#include <LiquidCrystal_I2C.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,20,4);
Adafruit_MPU6050 mpu;
int x = A0;
int y = A1;
void setup() {
  lcd.init();
  lcd.backlight();
  mpu.begin();
  pinMode(x, INPUT);
  pinMode(y, INPUT);
}
sensors_event_t event;
void loop() {
  mpu.getAccelerometerSensor()->getEvent(&event);
  int X = analogRead(x);
  int Y = analogRead(y);
  lcd.setCursor(0,0);
  lcd.println("Pitch ="+String(event.acceleration.x/1,0));
  lcd.setCursor(0,1);
  lcd.println("Roll ="+String(event.acceleration.y/1,0));
  lcd.setCursor(0,2);
  lcd.println("x = "+String(X));
  lcd.setCursor(0,3);
  lcd.println("y = "+String(Y));

}
