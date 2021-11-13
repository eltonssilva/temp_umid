
void sensor(){

  temp = dht.readTemperature();
  umid = dht.readHumidity();

  Serial.print("Temp = ");
  Serial.println( temp );

  Serial.print("Umid = ");
  Serial.println( umid );

 if(isnan(temp) || isnan(umid)){
  return;
 }

  mqttClient.publish( MQTT_PUB_TEMP, 1, true,  String(temp).c_str() );
  mqttClient.publish( MQTT_PUB_HUM, 1, true,  String(umid).c_str() );

  }
  



//Valor 0: não confiável, a mensagem é entregue no máximo uma única vez, se o cliente estiver indisponível no momento, ele perderá a mensagem.
//Valor 1: a mensagem deve ser entregue pelo menos uma vez.
//Valor 2: a mensagem deve ser entregue exatamente uma vez.
