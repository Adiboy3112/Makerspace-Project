#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "ksen_jio"; 
const char *password = "123";

const char *server = "http://127.0.0.1:8000/add/create/";

const int lm35_pin = A0; 

void setup() {
  delay(1000);
  pinMode(lm35_pin, INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
}

void loop() {
  WiFiClient wifi_client;
  HTTPClient http;    

  String temp_send, postData;
  
  int temp = analogRead(lm35_pin);  
  temp_send = String(temp);   
  int spo2 = analogRead(lm35_pin);  
  String spo2_send = String(spo2);
  int spo2 = analogRead(lm35_pin);  
  String spo2_send = String(spo2);   
  int pulse = analogRead(lm35_pin);  
  String pulse_send = String(pulse);
  String name;   
   

  //Post Data
  postData += "?spo2=" + spo2_send + "&";
  postData += "temp=" + temp_send + "&";
  postData += "pulse=" + pulse_send + "&";
  postData += "name=" + name +"&Submit=Submit";

  http.begin(wifi_client, server); //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Specify content-type header

  int httpCode = http.POST(postData);   //Send the request

  Serial.println(httpCode);   //Print HTTP return code

  http.end();  //Close connection
  
  delay(5000);  //Post Data at every 5 seconds
}
