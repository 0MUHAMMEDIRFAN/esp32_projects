int builtInLedPin = 2;
int ledPin = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(builtInLedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(builtInLedPin, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  digitalWrite(builtInLedPin, LOW);
  delay(1000);
  digitalWrite(ledPin, LOW);
  digitalWrite(builtInLedPin, HIGH);
  delay(2000);
}
