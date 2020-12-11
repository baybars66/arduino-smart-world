
/************ HOME *************
 *  NODMCU SERVERDEN GELEN BİLGİLERİ RF İLE TÜM CLİNTLARA
 *  VE RF İLE TÜM CLİENTLARDAN GELEN DATALARI MODMCUYA İLETİR
 *  ARDUİNO
 ****************************/


#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;


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

        }

}



  
void rfal()
{  
    uint8_t buf[8];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    { 
      int i;
      String rdgelen = (char*)buf;
      rdgelen= rdgelen.substring(0,8);
      if ( rdgelen.substring(0,2) == "FH")  Serial.println(rdgelen); 
    
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
   delay(10);
 }
 
