
/*  ERDEK
 *  
 *  NODMCU SERVERDEN GELEN BİLGİLERİ RF İLE TÜM CLİNTLARA
 *  VE RF İLE TÜM CLİENTLARDAN GELEN DATALARI MODMCUYA İLETİR
 *  ARDUİNO
 */


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
  if (!driver.init()) Serial.println("FERFOFAA");
  Serial.println("hazır");
  
}

void loop()
{
  al();

  rfal();
   
}



void al()
{  
  while (Serial.available())
       {
        srgelen= Serial.readString();


        if (srgelen.substring(0,8)=="TEALMOFF") almkon = 0;
        if (srgelen.substring(0,8)=="TEALMONN") almkon = 1;
      
        if (srgelen.substring(0,8)=="TAREPORT")
          {  if ( almkon == 1) Serial.println("FEOKOKON");  
             if ( almkon == 0) Serial.println("FEOKOKOF");  

          }
        
        //if (srgelen.substring(0,8)=="THREPORT") Serial.println("FHOKOKOK");  
        
    
  if(srgelen.substring(0,8) == "TEREPORT") 
   {  if ( almkon == 1) Serial.println("FEOKOKON");  
      if ( almkon == 0) Serial.println("FEOKOKOF");  

          }     


        
        if (srgelen.substring(0,2)=="TE")
           {
             //Serial.println(srgelen);
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
      // Message with a good checksum received, dump it.
     // Serial.print("Message: ");
    //  Serial.println((char*)buf);    
       String rdgelen = (char*)buf;
       rdgelen= rdgelen.substring(0,8);
       
      //if(rdgelen == "THS1ONAA") digitalWrite(LED_BUILTIN, HIGH);
   
      if (rdgelen == "FEALMALM" && almkon == 1) Serial.println(rdgelen);  
       if (rdgelen != "FEALMALM") Serial.println(rdgelen);  
    }

}



void rdgonder(String rdgiden) //
{
  //Serial.println(rdgiden);
  char *msg = "FENNNNNN";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  //Serial.println(msg);
 // Serial.println("Hello World!");
  delay(10);
 }
 
