#ifndef DEMO_SPINNER_H
#define DEMO_SPINNER_H

typedef void (* UpdateFunction)();

void DemoSpinnerReset();
void DemoSpinnerAdd(UpdateFunction u);
void DemoSpinnerNext();
void DemoSpinnerPrevious();
void DemoSpinnerUpdate();

#endif
