int VRx = A0;
int VRy = A1;
int SW = 2;
int buzzer = 7;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int led_status = HIGH;
int incomingByte = 0;
  
void setup() {
  Serial.begin(9600);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
   pinMode(LED_BUILTIN, OUTPUT);
    pinMode(buzzer, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(buzzer, LOW); 
  led_status = HIGH;

}

void loop() {
   if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
  if (incomingByte == 'E') {
      // flip LED
      led_status = (led_status == HIGH) ? LOW : HIGH;
      digitalWrite(LED_BUILTIN, led_status);
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  if (xPosition > 600)
    Serial.println("d");
  else if (xPosition < 400)
    Serial.println("a");
  else if (yPosition > 600)
    Serial.println("s");
  else if (yPosition <400)
    Serial.println("w");
  }else 
  if (incomingByte == 'B')
  {    digitalWrite(buzzer, HIGH);
  delay(500);
       digitalWrite(buzzer, LOW);
    }
   }
  /*
    Serial.print("X: ");
    Serial.print(mapX);
    Serial.print(" | Y: ");
    Serial.print(mapY);
    Serial.print(" | Button: ");
    Serial.println(SW_state);

    delay(100);
  */
  delay(300);
}
