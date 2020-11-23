
/************ WORK *************
 *  NODMCU SERVERDEN GELEN BİLGİLERİ RF İLE TÜM CLİNTLARA
 *  VE RF İLE TÜM CLİENTLARDAN GELEN DATALARI MODMCUYA İLETİR
 *  ARDUİNO
 ****************************/





const int titre = 4;

void setup() {
   pinMode(titre,INPUT);
  Serial.begin(115200);

  Serial.println("hazır");
  
}

void loop()
{

 
   int tit = digitalRead(titre);
  
   if (tit==1) { 
    
  Serial.println("FWALMALM");

  //     Serial.println(tit);
            delay(1500);
    //
 }
          


  
 // al(); //from interbet over mcu via serialport

 // rfal(); //from rf
   
}

/*

void al()
{  
  while (Serial.available())
       {
        srgelen= Serial.readString();

        
        if (srgelen.substring(0,2)=="TW")
           {
    // bunu kullanma hemen kapat Serial.println(srgelen);
             rdgonder(srgelen);
            }

        
        }

}
*/

/*
  
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
     //  if (rdgelen == "FHALMALM" && almkon == 1) Serial.println(rdgelen);  
      // if (rdgelen != "FHALMALM") Serial.println(rdgelen);  
       
      //if(rdgelen == "THS1ONAA") digitalWrite(LED_BUILTIN, HIGH);
   
    
    }

}



void rdgonder(String rdgiden) //
{
  //Serial.println(rdgiden);
  char *msg = "FWNNNNNN";
  rdgiden.toCharArray(msg,9);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  //Serial.println(msg);
 // Serial.println("Hello World!");
  delay(10);
 }
 */
