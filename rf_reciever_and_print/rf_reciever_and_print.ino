#include <RCSwitch.h>  // Radiohead library for 433mhz rf

RCSwitch mySwitch = RCSwitch();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  mySwitch.enableReceive(13);
  Serial.println("RF receiver initialized");
}
void loop() {

  if (mySwitch.available()) {
    int receivedValue = mySwitch.getReceivedValue();


    Serial.print("Recieved: ");
    Serial.println(receivedValue);
    mySwitch.resetAvailable();
  }
}
