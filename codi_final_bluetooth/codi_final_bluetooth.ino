// Llibreries per el motor /servos / bluetooth 
#include <AFMotor.h>                  // llibreria motor 
#include <SoftwareSerial.h>           // llibreria bluetooth 
#include <Servo.h>                    // llibreria servo 


// Declaració de variables : 
AF_DCMotor motor(4);                  // motor esquerra al pin 4 
AF_DCMotor motor1(3);                 // motor dret al pin 3 

// Declaració de les variables del conectors :  
int pinfdc1 = 3;
int pinfdc2 = 4;  
int pinfdc3 = 2;
int pinfdc4 = 5; 
int valor1 = 0; 
int valor2 = 0;
int valor3 = 0; 
int valor4 = 0;

int pausa = 1000 ;
// Declaració de la activació de cada motor 
void setup()                          
{
  Serial.begin(9600);                 // per a la lectura de el bluetooth 
  motor.setSpeed(255);
  motor.run(RELEASE);                 // el motor 1 en pausa  (motor esquerra)
  motor1.setSpeed(255);
  motor1.run(RELEASE);                // el motor dos en pausa (motor dret)
}

// Declaració de les funcións que volem que realitzi : 

void loop() 
{
  // lector de els sensors de fi de cursa 
   valor1= analogRead(pinfdc1); 
   valor2= analogRead(pinfdc2); 
   valor3= analogRead(pinfdc3); 
   valor4= analogRead(pinfdc4); 
    delay (200);

    // on del robot- lectura endavant 
    motor.run(FORWARD);                // motor esquerra va cap endavant  
    motor1.run(FORWARD);               // motor dret va cap endavant
// control de Fi de Curses (FDC)   
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
   // bluetooth 
    else if(Serial.available()>=1)
      {
      char entrada = Serial.read(); //Leer un caracter
      
       if(entrada == 'm' or entrada == 'M') //Si es 'M', endavant els motors 
      {
         motor.run(FORWARD);
         motor1.run(FORWARD);
         delay(pausa);
         Serial.println("motors endavant ");
      }
 
      else if(entrada == 'n' or entrada == 'N') //Si es 'N', deixara de anar endavant 
      {
         motor.run(RELEASE);
         motor1.run(RELEASE);
         delay(pausa);
         Serial.println("motors parat ");
      }
      else if(entrada == 'v' or entrada == 'V') //Si es 'V', va cap endarrera  
      {
         motor.run(BACKWARD);
         motor1.run(BACKWARD);
         delay(pausa);
         Serial.println("motors endarrera");
      }
      else if(entrada == 'w' or entrada == 'W') //Si es 'W', deixara de anar endarrera 
      {
         motor.run(RELEASE);
         motor1.run(RELEASE);
         delay(pausa);
         Serial.println("motors parat");
      }
      else if(entrada == 's' or entrada == 'S') //Si es 'S', Funcionaran els servos  
      {
       
         Serial.println("Servos ON ");
      }
      else if(entrada == 'r' or entrada == 'R') //Si es 'R', deixara de anar els servos  
      {
      
         Serial.println("Servos OFF ");
      }
      else if(entrada == 'l' or entrada == 'L') //Si es 'L', el robot girara a la dreta  
      {
          motor.run(FORWARD);                // motor esquerra funcióna   
          motor1.run(RELEASE);               // motor dret en pausa 
          delay(pausa);
         Serial.println("motor gir a la dreta ");
      }
      else if(entrada == 'o' or entrada == 'O') //Si es 'O', el robot deixa de girara a la dreta  
      {
          motor.run(RELEASE);                // motor esquerra en pausa   
          motor1.run(RELEASE);               // motor dret en pausa 
          delay(pausa); 
         Serial.println("motor para de gir a la dreta ");
      }
      else if(entrada == 't' or entrada == 'T') //Si es 'T', el robot girara a la Esquerra
      {
          motor.run(RELEASE);                // motor esquerra pausa   
          motor1.run(FORWARD);               // motor dret en funcionament 
          delay(pausa); 
         Serial.println("motor gir a la esquerra ");
      }
      else if(entrada == 'u' or entrada == 'U') //Si es 'U', el robot deixa de girara a la Esquerra
      {
          motor.run(RELEASE);                   // motor esquerra pausa   
          motor1.run(RELEASE);                  // motor dret pausa
          delay(pausa); 
         Serial.println("motor gir a la esquerra ");
      }
    }
}
