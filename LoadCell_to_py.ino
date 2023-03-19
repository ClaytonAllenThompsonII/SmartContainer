#include "HX711.h" //Original Repository Created by Bodge https://github.com/bogde/HX711
// Define the calibration factor for your load sensor
const float CALIBRATION_FACTOR = 219.9;

// Create an instance of the HX711 library
HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(2, 3); // Set the data and clock pins for the load sensor
  scale.set_scale(CALIBRATION_FACTOR);
  scale.tare();
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'x') {
      float load = scale.get_units();
      Serial.println(load);
    }
  }
}