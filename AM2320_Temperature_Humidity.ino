#include <AM2320.h>

AM2320 th(&Wire);

int sensorPin = A0;
int HighPin = D1;

void setup() {
  Serial.begin(115200);
  Wire.begin(D3, D2);
  pinMode(HighPin, OUTPUT);
  digitalWrite(HighPin, HIGH);
}

void loop() {

  int sensorValue = sensorValue = analogRead(sensorPin);
  Serial.println(F("Gound voltage"));
  Serial.print(sensorValue);
  Serial.println(F(""));
  
  Serial.println(F("Chip = AM2320"));
  switch(th.Read()) {
    case 2:
      Serial.println(F("  CRC failed"));
      break;
    case 1:
      Serial.println(F("  Sensor offline"));
      break;
    case 0:
      Serial.print(F("  Humidity = "));
      Serial.print(th.Humidity);
      Serial.println(F("%"));
      Serial.print(F("  Temperature = "));
      Serial.print(th.cTemp);
      Serial.println(F("*C"));
      Serial.println();
      break;
  }
  ESP.deepSleep(10e6); // 20e6 is 20 microseconds
}
