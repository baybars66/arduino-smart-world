
/************ HOME REPETER*************
 *  ÖN BAHÇEYE ULAŞMAYAN RF SINYALINI ALIP TEKRAR YOLLAMA
 *  AYRICA L1 LAMBASINI MANUEL YAKMA VE REPORT SORULDUĞUNDA
 *  ORTAM SICAKLIGINI İLETME
  ****************************/


/************ HOME REPETER*************
 * Bu program repeter olduğu için aldığı data datayı yollarken resetliyordu. Bu nedenle
 * sent ve Rec kontrollerle alırken ve gönerirken birini açıp diğerini kapattım
 * Bu yapıyı bozma!!!!!!!!!!!!!!!!!!!!!
  ****************************/


  
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

#include <dht11.h> // dht11 kütüphanesini ekliyoruz.


#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
#define Kapa 5
#define Ac 9
dht11 DHT11;

RH_ASK driver;

String rdgelen="1";
//String rdgiden ="2";
String sicaklik ="";
String gitti = "";
int control = 1;
int sentKont=2; //****önemli
int recKont=1;  //****önemli

void setup() {
  
  pinMode(Ac, INPUT);
   pinMode(Kapa, INPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  if (!driver.init()) Serial.println("FHRFOFAA");
  Serial.println("hazır");
  
}

void loop()
{ 
 if (recKont==1) 
  { rfal();
  
  }
   delay(30);
 dugmeKont();
 delay(30);
 gonderici();
 delay(30);
 

}

 void dugmeKont(){
  
 if (digitalRead(Ac))
  {  recKont =2;
     delay(10);
    digitalWrite(LED_BUILTIN, HIGH);
   // rdgonder("THGNL1ON");
     rdgonder("TWOFL1ON");
     delay(100);
  }
  
 if (digitalRead(Kapa))
   { recKont =2;
     delay(10);
     digitalWrite(LED_BUILTIN, LOW);
   // rdgonder("THGNL1OF");
     rdgonder("TWOFL1OF");
      delay(100);
   }

  
 }

  
void rfal()
{    
    uint8_t buf[8];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
      { // Serial.println("Gelen var");
         // int i;
         rdgelen = (char*)buf;
         rdgelen= rdgelen.substring(0,8);

         if (rdgelen.substring(0,2) != "TW")
          {
            sentKont=2;
            return;
         }
         else
          {
            Serial.print("RD GRLRN: "); 
            Serial.println(rdgelen); 
            sentKont= 1;
           }

      delay(1000);
  
      }
    
 }

void gonderici()
{

  if( sentKont == 1) {
    recKont =2;
     delay(10);
     /*
 if (rdgelen == "TWREPORT")
         { 
           isi();
           return;
         }

 
   if (rdgelen == "TWALMONN")
       { 
         secure();
         return;
       }
*/
  if ( rdgelen!= gitti) 
        {
           gitti = rdgelen;
         
         rdgonder(rdgelen);
        }
        


         
  sentKont=2;
   //delay(1000);
  }


  
}


void rdgonder(String rdgiden) //
{
     recKont =2;
     delay(100);
     
  char a[]="bbtt";
  rdgiden.toCharArray(a,9);
  char *msg = a;
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println(msg);
  delay(700);
  /*
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    Serial.println(msg);
    delay(1000);
    */

   recKont =1;
   delay(10);
 }


 void isi()
{

  int chk = DHT11.read(DHT11PIN);
  int bb =DHT11.temperature;
  String baba = String(bb);
  sicaklik = "FHTEMP" + baba;
  rdgonder(sicaklik);

}

 void secure()
{
 // Serial.print("SECURE: ");
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
