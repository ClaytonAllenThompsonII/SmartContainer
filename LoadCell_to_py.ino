#include "HX711.h" //Original Repository Created by Bodge https://github.com/bogde/HX711
// Define the calibration factor for your load sensor
const float CALIBRATION_FACTOR = 219.9;

// Create an instance of the HX711 library
HX711 loadSensor;

void setup() {
  Serial.begin(9600);
  loadSensor.begin(2, 3); // Set the data and clock pins for the load sensor
  loadSensor.set_scale(CALIBRATION_FACTOR);
  loadSensor.tare();
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'x') {
      float load = loadSensor.get_units();
      Serial.println(load);
    }
  }
}