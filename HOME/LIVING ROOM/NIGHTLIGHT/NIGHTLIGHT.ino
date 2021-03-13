  //Oturma odası gece lambası için 1 nol aydınlatma



#include <RH_ASK.h>
//#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

//int lamba =2 ;

String rdgelen="";

void setup()



{ //pinMode(lamba, OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  if (!driver.init()) ;  // Bı komut mutlaka olmalı... **************
  digitalWrite(LED_BUILTIN, HIGH);
  // digitalWrite(lamba, HIGH);
        Serial.begin(115200);
  if (!driver.init()) Serial.println("FHRFOFAA");
  Serial.println("hazır");
}

void loop()
{

    rfal();
}



void rfal()
{
    uint8_t buf[8];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {      
       String rdgelen = (char*)buf;
       rdgelen= rdgelen.substring(0,8);
       Serial.println(rdgelen);
       if(rdgelen == "THBMARON") digitalWrite(LED_BUILTIN, LOW);
       if(rdgelen == "THBMAROF") digitalWrite(LED_BUILTIN, HIGH);
       if(rdgelen == "THALMOFF") digitalWrite(LED_BUILTIN, HIGH);
      
   
    }

}
