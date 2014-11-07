#include "DropSlide.h"
#include "Kewb.h"

static int step;

void DropSlideUpdate() {
  KewbReset();
  step = (step + 1) % 10;
  switch(step) {
    case 6:
      KewbPlaneOn(X, 1);
    case 7:
      KewbPlaneOn(X, 0);
      break;
    case 5:
    case 4:
    case 3:
      KewbPlaneOn(Z, 0);
    case 2:
      KewbPlaneOn(Z, 1);
    case 1:
      KewbPlaneOn(Z, 2);
  }
}
