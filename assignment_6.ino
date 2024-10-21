void setup() {
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Enter a number to square:");
}

void loop() {
  // Check if there is input from the serial monitor
  if (Serial.available() > 0) {
    // Read the input as a string
    String input = Serial.readStringUntil('\n');
    
    // Convert the string to an integer
    int number = input.toInt();
    
    // Calculate the square of the number
    int square = number * number;
    
    // Output the result
    Serial.print("The square of ");
    Serial.print(number);
    Serial.print(" is ");
    Serial.println(square);
    
    // Ask for another number
    Serial.println("Enter another number to square:");
  }
}
