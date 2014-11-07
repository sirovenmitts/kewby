#include "Wait.h"
#include "TimeCop.h"
#include "Arduino.h"

#define WAIT1_INC 10
#define WAIT1_MIN 10
#define WAIT1_MAX 500

#define WAIT2_INC 1
#define WAIT2_MIN 1
#define WAIT2_MAX 5

time wait1 = 100,
     wait2 = 1;

time Wait1() {
  return wait1;
}

time Wait2() {
  return wait2;
}

void CycleWait1() {
  wait1 = (wait1 + WAIT1_INC) % WAIT1_MAX;
  wait1 = max(wait1, WAIT1_MIN);
}

void CycleWait2() {
  wait2 = (wait2 + WAIT2_INC) % WAIT2_MAX;
  wait2 = max(wait2, WAIT2_MIN);
}
