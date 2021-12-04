void connectToMqtt(){
  Serial.println("Conectando para o MQTT");
  mqttClient.connect();
}

void onMqttConnect(bool sessionPresent){
  Serial.println("Conectado no MQTT...");
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason){
  Serial.println("Disconectado no MQTT...");

  if(WiFi.isConnected()){
    mqttReconnectTimer.once(2, connectToMqtt);
  }
  
}


void mqttInit(){
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCredentials(USER_MQTT, PASSWORD_MQTT);
  mqttClient.setClientId(ID_MQTT);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
}
