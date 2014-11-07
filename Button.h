#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON_ON 0
typedef void (* ButtonFunction)();

void ButtonSetup();
void ButtonOnPressDo(ButtonFunction b);
void ButtonUpdate();

#endif
