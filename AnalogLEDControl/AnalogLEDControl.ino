const int analogInPin  = A0;    // analog input pin
const int analogOutPin = 11;    // analog output pin

int sensorValue = 0;            // value read from potentiometer
int outputValue = 0;            // value written to the analog output

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read in the analog value
  sensorValue = analogRead(analogInPin);
  // map it from the input range (0-1023) to the analog output range (0-255)
  outputValue = map(sensorValue,0,1023,0,255);
  // change the analog output and report values
  analogWrite(analogOutPin, outputValue);
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.println(outputValue);
  delay(10);
}
