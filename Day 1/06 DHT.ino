// Paste your code here

#include <DHT.h>

// Define the type of DHT sensor (DHT11)
#define DHT_TYPE DHT11

// Define the pin connected to the DHT sensor
#define DHT_PIN 26

// Initialize DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  // Read humidity value
  float humidity = dht.readHumidity();
  // Read temperature value in Celsius
  float temperature = dht.readTemperature();

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print humidity and temperature values
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Wait for 2 seconds before taking the next reading
  delay(2000);
}
