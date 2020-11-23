//EV HAREKEN SENSÖRÜ


#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

const int gir=A6;  
 
String rdgiden ="";





void setup()
{
   pinMode(gir,INPUT);
    Serial.begin(115200);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");

   Serial.println("hazır");
         
}

void loop()
{
   int yaban = analogRead(gir);
 
  if (yaban>=550 )
 
         { 
         
            rdgonder() ;
        
           delay (3000); //3000 iyi
    
         } 


}


//void rdgonder(String rdgiden)
void rdgonder()
{
  //Serial.println(rdgiden);
  char *msg = "FEALMALM";
  //rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println(msg);
    delay(10);
 }
  


   
 /*
  
void mcual() 
{  

  
   while (mcu.available()){
   Serial.println("GELEN VAR"); 
   blgelen=  mcu.readString(); 
   uzunluk= blgelen.length(); 
   uzunluk=uzunluk- 3;
   txtmi = blgelen.substring (0 ,2);
   if (txtmi=="42") blgelen=blgelen.substring (18, uzunluk);
   
   
   Serial.println(blgelen); 
     
   }     
 
 */
    
  
