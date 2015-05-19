const int analogOutPin = 11;   // analog output pin
int brightness = 0;            // LED brightness
int interval = 0;              // blink delay, ms 
unsigned long previousMillis = 0;
bool LEDstate = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Type 'b' plus a number from 0-255 to set the brightness");
  Serial.println("Type 'r' plus a number to set the blink interval in milliseconds");
}

void loop() {
  unsigned long currentMillis = millis();  
  char c;
  if (Serial.available()) {
    c = Serial.read();
    if (c == 'b') {
      brightness = Serial.parseInt(); 
      if (brightness > 255) brightness = 255;
      if (brightness < 0) brightness = 0;
      Serial.print("Setting brightness to "); Serial.println(brightness);
    } else if (c == 'r') {
      interval = Serial.parseInt();
      Serial.print("Setting interval to "); Serial.print(interval); Serial.println(" ms");
    }
    while (Serial.available()) Serial.read();
  }
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (LEDstate) {
      LEDstate = false;
      analogWrite(analogOutPin, 0);
    } else {
      LEDstate = true;
      analogWrite(analogOutPin, brightness);
    }
  }
}
