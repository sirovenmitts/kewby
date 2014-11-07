#include "TimeCop.h"
#include "Arduino.h"

static time last, now;

void TimeCopReset() {
  now = millis();
}

void TimeCopUpdate() {
  last = now;
  now = millis();
}

time TimeCopDiff() {
  return now - last;
}
