// Pin Definitions
const int knockSensorPin = A0;  // Piezo sensor connected to analog pin A0
const int buzzerPin = 8;        // Piezo buzzer connected to digital pin 8
const int threshold = 100;      // Sensitivity threshold for knock detection

// Notes and duration for the melody
int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};  // C, D, E, F, G, A, B, C
int noteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4};         // 4 = quarter note

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // For debugging knock detection
}

void loop() {
  int sensorReading = analogRead(knockSensorPin);  // Read piezo sensor

  if (sensorReading > threshold) {
    Serial.println("Knock detected! Playing tune...");
    playMelody();  // Play a tune if a knock is detected
    delay(1000);   // Delay to prevent multiple detections from one knock
  }
}

// Function to play a melody on the piezo buzzer
void playMelody() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // Calculate note duration in ms: 1000 ms divided by note type
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // Pause between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone between notes
    noTone(buzzerPin);
  }
}
