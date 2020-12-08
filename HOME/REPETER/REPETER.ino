
/************ HOME *************
 *  NODMCU SERVERDEN GELEN BİLGİLERİ RF İLE TÜM CLİNTLARA
 *  VE RF İLE TÜM CLİENTLARDAN GELEN DATALARI MODMCUYA İLETİR
 *  ARDUİNOæç
 ****************************/


#include <RH_ASK.h>
//#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

//char *controller;


String rdgelen="1";
String rdgiden ="2";
String dene ="2";


void setup() {
 
  Serial.begin(115200);
  if (!driver.init()) Serial.println("FHRFOFAA");
  Serial.println("hazır");
  
}

void loop()
{

 rfal(); //from rf
   
}





  
void rfal()
{  
    uint8_t buf[8];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    { 
  
      int i;
       String rdgelen = (char*)buf;
       
       rdgelen= rdgelen.substring(0,9);

       Serial.println(rdgelen);  
       delay(10);
       Serial.println(rdgelen.substring(8,9));
       
       if(rdgelen.substring(8,9) == "⸮") 
       {  Serial.println("bu"); 
        rdgelen= rdgelen.substring(0,8);
        rdgelen=rdgelen +"R" ;
        rdgonder(rdgelen);
       }
    
     if(rdgelen.substring(8,9) == "R") 
       { Serial.println("bu2"); 
        rdgelen= "1";

       }

        
      // Serial.println(dene);  
     
    }

}



void rdgonder(String rdgiden) //
{
  char *msg = "FHNNNNNN";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println(msg);
  delay(10);
 }
 
