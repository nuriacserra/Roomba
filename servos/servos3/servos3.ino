#include <SoftwareSerial.h> 

#include <Servo.h> 
Servo myservo; 

int bluetoothTx = 10; // 10 pin
int bluetoothRx = 11; // 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(9); 
  myservo.attach(10); 
  Serial.begin(9600);

  bluetooth.begin(9600);
}

void loop()
{
  if(bluetooth.available()> 0 ) 
  {
    int servopos = bluetooth.read(); 
    Serial.println(servopos);
    myservo.write(servopos); 
  }


}
