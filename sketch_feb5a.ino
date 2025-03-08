#define trigPin  9
#define echoPin 8
#define Buzzer1 5  // Active Buzzer
#define Buzzer2 7  // Passive Buzzer
#define LED 6

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Buzzer1, OUTPUT);
  pinMode(Buzzer2, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo signal
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If an object is detected within 10 cm, turn on both buzzers and LED
  if (distance > 0 && distance <= 10) {
    digitalWrite(Buzzer1, HIGH);
    digitalWrite(Buzzer2, HIGH);
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(Buzzer1, LOW);
    digitalWrite(Buzzer2, LOW);
    digitalWrite(LED, LOW);
  }

  delay(100); // Short delay for stability
}
