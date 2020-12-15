#include <IRremote.h>


#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
int al = 5;
int sw =2;

IRrecv irrecv(al);
decode_results result;
int deger=1;

void setup() {
  // put your setup code here, to run once:
 pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sw, OUTPUT);
   digitalWrite(sw, LOW);
 digitalWrite(LED_BUILTIN, LOW);
 Serial.begin(115200);
 irrecv.enableIRIn();
 
 Serial.begin(115200);
  if (!driver.init()) Serial.println("FHRFOFAA");
  Serial.println("hazır");
 


}

void loop() {
  // put your main code here, to run repeatedly:

  if(irrecv.decode(&result)) {
    deger = result.value;
    if( deger<0) deger = deger * (-1);
     //Serial.println(deger, HEX);
      Serial.println(deger);
   // if( deger<0) deger = deger* (-1);
    
    
     irrecv.resume();
     
  }

   is();
  
}

void is()
{
 switch (deger) { // compare the value to the following cases
      case 24481: // 1 Tuşu 1 nolu ışık aç
        rdgonder ("THGNL1ON");
        break;
      case 24735: // * Tuşu 1 Nolu Işık kapa
        rdgonder ("THGNL1OF");
        break;
     case 8161: //3 Tuşu 2 Nolu Işık aç
        rdgonder ("THGNL2ON");
        break;
     case 4335: // # tuşu 2 nolu ışık kapa
     rdgonder ("THGNL2OF");
         break;
    //case 0xFF629D: // 2 tuşu abajur aç
      case 16575:
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(sw, HIGH);
        break;
     case 28561: // 0 tuşu abajur kapa
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(sw, LOW);
        break;
     case 16321: // Y ok tuşu Kırmız aş
        rdgonder ("THBHSKON");
        break;
     case 20655: // A Ok tuşu Kırmız kapa
       rdgonder ("THBHSKOF");
        break;
  
     case 8415: // A Ok tuşu Kırmız kapa
       digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(sw, LOW);
      rdgonder ("THGNL1OF");
       r          dgonder ("THGNL2OF");
       rdgonder ("THBHSKOF");
  
      rdgonder ("THBHCSOF");

       
        break;
     case 23461: // Sola tuşu Çeşme Aç
       rdgonder ("THBHCSON");
        break;

     case 9435: // Sağa Tuşu Çeşme kapa
       rdgonder ("THBHCSOF");
        break;
        
     case 10455: // 4 Tuşu ..... Açma
       rdgonder ("THGNS4ON");
        break;
     case 6121: // 7 Tuşu ....... Kapama
        rdgonder ("THGNS4OF");
        break;
     case 22441: // 5 Tuşu ....... Açma
       rdgonder ("THGNS5ON");
        break;

     case 6375: // 8 Tuşu ....... Kapama
       rdgonder ("THGNS5OF");
        break;

     case 26775: // 6 Tuşu ...... Açma
        rdgonder ("THGNS6ON");
        break;
     case 26521: // 9 Tuşu ...... Kapama
       rdgonder ("THGNS6OF");
        break;
     case 2295: // 0 TUŞU ..... AÇMA/KAPAMA
       rdgonder ("THGNOKON");
        break;
 
}
  deger=0X0000;

}



void rdgonder(String rdgiden) //
{
  //Serial.println(rdgiden);
  char *msg = "FHNNNNNN";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
 Serial.println(msg);
  Serial.println("Hello World!");
   
  delay(10);

  
 }
 
