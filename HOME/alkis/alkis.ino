
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
{  
   ilkornek();
   if (alks1==0) return;
   delay(10);
   sonornek();
  /* if (fark[2]>10){ isik();
       fark[2]=0;

 }
 */
  if ((alks1==1) && (alks2 == 1)) isik();

 
}

void ilkornek()
{
   ses[1] = analogRead(ssgrs);
// Serial.println(i);
   delay (90);
    
   ses[2] = analogRead(ssgrs);
 //Serial.println(i);
    delay (90);
      
  fark[1] = ses[1] - ses[2];
  if ( fark[1] < 0 ) fark[1] = fark[1] * (-1);
  if (fark[1]>10) {alks1=1;
  
    Serial.println("alkıs1= 1");
    delay(500);
 //  Serial.println(fark[1]);
  }
   //if ((alks1==1) && (alks2==1)) isik();

}
void sonornek()
{
   ses[3] = analogRead(ssgrs);
// Serial.println(i);
   delay (90);
    
   ses[4] = analogRead(ssgrs);
 //Serial.println(i);
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
  
 //  if ((fark[2] == 0) ||(fark[2]==1)) {
   
  //  Serial.print("f= ");
  // Serial.println(fark[1]);
 //   Serial.print("oldu");
  Serial.print("f1= ");
   Serial.println(fark[1]);
   
   Serial.print("f2= ");
   Serial.println(fark[2]);
     
}
/*
if (fark[2]>10){ isik();
   fark[2]=0;
}
//Serial.println(ses[2]);
//delay (100);
  
}

*/
void isik()
 {    Serial.println("ISIK");
   if (lkon==0)  
    { 
        digitalWrite(LED_BUILTIN, HIGH); 
        lkon=1;
     }
  else  
     {
        digitalWrite(LED_BUILTIN, LOW); 
        lkon=0;
      }

  alks1=0;
   alks2=0;
     
 }





 
