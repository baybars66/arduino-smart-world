//Initializing LED Pin
int led_pin = 5;
int sure = 0;
int voltaj = 0;

void setup() {

  pinMode(led_pin, OUTPUT);

}

void loop() {
 yak(10, 100);

  yak(60, 200);
 yak(10, 100);



}

void yak(int min, int max)
{
 // put your main code here, to run repeatedly:
  voltaj = random(min, max);
  if (voltaj<16)  sure = random (200,400);
  if (voltaj>15)  sure = random (100,140);//300
   if (voltaj>50)  sure = random (90,120);//300
     if (voltaj>70)  sure = random (100,150);
    // if (voltaj>80)  sure = random (50,100);//400
   if (voltaj>90)  sure = random (90, 150); 
    if (voltaj>140)  sure = random (800, 7000); 
    if (voltaj>150)  sure = random (1000, 5000);  
      if (voltaj>180)  sure = random (1000,12000);   
   analogWrite (led_pin, voltaj);
    delay (sure);


}
