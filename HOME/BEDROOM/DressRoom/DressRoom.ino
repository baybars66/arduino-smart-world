//EV BEDROOM DRESSROOM HAREKENT ISI DUMAN SENSÖRÜ 

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.

#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
#define Buton 7

dht11 DHT11;
RH_ASK driver;



const int gir=A6;  
String rdgiden ="";
int duman = 1;


void setup()
{
  
  pinMode(Buton, INPUT);
   pinMode(gir,INPUT);
   Serial.begin(115200);    // Debugging only

   if (!driver.init())
        Serial.println("init failed");
    Serial.println("hazır");

       
         
}


void loop()
{
  hareket();
  isi();
  smoke();


}

void hareket()
{
   int yaban = analogRead(gir);
//  Serial.println(yaban);
   if (yaban>=550 )
      { 
        rdgonder("FHPIRALM") ;
        delay (10000); //3000 iyi
    
         } 
}


void smoke()
{
   duman = analogRead(Buton);
   //Serial.println(duman);
  if (duman > 450) {  rdgonder("FHDUMANN");
   
  delay(10000);

  }
}


 void isi()
{

  int chk = DHT11.read(DHT11PIN);
 int bb =DHT11.temperature;
  String baba = String(bb);
  if(bb>35) {
//String sicaklik = "FHTEMP" + baba;
 // Serial.println(sicaklik);
   rdgonder("FHISIALM");
   delay(10000);
  }


}



void rdgonder(String rdgiden)
//void rdgonder()
{
  //Serial.println(rdgiden);
  char *msg = "FHALMALM";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println(msg);
  delay(10);
 }
