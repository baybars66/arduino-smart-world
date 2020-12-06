

#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.

dht11 DHT11;

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

//char *controller;


 
 int ssgrs = 0;
 int lkon = 0;
 int alks1 = 0;
 int alks2 = 0;
 int sayi[4] = {1,3,5,7};
 int ses[4] = {1,3,5,7};
 int fark[2] = {1,3};

 
void setup() {
  
   pinMode(ssgrs,INPUT);
   pinMode(LED_BUILTIN, OUTPUT);
   
   Serial.begin(115200);
   Serial.println("hazır");
  
}

void loop()
{  // isi();
   ilkornek();
   if (alks1==0) return;
   delay(10);
   sonornek();
  
  if ((alks1==1) && (alks2 == 1)) isik();

 
}

void ilkornek()
{
   ses[1] = analogRead(ssgrs);
   delay (90);
   ses[2] = analogRead(ssgrs);
   delay (90);
      
  fark[1] = ses[1] - ses[2];
  if ( fark[1] < 0 ) fark[1] = fark[1] * (-1);
  if (fark[1]>10) {alks1=1;
  
    Serial.println("alkıs1= 1");
    delay(500);
 //  Serial.println(fark[1]);
  }
  

}
void sonornek()
{
   ses[3] = analogRead(ssgrs);
   delay (90);
    
   ses[4] = analogRead(ssgrs);
   delay (90);
      
  fark[2] = ses[3] - ses[4];
  if ( fark[2] < 0 ) fark[2] = fark[2] * (-1);

  if (fark[2]>3) { alks2=1;
Serial.println("alkıs2= 1");
  }
  else { alks1=0;
   alks2=0;
   Serial.println("alkıs1 2 = 0 0 ");
  }
   
  Serial.print("f1= ");
   Serial.println(fark[1]);
   
   Serial.print("f2= ");
   Serial.println(fark[2]);
     
}



void isik()
 {    Serial.println("ISIK");
   if (lkon==0)  
    { 
        digitalWrite(LED_BUILTIN, HIGH); 
       // rdgonder ("THBDL1ON");

        
        lkon=1;
     }
  else  
     {
        digitalWrite(LED_BUILTIN, LOW); 
        // rdgonder ("THBDL1OF");
        lkon=0;
      }

  alks1=0;
  alks2=0;
     
 }



void isi()
{
  // Serial.println();
  // Sensörün okunup okunmadığını konrol ediyoruz. 
  // chk 0 ise sorunsuz okunuyor demektir. Sorun yaşarsanız
  // chk değerini serial monitörde yazdırıp kontrol edebilirsiniz.
 // int chk = DHT11.read(DHT11PIN);
//  Serial.print("CHK: ");
 // Serial.println(chk);
  // Sensörden gelen verileri serial monitörde yazdırıyoruz.
//  Serial.print("Nem (%): ");
//  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);
/*
  Serial.print("Sicaklik (Fahrenheit): ");
  Serial.println(DHT11.fahrenheit(), 2);

  Serial.print("Sicaklik (Kelvin): ");
  Serial.println(DHT11.kelvin(), 2);

  // Çiğ Oluşma Noktası, Dew Point
  Serial.print("Cig Olusma Noktasi: ");
  Serial.println(DHT11.dewPoint(), 2);

  // 2 saniye bekliyoruz. 2 saniyede bir veriler ekrana yazdırılacak.
  delay(2000);
  */
}




void rdgonder(String rdgiden) //
{
  //Serial.println(rdgiden);
  char *msg = "FHNNNNNN";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
 Serial.println(msg);
 // Serial.println("Hello World!");
  delay(10);
 }
 


 
