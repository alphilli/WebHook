char published_value[5];
int light_level;

void setup() {
    pinMode(A0, INPUT);

    Particle.variable("light_level", light_level);
    
    //Note that, as per the Particle code examples, we use
    //an analog pin (in output mode with digitalWrite) to make
    //sure the voltage feeding the light sensor is steady.
    pinMode(A5, OUTPUT);
    digitalWrite(A5, HIGH);
    pinMode(D7, OUTPUT);
}

void loop() {
  
  light_level = analogRead(A0);
  //Convert the analog value to a format Particle.publish can use...
  sprintf(published_value, "%d", light_level);
  
  Particle.publish("light_levels", published_value, PRIVATE);
  
  //Flash the onboard LED to give an indication that a value
  //has just been read, while keeping the total delay to 30s.
  digitalWrite(D7, HIGH);
  delay(2000);
  digitalWrite(D7, LOW);
  delay(58000);
}