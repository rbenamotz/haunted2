#include <Arduino.h>
#include "hardware.h"
#define AUTO_BLINK 5000
void blinkEyes();

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_EYES_LED_1, OUTPUT);
  pinMode(PIN_EYES_LED_2, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  digitalWrite(PIN_EYES_LED_1, HIGH);
  digitalWrite(PIN_EYES_LED_2, HIGH);
  Serial.println("Hello from Haunted2");
}

void loop()
{
  static unsigned long lastBlink = 0;
  bool isButtonDown = !digitalRead(PIN_BUTTON);
  unsigned long l = millis() - lastBlink;
  if (l >= AUTO_BLINK || isButtonDown)
  {
    blinkEyes();
    lastBlink = millis();
  }
  while (isButtonDown)
  {
    isButtonDown = !digitalRead(PIN_BUTTON);
    yield();
  }
}

void blinkEyes()
{
  Serial.print("Blinking");
  for (int i = 0; i < 3; i++)
  {
    Serial.print(".");
    digitalWrite(PIN_EYES_LED_1, false);
    delay(50);
    digitalWrite(PIN_EYES_LED_2, false);
    delay(50);
    digitalWrite(PIN_EYES_LED_1, true);
    delay(100);
    digitalWrite(PIN_EYES_LED_2, true);
    delay(100);
  }
  Serial.println("Done");
}
