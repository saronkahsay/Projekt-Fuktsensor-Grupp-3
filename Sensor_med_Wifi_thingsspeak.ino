#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// ----- WiFi -----
const char* ssid = "MDU_guest";
const char* password = "Frozen202512";

// ----- ThingSpeak -----
const char* host = "api.thingspeak.com";
String writeAPIKey = "7X8A4LJPCJDCLAGR";

// ----- Sensor calibration -----
const int dry = 1024;   // sensor value in dry air/soil
const int wet = 0;   // sensor value in water / fully wet soil

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int sensorVal = analogRead(A0);

  // Convert to percentage (wet = 100%, dry = 0%)
  int humidityPercent = map(sensorVal, wet, dry, 100, 0);
  humidityPercent = constrain(humidityPercent, 0, 100);

  Serial.print("Soil moisture: ");
  Serial.print(humidityPercent);
  Serial.println("%");

  // ----- Send to ThingSpeak -----
  WiFiClient client;
  const int httpPort = 80;

  if (!client.connect(host, httpPort)) {
    Serial.println("⚠️ Connection to ThingSpeak failed");
  } else {
    String url = "/update?api_key=" + writeAPIKey + "&field1=" + String(humidityPercent);
    Serial.println(url);

    Serial.print("Requesting URL: ");
    Serial.println(url);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

    delay(500); // give server time
    while(client.available()) {
      String line = client.readStringUntil('\n');
      Serial.println(line);
    }

    Serial.println("Data sent to ThingSpeak!");
  }

  // ThingSpeak allows 1 update every 15 seconds minimum
  delay(15000);
}
