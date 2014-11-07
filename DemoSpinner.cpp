#include "DemoSpinner.h"

static int count = 0,
           current = 0;
UpdateFunction demos[100];

void DemoSpinnerReset() {
  count = current = 0;
}

void DemoSpinnerAdd(UpdateFunction u) {
  demos[count] = u;
  count += 1;
}

void DemoSpinnerNext() {
  current = (current + 1) % count;
}

void DemoSpinnerPrevious() {
  current = (current - 1) % count;
  if(current < 0) {
    current += count;
  }
}

void DemoSpinnerUpdate() {
  if(count > 0) {
    demos[current]();
  }
}
