#ifndef ROTARY_H
#define ROTARY_H

typedef void (* RotaryFunction)();

void RotarySetup();
void RotaryOnChangeDo(RotaryFunction r);
void RotaryUpdate();

#endif
