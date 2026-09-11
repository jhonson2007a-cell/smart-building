#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// --- WiFi & MQTT Credentials ---
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic = "ecozone/campus/room_101/occupancy";

// --- Pin Definitions ---
#define RELAY_LIGHTS 26
#define RELAY_FANS   27
#define STATUS_LED   2

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  
  int occupancy = doc["occupancy_count"];
  Serial.print("Occupancy Received: ");
  Serial.println(occupancy);

  // --- Zonal Control Logic ---
  if (occupancy == 0) {
    // Room Empty: Cut off non-essential power
    digitalWrite(RELAY_LIGHTS, LOW);
    digitalWrite(RELAY_FANS, LOW);
    digitalWrite(STATUS_LED, LOW);
    Serial.println("Action: Room Empty. Appliances OFF.");
  } 
  else if (occupancy > 0 && occupancy <= 5) {
    // Low Occupancy: Partial Lighting & Fans
    digitalWrite(RELAY_LIGHTS, HIGH);
    digitalWrite(RELAY_FANS, LOW);
    digitalWrite(STATUS_LED, HIGH);
    Serial.println("Action: Low Occupancy. Eco-Mode ON.");
  } 
  else {
    // High Occupancy: Full Power Mode
    digitalWrite(RELAY_LIGHTS, HIGH);
    digitalWrite(RELAY_FANS, HIGH);
    digitalWrite(STATUS_LED, HIGH);
    Serial.println("Action: High Occupancy. Full Comfort Mode.");
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32_EcoZone_Node")) {
      client.subscribe(mqtt_topic);
    } else {
      delay(5000);
    }
  }
}

void setup() {
  pinMode(RELAY_LIGHTS, OUTPUT);
  pinMode(RELAY_FANS, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);
  
  // Default OFF
  digitalWrite(RELAY_LIGHTS, LOW);
  digitalWrite(RELAY_FANS, LOW);
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
