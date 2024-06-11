// pins connections
const int pirPin = 2;      // PIR sensor input pin
const int motorPin1 = 3;   // L293D input 1
const int motorPin2 = 4;   // L293D input 2
const int enablePin = 5;   // L293D enable pin

void setup() {
  // Initialize pins
  pinMode(pirPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  //  enable pin to high to enable the motor driver
  digitalWrite(enablePin, HIGH);
  
  // Start with the motor off
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  
  // Begin serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read PIR sensor
  int pirState = digitalRead(pirPin);
  
  // Check if PIR sensor detects motion
  if (pirState == HIGH) {
    Serial.println("Motion detected! Opening door...");
    // Rotate motor to open door
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(2000); // delay as needed for door opening duration
    
    // Stop the motor after opening
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    
    // Wait for motion to stop being detected
    while (digitalRead(pirPin) == HIGH) {
      delay(100);
    }
    
    Serial.println("No motion detected. Closing door...");
    // Rotate motor to close door
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(2000); // delay as needed for door closing duration
    
    // Stop the motor after closing
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  
  delay(100); // Small delay to prevent excessive checking
}
