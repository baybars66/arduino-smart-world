//ON bahçe için abajur aydınlatma



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
       if(rdgelen == "THGNLTON")  digitalWrite(LED_BUILTIN, HIGH);
       if(rdgelen == "THGNLTOF") digitalWrite(LED_BUILTIN, LOW);
      
   
    }

}
