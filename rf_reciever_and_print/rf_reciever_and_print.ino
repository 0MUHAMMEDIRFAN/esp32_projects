#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);

  // Initialize transmitter on pin 13
  mySwitch.enableTransmit(25);

  // Initialize receiver on pin 12
  mySwitch.enableReceive(27);
}

void loop() {
  // Sending a test signal
  Serial.println("Transmitting signal: 12345");
  mySwitch.send("1010");  // Send signal '12345' with 24-bit length
  delay(1000);               // Wait for a second before receiving

  // Check if we have received any signal
  if (mySwitch.available()) {
    int receivedValue = mySwitch.getReceivedValue();
    if (receivedValue == 0) {
      Serial.println("Error: No signal detected");
    } else {
      Serial.print("Received signal: ");
      Serial.println(receivedValue);
    }
    mySwitch.resetAvailable();  // Reset to get ready for the next reception
  }

  delay(1000);  // Wait 1 second before transmitting and receiving again
}
