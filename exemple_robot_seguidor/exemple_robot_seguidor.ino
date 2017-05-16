// robot seguidor de linea 
// segueix una linea blanca delimitada per dues lineas negres 

// Definició de les sortides 
int MD1= 6; // Motor Dret 
int ME1= 5 ; // Motor Esquerra 

// Definició de les entrades 
int SD1 = A4; // Sensor dret 
int SE1 = A5; // Sensor esquerra 

// read 

 int readSD1= 0; // variable de lectura del sensor dret (sd1)
 int readSE1= 0; // variable de lectura del sensor esquerra (SDE1) 

// Funció d'inicialització 

void setup() 
{
  // Configuració  de les sortides 
 pinMode (MD1,OUTPUT);
 pinMode (ME1,OUTPUT);

 digitalWrite (MD1,HIGH),
 digitalWrite (ME1,HIGH);

 // Configuració de les entrades 

 pinMode (SD1,INPUT);
 pinMode (SE1,INPUT);

}
 int Estat =10 ;  // variable d'estat 

  
void loop()
{ 
  // LLeguir l'estat dels sensors del Robot 
  readSD1 = digitalRead (SD1); 
  readSE1 = digitalRead (SE1);

  switch (Estat)
  {
    // Gir Dreta 
    case 10:
    // seguint la linea 
     { 
      digitalWrite (MD1,HIGH); // motor dret a 1 
      digitalWrite (ME1,HIGH); // motor esquerra a 1
      if (readSE1 && !readSD1)
        { 
          Estat=20;          
        }
        
      if (!readSE1 && readSD1)     
       {
        Estat =100 ; 
       }
     }
     break;
     
     case 20:
      // girant esquerra 
     {    
      digitalWrite (MD1,LOW); // motor dret a 0
      digitalWrite (ME1,HIGH); // motor esquerra a 1
      if (readSE1 && readSD1)
        { 
          Estat=30;          
        }
        
      if (!readSE1 && !readSD1)     
       {
        Estat =10 ; 
       }
     }
     break; 
     
     case 30:
     {   
      digitalWrite (MD1,LOW); // motor dret a 1 
      digitalWrite (ME1,HIGH); // motor esquerra a 1
      if (!readSE1 && readSD1)
        { 
          Estat=40;          
        }
        
      if (readSE1 && !readSD1)     
       {
        Estat =20 ; 
       }   
     }
     break; 
     
     case 40:
     {
      digitalWrite (MD1,LOW); // motor dret a 1 
      digitalWrite (ME1,HIGH); // motor esquerra a 1
      if (!readSE1 && !readSD1)
        { 
          Estat=50;          
        }
        
      if (readSE1 && readSD1)     
       {
        Estat =30 ; 
       }
              
     }
     break; 
     
     case 50:
     {
      digitalWrite (MD1,LOW ); // motor dret a 1 
      digitalWrite (ME1,HIGH); // motor esquerra a 1
      if (readSE1 && !readSD1)
        { 
          Estat=20;          
        }
        
      if (!readSE1 && readSD1)     
       {
        Estat =100 ; 
       }
              
     }
     break; 
     
     // Gir Esquerra 
     
     case 100:
     {
              
     }
     break; 
     
     case 110:
     {
              
     }
     break; 
     
     case 120:
     {
              
     }
     break; 
     
     case 130:
     {
              
     }
     break; 
  }



}
