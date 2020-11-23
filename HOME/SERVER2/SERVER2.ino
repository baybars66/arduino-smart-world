
/************ HOME *************
 *  NODMCU SERVERDEN GELEN BİLGİLERİ RF İLE TÜM CLİNTLARA
 *  VE RF İLE TÜM CLİENTLARDAN GELEN DATALARI MODMCUYA İLETİR
 *  ARDUİNO
 ****************************/


#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

//char *controller;


String rdgelen="";
String rdgiden ="";

int almkon =1;
String srgelen="";
String srgiden ="";

void setup() {
 
  Serial.begin(115200);
  if (!driver.init()) Serial.println("FHRFOFAA");
  Serial.println("hazır");
  
}

void loop()
{
  al(); //from interbet over mcu via serialport

  rfal(); //from rf
   
}



void al()
{  
  while (Serial.available())
       {
        srgelen= Serial.readString();

        
        if (srgelen.substring(0,2)=="TH")
           {
    // bunu kullanma hemen kapat Serial.println(srgelen);
             rdgonder(srgelen);
            }

       /*
        srgelen= srgelen.substring(0,8);

        if (srgelen =="THALMOFF") almkon = 0;
        if (srgelen =="THALMONN") almkon = 1;
      
        if (srgelen =="TAREPORT") 
           {  if ( almkon == 1) Serial.println("FHOKOKON");  
             if ( almkon == 0) Serial.println("FHOKOKOF");  

          }

*/
        
        }

}



  
void rfal()
{  
    uint8_t buf[8];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    { 
  
      int i;
      // Message with a good checksum received, dump it.
     // Serial.print("Message: ");
    //  Serial.println((char*)buf);    
       String rdgelen = (char*)buf;
       rdgelen= rdgelen.substring(0,8);
     Serial.println(rdgelen);  
     //  if (rdgelen == "FHALMALM" && almkon == 1) Serial.println(rdgelen);  
      // if (rdgelen != "FHALMALM") Serial.println(rdgelen);  
       
      //if(rdgelen == "THS1ONAA") digitalWrite(LED_BUILTIN, HIGH);
   
    
    }

}



void rdgonder(String rdgiden) //
{
  //Serial.println(rdgiden);
  char *msg = "FHNNNNNN";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  //Serial.println(msg);
 // Serial.println("Hello World!");
  delay(10);
 }
 
