int alcoholPin = A0; // MQ-3 Alcohol sensor connected to A0
int motorPin1 = 11; // Motor control pin 1 (IN1)
int motorPin2 = 12; // Motor control pin 2 (IN2)
int buzzerPin = 6; // Buzzer connected to Pin 6
int threshold = 500; // Threshold alcohol level for triggering motor lock
int alcoholLevel = 0; // Variable to store alcohol sensor reading

void setup() 
{
 pinMode(motorPin1, OUTPUT); // Set motor control pins as output
 pinMode(motorPin2, OUTPUT);
 pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
 Serial.begin(9600); // Start Serial Monitor for debugging
 Serial.println("Alcohol Detection System Initialized...");
 Serial.println("Threshold Level: ");
 Serial.println(threshold); // Print the threshold level for reference
}

void loop() 
{
 // Read alcohol level from MQ-3 sensor
 alcoholLevel = analogRead(alcoholPin); 
 Serial.print("Alcohol Sensor Reading: "); 
 Serial.println(alcoholLevel); // Display raw alcohol level reading on Serial 
Monitor
 // Compare the alcohol level with the threshold
if (alcoholLevel > threshold) {
 // Alcohol detected above threshold: stop motor and activate buzzer
 Serial.println("ALCOHOL DETECTED! Exceeding threshold level.");
 Serial.println("Motor stopped, Buzzer ON.");
 digitalWrite(motorPin1, LOW); // Stop motor
 digitalWrite(motorPin2, LOW);
 digitalWrite(buzzerPin, HIGH); // Activate buzzer
 } 
  
else
{
 // No alcohol detected: run motor and keep buzzer off
 Serial.println("No alcohol detected. Level is below the threshold.");
 Serial.println("Motor running...");
 digitalWrite(motorPin1, HIGH); // Run motor forward
 digitalWrite(motorPin2, LOW);
 digitalWrite(buzzerPin, LOW); // Turn off buzzer
}
  
 // Print the current system state to the Serial Monitor
 Serial.print("Motor Status: ");
 if (alcoholLevel > threshold) {
 Serial.println("Stopped");
 }
else
 {
 Serial.println("Running");
 }
 Serial.print("Buzzer Status: ");
 if (digitalRead(buzzerPin) == HIGH) {
 Serial.println("ON");
 } else 
 {
 Serial.println("OFF");
 }
 Serial.println(); // Add a blank line between readings for better readability
 delay(2000); // Delay for 1 second before the next sensor reading
}
