// Define the LED pin
const int ledPin = 7;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Enter '1' to turn ON the LED, '0' to turn OFF the LED, or 'b' to blink the LED.");
}

void loop() {
  // Check if there is input from the serial monitor
  if (Serial.available() > 0) {
    char input = Serial.read(); // Read the input
    
    if (input == '1') {
      // Turn the LED ON
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
      
    } else if (input == '0') {
      // Turn the LED OFF
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
      
    } else if (input == 'b') {
      // Blink the LED 5 times
      for (int i = 0; i < 5; i++) {
        digitalWrite(ledPin, HIGH);
        delay(500);  // Wait for 500 milliseconds
        digitalWrite(ledPin, LOW);
        delay(500);  // Wait for 500 milliseconds
      }
      Serial.println("LED Blinking");
      
    } else {
      // Invalid input
      Serial.println("Invalid input! Use '1', '0', or 'b'.");
    }
  }
}
