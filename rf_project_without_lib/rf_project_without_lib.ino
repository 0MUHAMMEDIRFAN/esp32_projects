int builtInLedPin = 2;
int transmitPin = 12;  // Transmitter pin
int receivePin = 13;   // Receiver pin

int dataToSend = 5;   // The number we want to send
int receivedData = 0;  // Variable for received data

void setup() {
  Serial.begin(115200);
  
  // Set up pins
  pinMode(transmitPin, OUTPUT);
  pinMode(receivePin, INPUT);

  pinMode(builtInLedPin, OUTPUT);

  Serial.print("Transmit Pin :");
  Serial.println(transmitPin);
  Serial.print("Receive Pin :");
  Serial.println(receivePin);
  
  // Create two tasks
  xTaskCreate(transmitTask, "Transmit Task", 1000, NULL, 1, NULL);
  xTaskCreate(receiveTask, "Receive Task", 3000, NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(builtInLedPin, HIGH);
  delay(1500);
  digitalWrite(builtInLedPin, LOW);
  delay(1000);
}

// Transmitter task
void transmitTask(void *pvParameters) {
  while (true) {
    sendData(dataToSend);
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay between transmissions
  }
}

// Receiver task
void receiveTask(void *pvParameters) {
  while (true) {
    receivedData = receiveData();
    Serial.print(receivedData);
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay between checks
  }
}

void sendData(int data) {
  for (int i = 0; i < 8; i++) {
    int bitValue = bitRead(data, i);
    digitalWrite(transmitPin, bitValue);
    delay(50);  // Small delay to simulate transmission
  }
}

int receiveData() {
  int data = 0;

  for (int i = 0; i < 8; i++) {
    int bitValue = digitalRead(receivePin);
    if (bitValue == HIGH) {
      data |= (1 << i);
    }
    delay(50);  // Same delay to sync with transmitter
  }

  return data;
}


