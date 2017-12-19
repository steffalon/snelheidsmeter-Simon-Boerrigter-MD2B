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
    long t;
    long dist1, speed, dist2;

    dist1 = dist();
    t = time();
    Serial.print("Slept");
    dist2 = dist();
    Serial.println();
    Serial.print("Distance 1: ");
    Serial.print(dist1);
    Serial.println();
    Serial.print("Distance 2: ");
    Serial.print(dist2);
    Serial.println();
    speed = (dist2 - dist1)/(t/100);

    Serial.println();
    Serial.print(speed);
//Serial.print(dist2);Serial.println();
//Serial.print(dist1);Serial.println();
//Serial.print(t);Serial.println();
    Serial.println();
    
    delay(2000); 
}

long dist() {
  long cm, inches, duration;
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
  
  return cm;
}

long time() {
  long sleepTime = 100;
  delay(100);
  return sleepTime;  
}
