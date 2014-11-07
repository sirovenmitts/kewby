#include "LowLevel.h"
#include "Button.h"
#include "Rotary.h"

#include "Kewb.h"
#include "DemoSpinner.h"
#include "TimeCop.h"
#include "Wait.h"

#include "ShiftyPlanes.h"
#include "PassingCube.h"
#include "DropSlide.h"

time update;

int mode = 0;
void SwitchMode() {
  mode = (mode + 1) % 3;
  switch(mode) {
    case 0:
      RotaryOnChangeDo(&DemoSpinnerNext);
      break;
    case 1:
      RotaryOnChangeDo(&CycleWait1);
      break;
    case 2:
      RotaryOnChangeDo(&CycleWait2);
      break;
  }
}

void setup() {
  LowLevelSetup();
  ButtonSetup();
  RotarySetup();

  KewbReset();
  TimeCopReset();

  DemoSpinnerAdd(&PassingCubeUpdate);
  DemoSpinnerAdd(&ShiftyPlanesUpdate);
  DemoSpinnerAdd(&DropSlideUpdate);

  ButtonOnPressDo(&SwitchMode);
  RotaryOnChangeDo(&DemoSpinnerNext);
  Serial.begin(9600);
  Serial.println("Kewb V1, ready!");
}

void loop() {
  TimeCopUpdate();
  update += TimeCopDiff();
  if(update > Wait1()) {
    DemoSpinnerUpdate();
    update = 0;
  }
  LowLevelUpdate();
  ButtonUpdate();
  RotaryUpdate();
}
