#include "LowLevel.h"
#include "Kewb.h"
#include "Wait.h"

static int rows[] = {4, 3, 2},
           columns[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};

void LowLevelSetup() {
  for(int i = 0; i < 3; i++) {
    pinMode(rows[i], OUTPUT);
  }
  for(int i = 0; i < 9; i++) {
    pinMode(columns[i], OUTPUT);
  }
}

void LowLevelReset() {
  for(int i = 0; i < 3; i++) {
    digitalWrite(rows[i], LOW);
  }
  for(int i = 0; i < 9; i++) {
    digitalWrite(columns[i], HIGH);
  }
}

void LowLevelUpdate() {
  LowLevelReset();
  for(int x = 0; x < 3; x++) {
    for(int y = 0; y < 3; y++) {
      for(int z = 0; z < 3; z++) {      
        if(KewbIsOn(x, y, z)) {
          digitalWrite(columns[x + (y * 3)], LOW);
          digitalWrite(rows[z], HIGH);
          delay(Wait2());
        }
      }
    }
  }
}
