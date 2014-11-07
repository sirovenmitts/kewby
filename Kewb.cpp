#include "Kewb.h"
#include "Arduino.h"

boolean bits[27];

int toBit(int x, int y, int z) {
  return x + (y * 3) + (z * 9);
}

void safelySet(int bit, boolean value) {
  if(bit >= 0 && bit < 27) {
    bits[bit] = value;
  }
}

void KewbReset() {
  for(int i = 0; i < 27; i++) {
    bits[i] = false;
  }
}

void KewbOn(int x, int y, int z) {
  safelySet(toBit(x, y, z), true);
}

void KewbOff(int x, int y, int z) {
  safelySet(toBit(x, y, z), false);
}

boolean KewbIsOn(int x, int y, int z) {
  int bit = toBit(x, y, z);
  if(bit < 0 || bit > 26) {
    return false;
  }
  return bits[toBit(x, y, z)];
}

void KewbPlaneOn(AXIS axis, int position) {
  for(int x = 0; x < 3; x++) {
    for(int y = 0; y < 3; y++) {
      for(int z = 0; z < 3; z++) {
        switch(axis) {
          case X: KewbOn(position, y, z); break;
          case Y: KewbOn(x, position, z); break;
          case Z: KewbOn(x, y, position); break;
        }
      }
    }
  }
}

void KewbOnBetween(int x1, int y1, int z1, int x2, int y2, int z2) {
  for(int x = x1; x <= x2; x++) {
    for(int y = y1; y <= y2; y++) {
      for(int z = z1; z <= z2; z++) {
        KewbOn(x, y, z);
      }
    }
  }
}
