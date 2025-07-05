#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "SPIFFS.h"

const char* ssid = "YOUR_WIFI_SSID";               // 🔁 Replace this
const char* password = "YOUR_WIFI_PASSWORD";       // 🔁 Replace this

const char* aws_endpoint = "YOUR_ENDPOINT.iot.YOUR_REGION.amazonaws.com";  // 🔁 Replace this
const char* thingName = "Newthing";  // ✅ Your actual thing name

WiFiClientSecure net;
PubSubClient client(net);

// Load certificates from SPIFFS
void loadCerts() {
  File cert = SPIFFS.open("/certificate.pem.crt", "r");
  File key = SPIFFS.open("/private.pem.key", "r");
  File ca = SPIFFS.open("/AmazonRootCA1.pem", "r");

  if (!cert || !key || !ca) {
    Serial.println("❌ Failed to open one or more certificate files");
    return;
  }

  net.setCertificate(cert.readString().c_str());
  net.setPrivateKey(key.readString().c_str());
  net.setCACert(ca.readString().c_str());

  cert.close();
  key.close();
  ca.close();
}

void connectToAWS() {
  while (!client.connected()) {
    Serial.print("🔁 Connecting to AWS IoT... ");
    if (client.connect(thingName)) {
      Serial.println("✅ Connected!");
      client.publish("esp32/status", "ESP32 is online");
    } else {
      Serial.print("❌ Failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("🔌 Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi Connected");

  if (!SPIFFS.begin(true)) {
    Serial.println("❌ SPIFFS failed");
    return;
  }

  loadCerts();
  client.setServer(aws_endpoint, 8883);
}

void loop() {
  if (!client.connected()) {
    connectToAWS();
  }
  client.loop();
}
