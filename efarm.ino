#include <"ESP8266WiFi.h">
#include <<span class="TextRun Highlight BCX0 SCXW174472232" lang="EN-US" xml:lang="EN-US" data-contrast="auto"><span class="SpellingError BCX0 SCXW174472232">FirebaseArduino.h></span></span>


#define FIREBASE_HOST "YOUR HOSTNAME HERE" 
#define FIREBASE_AUTH "DATABASE SECRET HERE"
#define WIFI_SSID "YOUR WIFI SSID HERE" 
#define WIFI_PASSWORD "YOUR WIFI PASSWORD HERE" 


void setup() { 
 Serial.begin(9600); 

 WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
 Serial.print("connecting"); 
 while (WiFi.status() != WL_CONNECTED) { 
   Serial.print("."); 
   delay(500); 
 } 
 Serial.println(); 
 Serial.print("connected: "); 
 Serial.println(WiFi.localIP()); 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
} 
int n = 0;

 
void loop() { 

 Firebase.setFloat("number", 42.0); 

 if (Firebase.failed()) { 
     Serial.print("setting /number failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000); 
 

 Firebase.setFloat("number", 43.0); 
 
 
 if (Firebase.failed()) { 
     Serial.print("setting /number failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000);
  
 
 Serial.print("number: "); 
 Serial.println(Firebase.getFloat("number")); 
 delay(1000); 
 
 
 Firebase.remove("number"); 
 delay(1000); 
 

 Firebase.setString("message", "hello world"); 

 if (Firebase.failed()) { 
     Serial.print("setting /message failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000); 
 
 
 Firebase.setBool("truth", false); 
 
 
 if (Firebase.failed()) { 
     Serial.print("setting /truth failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000); 

 
 String name = Firebase.pushInt("logs", n++); 
 

 if (Firebase.failed()) { 
     Serial.print("pushing /logs failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 Serial.print("pushed: /logs/"); 
 Serial.println(name); 
 delay(1000); 
}
