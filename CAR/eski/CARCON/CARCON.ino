
/************ CAR *************
 *  NODMCU SERVERDEN GELEN BİLGİLERİ RF İLE TÜM CLİNTLARA
 *  VE RF İLE TÜM CLİENTLARDAN GELEN DATALARI MODMCUYA İLETİR
 *  ARDUİNO
 ****************************/


const int vin = A1;
const int titre = 2;
int volt =1;
int almkon =1;
int voltkon = 1;

String srgelen="";
String srgiden ="";

void setup() {
  
   pinMode(titre,INPUT);
   pinMode(vin,INPUT);
 
  Serial.begin(115200);

  Serial.println("hazır");
}

void loop()
{

 salla();
 
 al(); //from interbet over mcu via serialport
 
 // rfal(); //from rf
   

}


void al()
{  
  while (Serial.available())
       {
         srgelen= Serial.readString();
         if (srgelen.substring(0,2)=="TC")
           {
              // bunu kullanma hemen kapat Serial.println(srgelen);
             //rdgonder(srgelen);
            }
       if (srgelen.substring(0,8)=="TCALMONN") voltkon = 1;
       if (srgelen.substring(0,8)=="TCREPORT") voltolc();
        }

}



void salla()
{
  int tit = digitalRead(titre);
   
  if (tit==0) 
    { 
       Serial.println("FCALMALM");
       delay(1500);
     }
  
}


 void voltolc()
 {  
        
   volt = analogRead(vin);
  // double voltaj = map ( volt, 0, 1023, 0,2500) + offset;
  double voltaj = map ( volt, 0, 1023, 0, 1600);
  voltaj /= 100; 
  srgiden= String( voltaj);
  srgiden = "FCREPVLT" + srgiden;
  Serial.println (srgiden);

  if(voltaj <= 11.6 ) {
   
    if (voltkon ==1 ){ Serial.println ("FCPOWALM");  
         voltkon=2;
    }
 
  }
 }



 
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
