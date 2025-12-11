#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "MDU-guest";
const char* password = "Frozen202512";

// Replace with the IP of your Mosquitto server (not "localhost")
// IP-adressen till onlineserver
const char* mqtt_server = "77.42.37.48";   
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

const int dry = 1024; // value for dry sensor
const int wet = 0; // value for wet sensor

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    if (client.connect("ESP8266_SoilSensor")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}

void setup() { 
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int sensorVal = analogRead(A0);
  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);

  char payload[10];
  snprintf(payload, sizeof(payload), "%d", percentageHumidity);

  client.publish("grupp3/soil/humidity", payload);

  Serial.print("Sent: ");
  Serial.print(payload);
  Serial.println("%");

  delay(1000);
}
