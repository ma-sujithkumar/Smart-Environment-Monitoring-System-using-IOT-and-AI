#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
// Including library of DHT11 temperature and humidity sensor
#include "DHT.h" 
#define DHTTYPE DHT11   // DHT 11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 
// Network SSID 
const char* ssid = "Redmi 2";  
// Network Password
const char* password ="******";  
WiFiClient client;
// Channel Number 
unsigned long myChannelNumber = 1346212; 
//Write API Key
const char * myWriteAPIKey = "OQWDX032UM0RDNRJ"; 


void setup()
{
dht.begin();
Serial.begin(9600);

delay(10);
// Connect to WiFi network
WiFi.begin(ssid, password);
ThingSpeak.begin(client);
}

void loop()
{
float h = dht.readHumidity();
float t = dht.readTemperature();
    
//Read Analog values and Store in variable
Serial.print("Current humidity = ");
Serial.print(h);
Serial.print("%  ");
Serial.print("temperature = ");
Serial.print(t); 
Serial.println("C  "); //Print on Serial Monitor
delay(100);

//Update in ThingSpeak
ThingSpeak.writeField(myChannelNumber,1,t,myWriteAPIKey);	
ThingSpeak.writeField(myChannelNumber, 2,h, myWriteAPIKey);
delay(100);
