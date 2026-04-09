 int motorPWR1 = 12, motorI1 = 11, motorI2 = 10;
int motorPWR2 = 2, motorI3 = 3, motorI4 = 5;
int bumpSensor = 13;
int trigPin = 6, echoPin = 13, pez = 9;
long duration, inches;
bool bumpActive = false;

void setup()
{
  pinMode(motorPWR1, OUTPUT);
  pinMode(motorPWR2, OUTPUT);
  digitalWrite(motorPWR1, HIGH);
  digitalWrite(motorPWR2, HIGH);
  
  pinMode(motorI1, OUTPUT);
  pinMode(motorI2, OUTPUT);  
  pinMode(motorI3, OUTPUT);
  pinMode(motorI4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pez, OUTPUT);
  
  pinMode(bumpSensor, INPUT);  
  
  Serial.begin(9600);
}

void loop()
{
  ultrasonicSensor();
  if (inches < 15)
  {
    bumpActive = true;
  }
  if (bumpActive)
  {
    digitalWrite(pez, HIGH);
    bumpFunction();
  }
  else
  {
    digitalWrite(pez, HIGH);
    forward();
  }
}

void bumpFunction()
{
  stop();
  delay(1000);
  backward();
  delay(2500);
  turnLeft();
  delay(2500);
  bumpActive = false;
}
void ultrasonicSensor()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  inches = (duration/2) / 74;
}

void stop()
{
  digitalWrite(motorI1, LOW);
  digitalWrite(motorI2, LOW);  
  digitalWrite(motorI3, LOW);
  digitalWrite(motorI4, LOW);
  Serial.println("STOP");
}
void forward()
{
  digitalWrite(motorI1, HIGH);
  digitalWrite(motorI2, LOW);  
  digitalWrite(motorI3, HIGH);
  digitalWrite(motorI4, LOW);
  Serial.println("FORWARD");
}
void backward()
{
  digitalWrite(motorI2, HIGH);
  digitalWrite(motorI1, LOW);
  digitalWrite(motorI4, HIGH);
  digitalWrite(motorI3, LOW);
  Serial.println("BACKWARD");
} 
void turnRight()
{
  digitalWrite(motorI1, LOW);
  digitalWrite(motorI2, LOW); 
  digitalWrite(motorI4, LOW);
  digitalWrite(motorI3, HIGH);
  Serial.println("TURN RIGHT");
}
void turnLeft()
{
  digitalWrite(motorI1, HIGH);
  digitalWrite(motorI2, LOW); 
  digitalWrite(motorI4, LOW);
  digitalWrite(motorI3, LOW);
  Serial.println("TURN LEFT");
}
