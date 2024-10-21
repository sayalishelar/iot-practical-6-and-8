// Define the pin numbers for the LEDs
const int greenLED = 7;
const int yellowLED = 6;
const int redLED = 5;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  // Start serial communication
  Serial.begin(9600);
  Serial.println("Enter 'b' to blink green, 'g' to illuminate green, 'y' for yellow, and 'r' for red:");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read(); // Read user input
    
    // Turn off all LEDs before processing new input
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    // Check the user input and control the LEDs
    if (input == 'b') {
      // Blink the green LED
      for (int i = 0; i < 5; i++) {
        digitalWrite(greenLED, HIGH);
        delay(500);
        digitalWrite(greenLED, LOW);
        delay(500);
      }
    } else if (input == 'g') {
      // Illuminate the green LED
      digitalWrite(greenLED, HIGH);
    } else if (input == 'y') {
      // Illuminate the yellow LED
      digitalWrite(yellowLED, HIGH);
    } else if (input == 'r') {
      // Illuminate the red LED
      digitalWrite(redLED, HIGH);
    } else {
      // If the user entered an invalid character, notify the user
      Serial.println("Invalid input! Use 'b', 'g', 'y', or 'r'.");
    }
  }
}
