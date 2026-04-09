  int buttonPin = 2;
int relayPin = 8;
int count = 10; // inventory

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH && count > 0) {
    digitalWrite(relayPin, HIGH); // dispense
    delay(1000);
    digitalWrite(relayPin, LOW);

    count--;
    Serial.print("Items left: ");
    Serial.println(count);

    delay(2000);
  }
}
