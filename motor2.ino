int trigPin = 9;
int echoPin = 8;
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 3;
int velocidade = 50;
int motor1pin1 = 3;
int motor1pin2 = 4;
int motor1vel = 5;
int motor2pin1 = 12;
int motor2pin2 = 11;
int motor2vel = 10;

unsigned long time;
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  // initialize the digital pin as an output.
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1vel, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2vel, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  time = millis();
  
}

void motor(long dist) {
  
  velocidade = dist * 2;

  if (velocidade > 255){
    velocidade = 255;
  }
  //Serial.println("hora");
  //Serial.print(millis() - time);
  unsigned long distanciaparada = 0.0;
  if (time > 3000)
    distanciaparada = 100;
  else
    distanciaparada = 30 + (time / 100);
 
  if (dist < distanciaparada){
    
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    velocidade = 255;
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    analogWrite(motor1vel, velocidade);
    analogWrite(motor2vel, velocidade);
    delay(600);
    time = millis();
  }  else {
    digitalWrite(motor1pin1, HIGH); 
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH); 
    digitalWrite(motor2pin2, LOW);
  }
  
  //if (dist < 20){
  //  digitalWrite(3, HIGH);
  //  digitalWrite(4, HIGH);
  //}
  Serial.println(dist);
  analogWrite(motor1vel, velocidade);
  analogWrite(motor2vel, velocidade);
  
  //delay(300);
  
}

long sensordistancia() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration/2) / 29.1;
  return distance;
}

// the loop routine runs over and over again forever:
void loop() {
  delay(100);
  
  motor(sensordistancia());
  //Serial.println(sensordistancia());
}

