#include "Kewb.h"
#include "PassingCube.h"

static int step = 0;

void PassingCubeUpdate() {
  KewbReset();
  step = (step + 1) % 6;
  switch(step) {
    case 1:
      KewbOn(0, 0, 0);
      break;
    case 2:
      KewbOnBetween(0, 0, 0, 1, 1, 1);
      break;
    case 3:
      KewbPlaneOn(Z, 0);
      KewbPlaneOn(Z, 1);
      KewbPlaneOn(Z, 2);
      break;
    case 4:
      KewbOnBetween(1, 1, 1, 2, 2, 2);
      break;  
    case 5:
      KewbOn(2, 2, 2);
      break;
  }
}
