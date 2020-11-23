//EV alıcı



#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;
const int isik=A4;

const int gecelam=4;
const int cesme=6;
 
void setup()
{
  pinMode(isik,INPUT);
  pinMode(gecelam,OUTPUT);
  pinMode(cesme,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");


     Serial.println("hazır");     
}

void loop()
{
int durum= digitalRead(LED_BUILTIN);
   int aydinlik = analogRead(isik);
   if (aydinlik >=550 && durum == HIGH) 
      { 
             
             digitalWrite(gecelam, HIGH);
             
             }
   //  if (aydinlik <=550)  digitalWrite(gecelam, LOW);
   else digitalWrite(gecelam, LOW);
    rfal();
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
  Serial.println(rdgelen);  
    if(rdgelen == "THBHSKON") digitalWrite(LED_BUILTIN, HIGH);
    if(rdgelen == "THBHCSON") digitalWrite(cesme, HIGH);
    if(rdgelen == "THBHSKOF") digitalWrite(LED_BUILTIN, LOW);
    if(rdgelen == "THBHCSOF") digitalWrite(cesme, LOW);
   // if(rdgelen == "THS1ONAA") digitalWrite(cesme, HIGH);
   
    
    }

}
/*

#include <VirtualWire.h>
#include <Wire.h>
//#include <SPI.h>
const int receive_pin = 10;
String rdgelen="nn";

  
void setup() {
  
 pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  //mcu.begin(115200);
// Initialise the IO and ISR
vw_set_rx_pin(receive_pin);
vw_set_ptt_inverted(true); // Required for DR3100
    
    vw_setup(500);   // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
  Serial.println("hazır");
  
}
void loop() {

   rdal();

 
}





}
  /*
 void gonder ()
{
   // Bu fonksiyona serial print koyma delaylarla oynama
   delay(5);
   radio.stopListening();
   const char msg[] ="YTKYBN";
   radio.write(&msg, sizeof(msg));
   delay (1000);
  
}   

*/

   
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
       
       /*
   while (Serial.available()){    
   
      serigelen = Serial.readString();
      blu.println(serigelen);
     
    
   }
 */
    








/*
void rdgonder (String giden)
{
    char msg[7]="";
    giden.toCharArray(msg,7);
    delay(5);
    radio.stopListening();
      Serial.println (msg);
    radio.write(&msg, sizeof(msg));

       
    Serial.println ("gitti");
   
    //delay (1400);
    delay(10);

}

*/


/*
 void durum(){

if (digitalRead(lam) == HIGH)   lamba= "LAMBA YANYO" ; 
  if (digitalRead(lam) == LOW )lamba= "LAMBA SONUK" ;
 if (digitalRead(LED_BUILTIN) == HIGH)  almdrm = "ALARM ACIK" ; 
  if (digitalRead(LED_BUILTIN) == LOW)  almdrm = "ALARM KAPA" ;
 // Serial.println(lamba);
  
  // isi=rtc.getTemp();
  int isi = dht.readTemperature();
  int volt = analogRead(vin);
  double voltaj = map ( volt, 0, 1023, 0,2500) + offset;

  voltaj /= 100;

   
 
    msg= String( voltaj,2);
    msg = "v "+ msg + " " + lamba + " " + isi +  " " + almdrm;
    Serial.println(msg);
    blu.println(msg);
   


  
}
    
 */
