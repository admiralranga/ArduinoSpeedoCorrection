
int interval = 250;// this is the time in milliseconds that we want our signal to be high and then low
float intervalmath;                    // for example a value of 2 gives a waveform repeat opf 4ms or 250hz ~114mph (unlikely in a TD5!)
float hertz = 250;
                                     
int outputPin = 9;
int ledPin = LED_BUILTIN;
int sensorValue = 0;

void setup() {
  // initialize digital pin 12 as an output.
  pinMode(outputPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  
  hertz = 500.0/(interval);
  Serial.print("Hz = ");
  Serial.print(hertz);
  Serial.print("\t interval = ");
  Serial.println(interval);

  
  for (long i=micros() + 10000000L; micros() <= i;) {
    digitalWrite(outputPin, HIGH);   // set the output high
    //digitalWrite(ledPin, HIGH);   // set the output high
    delay(interval);                       // wait for a second
    digitalWrite(outputPin, LOW);    // turn the LED off by making the voltage LOW
    //digitalWrite(ledPin, LOW);   // set the output high
    delay(interval);                       // wait for a second
  }

  switch(interval) {//cycle through 250,125,20,10,6,5,4,3,2 pulse widths
    case 250: interval = 125; break;
    case 125: interval = 20; break;
    case 20: interval = 10; break;
    case 10: interval = 6; break;
    case 6: interval = 5; break;
    case 5: interval = 4; break;
    case 4: interval = 3; break;
    case 3: interval = 2; break;
    case 2: interval = 250; break;
  }
}
