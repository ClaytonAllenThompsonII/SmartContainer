#include <Wire.h>
#include <AWSIoTDeviceSDK.h>
#include <Particle.h>
#include <TimeLib.h>

// AWS IoT endpoint configuration
char* awsEndpoint = "your-iot-endpoint.amazonaws.com";
char* awsRegion = "us-east-1";
char* awsKey = "your-aws-key";
char* awsSecret = "your-aws-secret";
char* awsClientId = "your-aws-client-id";
char* awsTopic = "load_cell_data";

AWSIoTClient awsClient(awsEndpoint, awsClientId, awsKey, awsSecret);

void setup() {
  Serial.begin(9600);
  Wire.begin(); // initialize I2C bus

  // Set up Wi-Fi connection
  WiFi.on();
  WiFi.setCredentials("guest-ssid", "guest-password"); // Similiar to WiFi.Begin(ssid,pass) Allows the application to set credentials for the Wi-Fi network from within the code. These credentials will be added to the device's memory, and the device will automatically attempt to connect to this network in the future.
  WiFi.connect();
  //Checks if the Wifi is connected using WiFi.ready(); If Wi-Fi is connected ready() returns True and prints message to serial monitor. 
  if (WiFi.ready()) {Serial.println("Connected to Wi-Fi network!");}
     else {Serial.println("Failed to connect to Wi-Fi network!");}


  // Set timezone offset to local timezone (Eastern Time Zone)
  Time.zone(-5);

  awsClient.enableMetrics(); // optional, enables metrics collection
  awsClient.setMetricsInterval(60000); // optional, sets metrics interval to 1 minute
  awsClient.connect();

  delay(1000);
}

void loop() {
  // Your remaining code for the Photon, excluding the OpenScale-specific code
    if (Serial1.available()) {
        Serial.write(Serial1.read());
    }

}
