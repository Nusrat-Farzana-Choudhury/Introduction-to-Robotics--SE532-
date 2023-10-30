/*Team: BlindSight Innovators
  Daffodil International University*/

#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4

long duration;
int distance;
int alarmThreshold = 50; // Adjusted this threshold as needed

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measuring the echo duration to calculate distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // Calculated distance in centimeters

  // Check if an obstacle is too close
  if (distance < alarmThreshold) {
    digitalWrite(BUZZER_PIN, HIGH); // Activate the buzzer
    delay(1000); // Buzz for 1 seconds
    digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50); // Delay for smoother readings, adjusted as needed
}
