// Week 5: Joystick → Serial Cursor
// Author: 0xHitek

#define VRX A0
#define VRY A1
#define SW  2

int xPos, yPos, button;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP); // joystick button
}

void loop() {
  xPos = analogRead(VRX);
  yPos = analogRead(VRY);
  button = digitalRead(SW);

  // Map joystick values (0–1023) into -10 to +10 range
  int xMapped = map(xPos, 0, 1023, -10, 10);
  int yMapped = map(yPos, 0, 1023, -10, 10);

  Serial.print("X: "); Serial.print(xMapped);
  Serial.print(" | Y: "); Serial.print(yMapped);

  if (button == LOW) {
    Serial.print(" | Button: PRESSED");
  }
  Serial.println();

  delay(200);
}
