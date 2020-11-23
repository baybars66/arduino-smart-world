/*
   ERDEK SERVER
   
   WebSocketClientSocketIO.ino

*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h>
#include <Hash.h>


char msg[7]="";

String str = "";
String serigelen = "";
String serigiden = "";

String wifigiden = "";
String wifigelen = "";

String txtmi = "";

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;

#define USE_SERIAL Serial1
#define MESSAGE_INTERVAL 30000
#define HEARTBEAT_INTERVAL 25000

uint64_t messageTimestamp = 0;
uint64_t heartbeatTimestamp = 0;
bool isConnected = false;

 
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {


  switch (type) {
     case WStype_DISCONNECTED:
       ///  USE_SERIAL.printf("[WSc] Disconnected!\n");
          isConnected = false;
          break;
      case WStype_CONNECTED:
          {
            //Serial.println ("[nnnnnnnT");
          ///   USE_SERIAL.printf("[WSc] Connected to url: %s\n",  payload);
              isConnected = true;

            // send message to server when Connected
              // socket.io upgrade confirmation message (required)
        webSocket.sendTXT("5");
          }
          break;
   
    case WStype_TEXT:
      {
        // USE_SERIAL.printf("[WSc] get text: %s\n", payload);

        str = String((char*) payload);
        //Serial.println(str);
        delay(50);
        seriyolla(str);
        
      
        
      }
      // send message to server
      // webSocket.sendTXT("message here");
      break;
    case WStype_BIN:
      USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
      hexdump(payload, length);

      // send data to server
      // webSocket.sendBIN(payload, length);
      break;
  //  default: rdal();
   //   break;
  }

}




void setup() {
  
  Serial.begin(115200);

  USE_SERIAL.begin(115200);

  Serial.setDebugOutput(true);
  USE_SERIAL.setDebugOutput(true);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  WiFiMulti.addAP("ERDALM", "Capan66-kablosuz");

  //WiFi.disconnect();
  while (WiFiMulti.run() != WL_CONNECTED) {
  delay(500);
    Serial.print(".");
  }

  webSocket.beginSocketIO("88.250.131.163", 8666);
  //webSocket.setAuthorization("user", "Password"); // HTTP Basic Authorization
  webSocket.onEvent(webSocketEvent);




}

void loop() {

 webSocket.loop();

  if (isConnected) {

    uint64_t now = millis();

    if (now - messageTimestamp > MESSAGE_INTERVAL) {
      messageTimestamp = now;
      // example socket.io message with type "messageType" and JSON payload
      // webSocket.sendTXT("42[\"messageType\",{\"greeting\":\"hello\"}]");
      //webSocket.sendTXT("42[\"chat message\",\"merhaba\"]");
    
    }
    if ((now - heartbeatTimestamp) > HEARTBEAT_INTERVAL) {
      heartbeatTimestamp = now;
      // socket.io heartbeat message
      webSocket.sendTXT("2");
    }
  }


serial();


}

 void serial()
 {
   while (Serial.available())
        { 
          serigelen = Serial.readString();
          //Serial.println(serigelen);
          if ( serigelen.substring(0,2)=="FE")
             {
                serigelen = serigelen.substring(0,8);
                serigelen= "\"" + serigelen+ "\"";
             // webSocket.sendTXT("42[\"chat message\",\"merhaba\"]");
                serigelen = "42[\"chat message\", " +serigelen+"]";
               // Serial.println(serigelen);
                webSocket.sendTXT(serigelen);
                }
          }


}


void seriyolla( String serigiden)
{//Serial.print("HTALAL");

  int uzunluk = serigiden.length();
  uzunluk=uzunluk - 2;
  txtmi = serigiden.substring(0,2);
  if (txtmi=="42") serigiden=serigiden.substring (19, uzunluk);

 // Serial.println(serigiden);

  if(serigiden.substring(0,2) == "TE") 
    { Serial.println(serigiden);
 //  Serial.println("bababva");

   
   }
 if(serigiden.substring(0,2) == "TA") 
    { Serial.println(serigiden);
 //  Serial.println("bababva");

    }
  str="";
}

/*
void posta(String note)
{
    
  wifigiden = "\"" + note + "\"";
    // webSocket.sendTXT("42[\"chat message\",\"merhaba\"]");
   wifigiden = "42[\"chat message\", " + wifigiden + "]";
   // Serial.println(wifigiden);
    webSocket.sendTXT(wifigiden);

}
*/
