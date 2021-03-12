/************************
Bu Program Eve Tuş takımı ile girmek için yazıldı
Tuş takımını soldan saga 1234567 uçları arduino digital 5431678 uçlarına 
Buzzer D10 ucuna
Oled SCA A4 SCL ise A5 uclarına ( Bunlar sabit değişmez)
RF D12 ucuna ( Sender değişmez)



*/
#include <RH_ASK.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
Adafruit_SSD1306 display(-1);

#include <Keypad.h>

RH_ASK driver;
String ekran="";
int say=0;
int hatacount=0;
int buzz=10;
int zaman=0;
const byte SATIR = 4;
const byte SUTUN= 3;
char keys[SATIR][SUTUN] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[SATIR] = { 5, 4, 3, 2 };
byte colPins[SUTUN] = { 6, 7, 8 };
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, SATIR, SUTUN );
void setup()
{
    if (!driver.init())
        Serial.println("init failed");
    Serial.println("hazır");

  // Oledimizin I2C adresi 0x3C
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

// Tampon Bellek sıfırlama
display.clearDisplay();

//Serial.begin(115200);
pinMode(A0, OUTPUT);
pinMode(buzz, OUTPUT);
Serial.println("hazır");
display.clearDisplay();
display.setTextSize(3);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("WELCOME");
display.display();
delay(200);



}
void loop()
{  char key = kpd.getKey();
   if(key){
    zaman=0;
    cal(50);
     // Serial.println(key);

      ekran = String(ekran + key);
      yaz(ekran);
      say=say+1;
        if (say==6)
         {
            if(ekran=="120212")
               {
                 rdgonder("TWOFL1OF");
                 hatacount=0;
                 yaz("BYE BYE");
                 cal(50);
                 delay(100);
                 cal(50);
                 delay(100);
                  cal(50);
                 delay(100);
                 cal(300);
                 delay(100);
                 cal(50);
                 delay(100);
                 cal(50);
                  ekran="";
             say=0;
                 return;
               }
          
            if(ekran=="668066")
               {
                 yaz("EVE GIR");
                 cal(500);
                 rdgonder("TWOFL1ON");
                 hatacount=0;
                 
               }
            if(ekran!="668066")
             {
              hatakont();
             }
         ekran="";
             say=0;
          }
    }

  else{
    zaman=zaman+1;
    if(zaman==500){
      yaz ("WELCOME");
      zaman=0;
    }
  }
delay(15);
}



void yaz(String rakam)
{
display.clearDisplay();
display.setTextSize(3);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println(rakam);
display.display();
delay(200);


}

void cal(int zaman)
{
digitalWrite(buzz, HIGH);
delay(zaman);

digitalWrite(buzz, LOW);

}


void hatakont()
{
  yaz("HATA");
  cal(50);
  delay(10);
  cal(50);
  delay(10);
  cal(50);
  hatacount=hatacount+1;
  if (hatacount==3){ yaz("****");
   rdgonder("TWOFL1OF");
     hatacount=0;
  }
  
}



void rdgonder(String rdgiden)
{
  //Serial.println(rdgiden);
  char *msg = "FHALMALM";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println(msg);
  delay(1000);

 }
