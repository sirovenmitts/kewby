#ifndef KEWB_H
#define KEWB_H

#include "Arduino.h"

typedef enum { X, Y, Z } AXIS;

void KewbReset();

void KewbOn(int x, int y, int z);
void KewbOff(int x, int y, int z);

boolean KewbIsOn(int x, int y, int z);

void KewbPlaneOn(AXIS axis, int position);
void KewbOnBetween(int x1, int y1, int z1, int x2, int y2, int z2);

#endif
