#include "Rotary.h"
#include "Arduino.h"
#include "TimeCop.h"

#define ROTARY_TIMEOUT 100
#define LEFT A0
#define RIGHT A1

static int last = 0;
static time updated = millis();
static RotaryFunction onChanged;

void RotarySetup() {
  pinMode(LEFT, INPUT);
  digitalWrite(LEFT, HIGH);
  pinMode(RIGHT, INPUT);
  digitalWrite(RIGHT, HIGH);
}

void RotaryOnChangeDo(RotaryFunction r) {
  onChanged = r;
}

void RotaryUpdate() {
  int MSB = digitalRead(LEFT);
  int LSB = digitalRead(RIGHT);
  int encoded = (MSB << 1) | LSB;
  int sum = (last << 2) | encoded;
  int changed = false;
  switch(sum) {
    case 0b1101:
    case 0b0100:
    case 0b0010:
    case 0b1011:
    case 0b1110:
    case 0b0111:
    case 0b0001:
    case 0b1000:
      changed = true;
  }
  last = encoded;

  time now = millis();
  if(now - updated > ROTARY_TIMEOUT) {
    if(changed) {
      Serial.println("CHANGED");
      onChanged();
      updated = now;
    }
  }
}
