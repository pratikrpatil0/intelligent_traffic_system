#include <Arduino.h>


// Defining pins
const int ultrasonicLeftTrigger = 8;       
const int ultrasonicLeftEcho = 9;          
const int ultrasonicRightTrigger = 7;      
const int ultrasonicRightEcho = 6;         
const int singleUltrasonicTrigger = 2;    
const int singleUltrasonicEcho = 3;        
const int greenLED = 12;                   
const int redLED = 11;                     
const int buzzer = 4;                      

void setup() {
  pinMode(ultrasonicLeftTrigger, OUTPUT);
  pinMode(ultrasonicLeftEcho, INPUT);
  pinMode(ultrasonicRightTrigger, OUTPUT);
  pinMode(ultrasonicRightEcho, INPUT);
  pinMode(singleUltrasonicTrigger, OUTPUT);
  pinMode(singleUltrasonicEcho, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Initial state: green light on
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

long measureDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.034) / 2; // Calculate distance in cm
  return distance;
}

void loop() {
  // Default state: Green light on, using left and right sensors
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  long distanceLeft = measureDistance(ultrasonicLeftTrigger, ultrasonicLeftEcho);
  long distanceRight = measureDistance(ultrasonicRightTrigger, ultrasonicRightEcho);

  // If an object is detected by either side sensor, turn red light on
  if (distanceLeft < 50 || distanceRight < 50) {  // Threshold distance in cm
    digitalWrite(greenLED, LOW);       // Turn off green light
    digitalWrite(redLED, HIGH);        // Turn on red light
    delay(200); // Short delay to stabilize sensors

    // Pause side sensors and activate center sensor
    unsigned long startTime = millis();

    while (true) {
      long distanceCenter = measureDistance(singleUltrasonicTrigger, singleUltrasonicEcho);

      // Reset the 10-second timer if an object is detected within range
      if (distanceCenter < 50) {
        startTime = millis();  // Restart timer if object is detected within 10 seconds
      }

      // If 10 seconds pass without any detection from the center sensor, activate the buzzer
      if (millis() - startTime > 10000) {
        digitalWrite(buzzer, HIGH);    // Turn on buzzer
        delay(2000);                   // Buzzer on for 2 seconds

        // Start another 10-second loop to monitor center sensor
        unsigned long buzzerCheckStartTime = millis();
        while (digitalRead(buzzer) == HIGH) {
          distanceCenter = measureDistance(singleUltrasonicTrigger, singleUltrasonicEcho);

          // Restart the 10-second timer if an object is detected within range
          if (distanceCenter < 50) {
            buzzerCheckStartTime = millis();   // Restart this inner timer
          }

          // If 10 seconds pass without detecting an object and the buzzer is on, reset system
          if (millis() - buzzerCheckStartTime > 10000) {
            digitalWrite(buzzer, LOW);         // Turn off buzzer
            digitalWrite(greenLED, HIGH);      // Turn green light back on
            digitalWrite(redLED, LOW);         // Turn off red light
            break;                             // Exit the second inner loop
          }
        }
        break;  // Exit the first inner loop after completing the buzzer check
      }
    }
  }
}
 