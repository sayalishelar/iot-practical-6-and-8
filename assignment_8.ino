// Define the pin where the temperature sensor is connected
const int tempPin = A0;

void setup() {
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Temperature readings:");
}

void loop() {
  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(tempPin);
  
  // Convert the analog value to voltage (assuming a 5V reference for LM35)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // For LM35: each 10mV represents 1°C, so temperature in Celsius is voltage * 100
  // For TMP36: The output is offset by 500mV, so subtract 0.5 and multiply by 100
  float temperatureC = (voltage - 0.5) * 100.0; // For TMP36, adjust formula accordingly for LM35
  
  // Print the temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Wait for 1 second before taking another reading
  delay(1000);
}



//Vcc (Pin 1): Connect to 5V (for LM35) or 3.3V (for TMP36).
//GND (Pin 3): Connect to GND.
//Analog Output (Pin 2): Connect to an analog pin on the Arduino (e.g., A0).
