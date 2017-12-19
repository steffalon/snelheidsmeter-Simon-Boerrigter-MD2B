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
    double speed, t;
    double dist1, dist2;

    dist1 = dist();
    t = time();
    Serial.print("Slept");
    dist2 = dist();

    speed = (dist2 - dist1)/t;

    Serial.println();
    Serial.print(speed);
//Serial.print(dist2);Serial.println();
//Serial.print(dist1);Serial.println();
//Serial.print(t);Serial.println();
    Serial.println();
    
    delay(2000); 
}

double dist() {
  double tijd, m;
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);
 
    tijd = pulseIn(echoPin, HIGH); // TIME IS IN MICROSECONDS
    
    m = (tijd / 29 / 2);
    return m;  
}

double time() {
  long sleepTime = 100;
  Serial.print("sleeping");
  delay(100);
  return sleepTime;  
}
