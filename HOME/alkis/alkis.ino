
 int ssgrs = 0;
 int lkon = 0;
 int alks1 = 0;
 int say2 = 0;
 int ses1 = 1;
 int ses2 = 1;
 int ses3 = 1;
 int say = 0;
 int fark = 0;

void setup() {
  
   pinMode(ssgrs,INPUT);
   pinMode(LED_BUILTIN, OUTPUT);
   
   Serial.begin(115200);
   Serial.println("hazır");
  
}

void loop()
{  

  do {
    say = say + 1;   
 
} while (say2 < 2);


  
   say = say+1 ;
    if (say==1)   ses1 = analogRead(ssgrs);
    if (say==2)  { ses2 = analogRead(ssgrs);
     say=1;
    }

     fark = ses2-ses1;
   if ((fark >= 40 ) && (fark <=70 ))  {  
      //pinMode(ssgrs,OUTPUT);
     delay(500);
       //pinMode(ssgrs,INPUT);
    //  ses3 = analogRead(ssgrs);
     // fark = ses3-ses2;
     Serial.println(fark);
  dene();
      
   
    

   // delay(130);
    }


    
 }




void dene()
{
   say2 = 0;
do {
    say2 = say2 + 1;   
 
} while (say2 < 15);

   Serial.println(say2);
  //if (alks2== 0) alks2=1;
  if (alks1== 1) {
    isik(); 
    return;
  } 
  if (alks1== 0) alks1=1; 
 
}



void isik()
 {
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
  
    Serial.println(alks1); 
 
  delay(100);
   
 }
 /*
  Serial.println(tit);
  Serial.println(alks1); 
  Serial.println(alks2);

  if(alks1==1) alks2=alks2+1;
  if (alks2==15) {alks1=0; alks2=0;}
 
 // if (tit < 750 || tit  > 760  )  alks();
 // if (tit ==755 ) return;
  //if ( tit==754 )  return;
  //if ( tit==753 )  return;
  //if ( tit==756 )  return;
  //delay(2000);

*/
 
