
 int ssgrs = 0;
 int lkon = 0;
 int alks1 = 0;
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
  
  
  ornek(1);
  delay(60);
  ornek(2);




  
  /*
    say1 = 0;
   
   do {
        say1 = say1 + 1;   
        ses1 = analogRead(ssgrs);
       // delay (10);
         ses2 = analogRead(ssgrs);
        delay (30);
         ses3 = analogRead(ssgrs);
      //  delay (10);
         ses4  = analogRead(ssgrs);
      //  delay (10);
               
       } while (say1 < 4);

 fark1 = ses1 - ses2;
 if (fark1 < 0) fark1 = fark1 * (-1);
 fark2=ses3 - ses4 ;
if (fark2 < 0) fark2 = fark2 * (-1);

if (fark1 > 1) { 
    Serial.println("Fark1 : ");
     Serial.println(fark1);
}

if (fark2 > 1) { 
    Serial.println("Fark2 : ");
     Serial.println(fark2);
}
 */
 //Serial.println(ses3);
 
 //Serial.println(ses4);
 
 
    //delay(100);
    /*
    
    say = say + 1;   
   
    if (say==1)   ses1 = analogRead(ssgrs);
    
    if (say==2)  
       { ses2 = analogRead(ssgrs);
          say=0;
        }

     fark 1 = ses2-ses1;

     say3 = 0;
   
   do {
        say3 = say3 + 1;   
 
       } while (say3 < 15);

 
      
    }
    if ((fark >= 40 ) && (fark <=70 ))
       {        
         delay(500);
         Serial.println(fark);
         dene();
       }


*/
}


void ornek(int j)
{


    int i = j;
 do {


        
        ses[i] = analogRead(ssgrs);
       // Serial.println(i);
        delay (90);
        i = i + 1;  
        
         ses[i] = analogRead(ssgrs);
      //    Serial.println(i);
       delay (90);
      
               
       } while (i < j+1);

  fark[i-1] = ses[i] - ses[i-1];
  if ( fark[i-1] < 0 ) fark[i-1] = fark[i-1] * (-1);
  

  
*/
//Serial.println(fark[i-1]);
if (fark[i-1] > 1) { 
int a= i-1;


    Serial.println(a);
     Serial.println(fark[i-1]);
     delay (100);
}
//Serial.println(ses[2]);
//delay (100);
  
}



void yeniden()
{
      for(int a= 0;a < 15; a++)
{

}

if ((fark[1] > 1) && (fark[2] == 0) fark[1]=0;


}





/*
void dene()
{
   say3 = 0;
   
   do {
        say3 = say3 + 1;   
 
       } while (say3 < 15);

   if (alks1== 1) 
      {
        isik(); 
        return;
        } 
 
   if (alks1== 0) alks1=1; 
 
}

*/

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
  
     
 }
 
