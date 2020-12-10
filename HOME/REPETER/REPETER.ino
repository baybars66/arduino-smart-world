
/************ HOME REPETER*************
 *  ÖN BAHÇEYE ULAŞMAYAN RF SINYALINI ALIP TEKRAR YOLLAMA
 *  AYRICA L1 LAMBASINI MANUEL YAKMA VE REPORT SORULDUĞUNDA
 *  ORTAM SICAKLIGINI İLETME
  ****************************/

#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#include <RH_ASK.h>

#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
#define Buton 5

dht11 DHT11;

RH_ASK driver;

String rdgelen="1";
String rdgiden ="2";
String sicaklik ="";
String gitti = "";



void setup() {
  
  pinMode(Buton, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  if (!driver.init()) Serial.println("FHRFOFAA");
  Serial.println("hazır");
  
}

void loop()
{
  
 rdgelen="1";
 
 rfal(); //from rf

 if (digitalRead(Buton) == 1) isik();
  
}


void isik()
{
  if (digitalRead(LED_BUILTIN) == LOW )
     {
       digitalWrite(LED_BUILTIN, HIGH);
       rdgonder("THGNL1ON");
      }
  else
     {
       digitalWrite(LED_BUILTIN, LOW);
       rdgonder("THGNL1OF");
      }
    
    delay(500);

}


  
void rfal()
{  
    uint8_t buf[8];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {  
      int i;
      rdgelen = (char*)buf;
      rdgelen= rdgelen.substring(0,8);

      if (rdgelen.substring(0,2) != "TH") return;
      
       //Serial.println(rdgelen);  
      if (rdgelen == "THREPORT")
         { 
           isi();
           return;
         }

   if (rdgelen == "THALMONN")
       { 
         secure();
         return;
       }
   
   if ( rdgelen!= gitti) 
        {
         rdgonder(rdgelen);
         gitti = rdgelen;
         }
       
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


 void isi()
{

  int chk = DHT11.read(DHT11PIN);
  int bb =DHT11.temperature;
  String baba = String(bb);
  sicaklik = "FWTEMP" + baba;
  rdgonder(sicaklik);

}

 void secure()
{
  
 digitalWrite(LED_BUILTIN, LOW);
 rdgonder("THGNL1OF");
 delay (10);
 rdgonder("THGNL2OF");
 delay (10);
 rdgonder("THBHSKOF");
 delay (10);
 rdgonder("THLRNLOF");
 delay (10);
 rdgonder("THBHCSOF");
 delay (10);


}
