#include "DHT.h"
#include <ESP8266WiFi.h>
#include <AsyncMqttClient.h>
#include <Ticker.h>


#define WIFI_SSID           "AGUIAR_ADM"
#define WIFI_PASSWORD       "a0b9c8d7e6"

#define MQTT_HOST           "mqtt.autodomo.io"
#define MQTT_PORT           1883

const char* USER_MQTT       = "User000001075";
const char* PASSWORD_MQTT   = "upfkk9ym";
#define ID_MQTT             "02AA34A502BB"

#define MQTT_PUB_TEMP       "/autodomo/User000001075/03AA5E75B8CD/temperature/state"
#define MQTT_PUB_HUM        "/autodomo/User000001075/02AA34A502BB/humidity/state"


// Pino de Dados do DHT11
#define DHTPIN 2 

// Defino qual o tipo de DTH  dht11/dht22
#define DHTTYPE DHT11 


// LIGAR O SENSOR
DHT dht(DHTPIN, DHTTYPE);

float temp;
float umid;


AsyncMqttClient mqttClient;
Ticker wifiReconnectTimer;
Ticker mqttReconnectTimer;


WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;

unsigned long tempoAnterior = 0;
const long    intervalo     = 10000;

void setup() {
  // put your setup code here, to run once:
  initParametros();
  wifiInit();
  connectToWifi();
  mqttInit();

}

void loop() {
  // put your main code here, to run repeatedly:
   unsigned long tempoAtualMillis = millis();

  if(tempoAtualMillis - tempoAnterior >= intervalo){
    tempoAnterior = tempoAtualMillis;
    
    sensor();
    
  }

}
