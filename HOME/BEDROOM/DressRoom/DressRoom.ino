//EV BEDROOM DRESSROOM HAREKENT ISI DUMAN SENSÖRÜ

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.

#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
#define Buton 7

dht11 DHT11;

RH_ASK driver;

const int gir=A6;  
int duman = 1;
char *msg = "FHDUMANN";

void setup()
{
 
   pinMode(Buton, INPUT);
   pinMode(gir, INPUT);
   Serial.begin(115200);    // Debugging only

   if (!driver.init()) Serial.println("init failed");
   digitalWrite(duman, LOW);
   Serial.println("hazır");

}


void loop()
{
  smoke();
  hareket();
  isi();


}


void smoke()
{
   duman = analogRead(Buton);
  // Serial.println(duman);
   if (duman > 550)
    {  
      rdgonder(1);
     
      delay(10000);

    }
}

void hareket()
{
   int yaban = analogRead(gir);
   //Serial.println(yaban);
   if (yaban>=550 )
     {  
       rdgonder(2);
     
       delay (10000);
     }
}





 void isi()
{
  int chk = DHT11.read(DHT11PIN);
  int bb =DHT11.temperature;
  String baba = String(bb);
  if(bb>35)
   {
    //String sicaklik = "FHTEMP" + baba;
    // Serial.println(sicaklik);
    rdgonder(3);
   
   
   delay(10000);
  }


}

 




void rdgonder(int rdgiden)
{  
 msg = "FHALMALM";
driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println(msg);
  delay(1000);


 
  switch (rdgiden) {
  case 1:
   msg= "FHDUMANN";
    break;
  case 2:
    msg= "FHPIRALM";
    break;
     case 3:
    msg= "FHISIALM";
    break;
  default:
    msg= "FHALMALM";
    break;
}
 

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println(msg);
  delay(500);

   

 
}
