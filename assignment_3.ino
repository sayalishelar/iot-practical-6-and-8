// Pin definitions
const int tempPin = A0;    // Pin connected to LM35 output
const int buzzerPin = 8;   // Pin connected to the buzzer
const float thresholdTemp = 30.0; // Temperature threshold in Celsius

void setup() {
  // Initialize the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
  // Read the analog value from the LM35
  int sensorValue = analogRead(tempPin);
  
  // Convert the analog value to temperature in Celsius
  float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
  float temperatureC = voltage * 100.0; // LM35 outputs 10mV per degree Celsius

  // Display the temperature on the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Check if the temperature exceeds the threshold
  if (temperatureC > thresholdTemp) {
    digitalWrite(buzzerPin, HIGH); // Activate the buzzer
    Serial.println("Temperature threshold exceeded! Buzzer ON.");
  } else {
    digitalWrite(buzzerPin, LOW);  // Deactivate the buzzer
  }

  // Wait for 1 second before the next reading
  delay(1000);
}
