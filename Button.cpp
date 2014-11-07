#include "Button.h"
#include "Arduino.h"

static int current;
ButtonFunction onPress;

void ButtonSetup() {
  pinMode(A5, INPUT_PULLUP);
}

void ButtonOnPressDo(ButtonFunction b) {
  onPress = b;
}

void ButtonUpdate() {
  int next = digitalRead(A5);
  if(next != current && next == BUTTON_ON) {
    onPress();
  }
  current = next;
}
