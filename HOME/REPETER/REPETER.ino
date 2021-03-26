
/************ HOME REPETER*************
 *  ÖN BAHÇEYE ULAŞMAYAN RF SINYALINI ALIP TEKRAR YOLLAMA
 *  AYRICA L1 LAMBASINI MANUEL YAKMA VE REPORT SORULDUĞUNDA
 *  ORTAM SICAKLIGINI İLETME
  ****************************/
  
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.

#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
#define Kapa 9
#define Ac 5

dht11 DHT11;

RH_ASK driver;

char *rdgelen;
String metin = "";
char *msg = "FHBASLAA"; 
char *btnmsg = "FHBASLAA"; 
String gitti= "";
String btngitti= "";

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
  
 rfal();
 
 dugmeKont();


}



  
void rfal()
{   
    char rfgiden[8]; 
    uint8_t buf[8];
    uint8_t buflen = sizeof(buf);
    
    if (driver.recv(buf, &buflen)) // Non-blocking
      {  
         rdgelen = (char*)buf;
         metin = rdgelen;
         metin = metin.substring(0,8);
         Serial.print("metin : ");
         Serial.println(metin);
         if(  metin.substring(0,2) != "TH") return ;
         metin.toCharArray(msg, 9);

       if (metin == "THREPORT") {
        isi();
        return;
       }
       
       if (metin == "THALMONN") {
        secure();
        return;
       }
       if (metin.substring(0,2) == "TH") rdgonder();
             
   
        delay(1000);
  
      }
    
 }



 void isi()
{

 int chk = DHT11.read(DHT11PIN);
 int bb =DHT11.temperature;
 
 String baba = "FHTEMP" +String(bb);
 baba.toCharArray(msg, 9);
 rdgonder();

}


 void secure()
{
 // Serial.print("SECURE: ");
 digitalWrite(LED_BUILTIN, LOW);
 
 msg="THGNL1OF";
 rdgonder();
 delay (10);
 msg = "THGNL2OF";
 rdgonder();
 delay (10);
 msg = "THBHSKOF";
 rdgonder();
 delay (10);
 msg = "THLRNLOF";
 rdgonder();
 delay (10);
 msg = "THBHCSOF";
 rdgonder();
 delay (10);


}



 void dugmeKont()
{ 
   if (digitalRead(Kapa)) 
    {
      btngitti= String( random(6000, 10000));
      Serial.println("Kapada ");
     btnmsg ="THGNL1OF";
     delay(20);
     Serial.print("msgkapada : ");
  Serial.println(btnmsg);
     btnrdgonder();
     delay(10);
   }
   if (digitalRead(Ac))
   {
    Serial.println("Acta");
    btngitti= String( random(1, 5000));
    btnmsg = "THGNL1ON";
    delay(20);
    Serial.print("msgActa : ");
  Serial.println(btnmsg);
    btnrdgonder();
    delay(10);
  
 }

}

 
void rdgonder() 

{  
  
  Serial.print("msg : ");
  Serial.println(msg);
  
  if (gitti== msg){
   Serial.print("buuuu");
  return;
}
  else{
    
  
  
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  //Serial.print("Giden msg : ");
 // Serial.println(msg);
  delay(300);
/*
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
 // Serial.print("Giden msg : ");
  //Serial.println(msg);
  delay(500);
  */
  gitti = msg;
  }
 }



  
void btnrdgonder() 

{  
  
  Serial.print("msg : ");
  Serial.println(btnmsg);
  
  if (btngitti== btnmsg){
   Serial.print("buuuu");
  return;
}
  else{
    
  driver.send((uint8_t *)btnmsg, strlen(btnmsg));
  driver.waitPacketSent();
  //Serial.print("Giden msg : ");
 // Serial.println(msg);
  delay(300);

 btngitti = btnmsg;
  }
 }
