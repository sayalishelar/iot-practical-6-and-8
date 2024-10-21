// Define the pin where the temperature sensor is connected
const int tempPin = A0;

// Variables to track max and min temperatures
float maxTempC = -1000.0;  // Initialize to an extremely low value
float minTempC = 1000.0;   // Initialize to an extremely high value

void setup() {
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Temperature readings (Celsius and Fahrenheit):");
}

void loop() {
  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(tempPin);
  
  // Convert the analog value to voltage (assuming a 5V reference)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Calculate the temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100.0;  // For TMP36, adjust for LM35 if needed
  
  // Calculate the temperature in Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Update max and min temperature readings
  if (temperatureC > maxTempC) {
    maxTempC = temperatureC;
  }
  
  if (temperatureC < minTempC) {
    minTempC = temperatureC;
  }
  
  // Display the current temperature
  Serial.print("Current Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C / ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  // Display the maximum and minimum temperatures observed
  Serial.print("Max Temperature: ");
  Serial.print(maxTempC);
  Serial.print(" °C / ");
  Serial.print((maxTempC * 9.0 / 5.0) + 32.0);
  Serial.println(" °F");

  Serial.print("Min Temperature: ");
  Serial.print(minTempC);
  Serial.print(" °C / ");
  Serial.print((minTempC * 9.0 / 5.0) + 32.0);
  Serial.println(" °F");

  // Wait for 1 second before taking another reading
  delay(1000);
}
