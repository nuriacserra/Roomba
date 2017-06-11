
// Llibreries per el motor /servos / bluetooth 
#include <AFMotor.h>                  // llibreria motor 
#include <SoftwareSerial.h>           // llibreria bluetooth 
#include <Servo.h>                    // llibreria servo 


// Declaració de variables : 

AF_DCMotor motor(4);                  // motor esquerra al pin 4 
AF_DCMotor motor1(3);                 // motor dret al pin 3 

// declaració de les variables del conectors :  
int pinfdc1 = 3;
int pinfdc2 = 4;  
int pinfdc3 = 2;
int pinfdc4 = 5; 
int valor1 = 0; 
int valor2 = 0;
int valor3 = 0; 
int valor4 = 0;


// Declaració de la activació de cada motor 
void setup()                          
{
  Serial.begin(9600);         
  
  motor.setSpeed(250);
  motor.run(RELEASE);                 // el motor 1 en pausa  (motor esquerra)
  motor1.setSpeed(300);
  motor1.run(RELEASE);                // el motor dos en pausa (motor dret)

}

// Declaració de les funcións que volem que realitzi : 

void loop() 
{
   valor1= analogRead(pinfdc1); 
   valor2= analogRead(pinfdc2); 
   valor3= analogRead(pinfdc3); 
   valor4= analogRead(pinfdc4); 
    delay (200);
    motor.run(FORWARD);                // motor esquerra va cap endavant  
    motor1.run(FORWARD);               // motor dret va cap endavant 

  if (valor3==0) // DAVANT DRETA 
  { 
    motor.run (BACKWARD);                // motor esquerra va cap endarrera  
    motor1.run(BACKWARD);                // motor dret va cap endarrera 
    delay (2000); 
    motor.run(BACKWARD);                  
    motor1.run(FORWARD);              
    delay (2500);
  }
  else if (valor4==0) // DAVANT ESQUERRA 
  {
    motor.run (BACKWARD);                // motor esquerra va cap endarrera  
    motor1.run(BACKWARD);                // motor dret va cap endarrera 
    delay (2000); 
    motor.run(FORWARD);                  
    motor1.run(BACKWARD);              
    delay (2500);
  }
  else if (valor1==0) // darrera dreta 
  {
    motor.run (FORWARD);                // motor esquerra va cap ENDANVAT
    motor1.run(FORWARD);                // motor dret va cap ENDAVANT 
    delay (2000); 
    motor.run(BACKWARD);                  
    motor1.run(FORWARD);              
    delay (2500);
  }
  else if (valor2==0)  // darrera esquerra 
  {
    motor.run (FORWARD);                // motor esquerra va cap ENDANVAT 
    motor1.run(FORWARD);                // motor dret va cap ENDAVANT
    delay (2000); 
    motor.run(FORWARD);                  
    motor1.run(BACKWARD);              
    delay (2500);
  }
}
