//ON bahçe için 1 nol aydınlatma



#include <RH_ASK.h>
//#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

int lamba =2;
int contr = 0;

String rdgelen="";

void setup()



{ pinMode(lamba, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  if (!driver.init()) ;  // Bı komut mutlaka olmalı... **************
  digitalWrite(LED_BUILTIN, LOW);
   digitalWrite(lamba, LOW);
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
       if(rdgelen == "THBDL1ON") isik();
       if(rdgelen == "THBDL1OF") digitalWrite(lamba, LOW);
      if(rdgelen == "THALMOFF") contr=1;
      if(rdgelen == "THALMONN") 
         { contr=0;
           digitalWrite(lamba, LOW);
   
          }

}
}

void isik()
{
 if (contr == 1) digitalWrite(lamba, HIGH);
  

}
