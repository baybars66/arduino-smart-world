
/************ HOME *************
 onbahce ısıkları açma kapama remote kontrol
 ****************************/


#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

//char *controller;



int but1 = 2;
int but2 = 3;

int but3 = 4;
int but4 = 5;

int buttonState = 0;
void setup() {
  digitalWrite ( but1 , LOW);
  digitalWrite ( but2 , LOW);
  digitalWrite ( but3 , LOW);
  digitalWrite ( but4 , LOW);
  
   pinMode(but1, INPUT);
   pinMode(but2, INPUT);
   pinMode(but3, INPUT);
   pinMode(but4, INPUT);
   
 
  
  Serial.begin(115200);
  if (!driver.init()) Serial.println("FHRFOFAA");
  Serial.println("hazır");
 
}

void loop()
{

  buttonState = digitalRead(but1); 
  if ( buttonState == HIGH) { rdgonder ("THGNL1ON");
   return;
  }  
  

  buttonState = digitalRead(but2); 
  if ( buttonState == HIGH) { rdgonder ("THGNL1OF");
   return;
  }  


  buttonState = digitalRead(but3); 
  if ( buttonState == HIGH) { rdgonder ("THGNL2ON");
   return;
  }  


    buttonState = digitalRead(but4); 
  if ( buttonState == HIGH) { rdgonder ("THGNL2OF");
   return;
  }  
 
   
}




void rdgonder(String rdgiden) //
{
  //Serial.println(rdgiden);
  char *msg = "FHNNNNNN";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
 Serial.println(msg);
 // Serial.println("Hello World!");
  delay(10);
 }
 
