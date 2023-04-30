#include "HX711.h" //Original Repository Created by Bodge https://github.com/bogde/HX711
// Define the calibration factor for your load sensor
const float CALIBRATION_FACTOR = -1760;

long setting_tare_point; //Zero value that is found when scale is tared
const byte statusLED = 13;  //Flashes with each reading
// Create an instance of the HX711 library
HX711 scale;

void setup() 
{
  pinMode(statusLED, OUTPUT);
  
  scale.begin(2, 3); // Set the data and clock pins for the load sensor

  //Setup UART
  Serial.begin(9600);

  scale.set_scale(CALIBRATION_FACTOR);
  scale.set_offset(setting_tare_point);
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