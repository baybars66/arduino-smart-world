//ON bahçe için   TAVAN aydınlatma 1



#include <RH_ASK.h>
//#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  if (!driver.init()) ;  // Bı komut mutlaka olmalı... **************
  digitalWrite(LED_BUILTIN, LOW);
        
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
       if(rdgelen == "THGNL1ON")  digitalWrite(LED_BUILTIN, HIGH);
       if(rdgelen == "THGNL1OF") digitalWrite(LED_BUILTIN, LOW);
      
   
    }

}
