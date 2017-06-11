int pinfdc1 = 3;
int pinfdc2 = 4;  
int pinfdc3 = 2;
int pinfdc4 = 5; 
int valor1 = 0; 
int valor2 = 0;
int valor3 = 0; 
int valor4 = 0;


void setup() {
Serial.begin(9600); 
}

void loop()
{
valor1= analogRead(pinfdc1); 
delay (2);
valor2= analogRead(pinfdc2); 
valor3= analogRead(pinfdc3); 
valor4= analogRead(pinfdc4); 

Serial.print("Lectura del fdc1:"); 
Serial.print("\t");
Serial.print(valor1);
Serial.print("\t");
Serial.print("Lectura del fdc2:"); 
Serial.print("\t");
Serial.println(valor2);
Serial.print("Lectura del fdc3:"); 
Serial.print("\t");
Serial.print(valor3);
Serial.print("\t");
Serial.print("Lectura del fdc4:"); 
Serial.print("\t");
Serial.print(valor4);
Serial.print("\t");
delay (100);
}
