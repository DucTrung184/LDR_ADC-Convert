#include <Arduino.h>

#define LDR_PIN 39  
int value = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 LDR sensor started!");
}

void loop() {
  value = analogRead(LDR_PIN);  
  
  Serial.print(">Light:");
  Serial.println(value);
  
  delay(1000); 
}
