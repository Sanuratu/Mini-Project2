//define L298n module IO Pin
int ENA = 5;
int IN1 = 3;
int IN2 = 4;

int ENB = 6;
int IN3 = 2;
int IN4 = 7;

#define MotorA 120
#define MotorB 120

int Sensor1 = 0;
int Sensor4 = 0;
int Sensor2 = 0;
int Sensor3 = 0;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  Sensor1 = digitalRead(8);
  Sensor4 = digitalRead(11);
  Sensor2 = digitalRead(9);
  Sensor3 = digitalRead(10);

  if (Sensor2 == LOW && Sensor3 == LOW) //IR is on black line
  {
    //Stop both Motors
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite (ENA, 0);
    analogWrite (ENB, 0);
   
  }
  else if (Sensor2 == HIGH && Sensor3 == HIGH) //IR not on black line
  {
    //Move both the Motors
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite (ENA, MotorA);
    analogWrite (ENB, MotorB);
   
  }

  else if (Sensor2 == HIGH && Sensor3 == LOW)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite (ENA, 255);
    analogWrite (ENB, 255);
 
  }

  else if (Sensor3 == HIGH && Sensor4 == LOW)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite (ENA, 255);
    analogWrite (ENB, 255);
   
  }

  else
  {
    //Stop both the motors
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite (ENA, 0);
    analogWrite (ENB, 0);
   
  }
}