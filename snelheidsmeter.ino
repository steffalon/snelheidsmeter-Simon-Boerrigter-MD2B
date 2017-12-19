// Arduino pinnnen configureren
const int echoPin = 2;
const int trigPin = 4;
long last;
long dif;

void setup() {
    // Zet IN- en UITgang voor digitale pinnen
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    // Seriele poort aanzetten
    Serial.begin(9600);
    last = 0;
}
 
void loop()
{
    float t;
    float dist1, dist2;
    float speed;

    dist1 = dist();
    t = time();
    dist2 = dist();
    Serial.println();
    Serial.print("Distance 1: ");
    Serial.print(dist1);
    Serial.print(" m");
    Serial.println();
    Serial.print("Distance 2: ");
    Serial.print(dist2);
    Serial.print(" m");
    Serial.println();
    speed = ((dist2 - dist1))/(t/1000);

    Serial.println();
    Serial.print("Speed in m/s: ");
    Serial.print(speed);
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    
    delay(500); 
}

float dist() {
  float cm, inches, duration;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  cm = cm/100;
  return cm;
}

float time() {
  float sleepTime = 100;
  delay(100);
  return sleepTime;  
}
