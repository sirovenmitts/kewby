#include "Kewb.h"
#include "ShiftyPlanes.h"

static int counter = 0;

void ShiftyPlanesUpdate() {
  KewbReset();
  counter = (counter + 1) % 9;
  int position = counter % 3;
  if(counter < 3) {
    KewbPlaneOn(Z, position);
  } else if(counter < 6) {
    KewbPlaneOn(Y, position);
  } else {
    KewbPlaneOn(X, position);
  }
}
