
// definicio de les llibreries 
#include <AFMotor.h>
#include <AccelStepper.h>
#include <SoftwareSerial.h> 
#include <Servo.h> 

// definicio de els motors i el servos 
Servo miniservo(1);
Servo miniservo(2);
AF_DCMotor motor (4);
AF_DCMotor motor (3); 

// Definicio de les entrades de la arduino  
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
