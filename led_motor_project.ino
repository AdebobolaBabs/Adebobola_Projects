
#define ENABLE 5
#define DIRA 3
#define DIRB 4

void setup() {
  pinMode(8, OUTPUT); // red
  pinMode(10, OUTPUT); // yellow
  pinMode(12, OUTPUT); // green
  pinMode(ENABLE, OUTPUT); // motor power
  pinMode(DIRA, OUTPUT); // spin right
  pinMode(DIRB, OUTPUT); // spin left
  //Serial.begin(9600);
}

void loop() {
  digitalWrite(8, HIGH); // turn on red for 2 seconds
  delay(2000);
  digitalWrite(8, LOW); // turn off red

  digitalWrite(10, HIGH); // turn on yellow for 2 seconds
  delay(2000);
  digitalWrite(10, LOW); // turn off yellow

  digitalWrite(12, HIGH); // turn on green for 2 seconds

  //Serial.println("Start The Motors!");
  digitalWrite(DIRB, HIGH); // spin to the left
  digitalWrite(DIRA, LOW);
  analogWrite(ENABLE, 255); // set motor speed to 255
  delay(2000);

  analogWrite(ENABLE, LOW); // turn motor off
  digitalWrite(12, LOW); // turn off green
}
