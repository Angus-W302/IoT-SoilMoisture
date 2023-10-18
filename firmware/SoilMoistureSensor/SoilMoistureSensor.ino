/*
*  Weather Station App with Soil Moisture
*  CGS Semester 2
*  Task 2
*  Author: Angus Wallbrink
*/

#include <math.h>
#include <WiFi.h>
#include <aREST.h>

// Soil moisture sensor pin
#define SOIL_MOISTURE_PIN 26 // Change this to the pin your sensor is connected to
#define THRESHOLD 2000

// Create aREST instance
aREST rest = aREST();

// WiFi parameters
const char* ssid = "Proxima";
const char* password = "centauri";

//Static IP address configuration
#define LISTEN_PORT 80

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

// Variables to be exposed to the API
int soilMoisture; // create a variable for soil moisture
char* location = "Al Fresco";
int timer = 72000;

//Led Pin
const int ledPin = 14; 

// Declare functions to be exposed to the API
int ledControl(String command);

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  // Init variables and expose them to REST API
  rest.variable("soilMoisture", &soilMoisture); // Replace temperature and humidity
  rest.variable("location", &location);

  // Give name and ID to device
  rest.set_id("112");
  rest.set_name("alpha-112");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  IPAddress ip(192, 168, 1, 112); // Set static IP
  IPAddress gateway(192, 168, 1, 1); // Set gateway
  Serial.print(F("Setting static IP to : "));
  Serial.println(ip);
  IPAddress subnet(255, 255, 255, 0); // Set subnet
  WiFi.config(ip, gateway, subnet);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());

}

void loop()
{
  // Reading soil moisture
  soilMoisture = analogRead(SOIL_MOISTURE_PIN);

  // Check if soil is dry or wet and print soil moisture value
  if (soilMoisture > THRESHOLD) {
    Serial.println("The soil is WET");
    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("The soil is DRY");
    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);
    digitalWrite(ledPin, LOW);
  }

  // Check running time and reset if expired
  if (timer <= 0)
  {
    delay(3000);
    Serial.println("Resetting..");
    ESP.restart();
  }
  else
  {
    Serial.print("Timer: ");
    Serial.println(timer);
    delay(5000);
    timer--;
  }

  // Handle REST calls
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  while (!client.available())
  {
    delay(1);
  }
  rest.handle(client);
}


// Custom function accessible by the API
int ledControl(String command)
{

  // Get state from command
  int state = command.toInt();

  digitalWrite(6, state);
  return 1;
}
