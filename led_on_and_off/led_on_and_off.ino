int builtInLedPin = 2;
int ledPin = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(builtInLedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(builtInLedPin, HIGH);
  digitalWrite(ledPin, LOW);
  delay(2000);
  digitalWrite(builtInLedPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(1000);
}
