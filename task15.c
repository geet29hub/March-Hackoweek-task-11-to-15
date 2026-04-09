 int pirPin = 2;
int ledPin = 7;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Slot Occupied");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Slot Empty");
  }

  delay(1000);
}
