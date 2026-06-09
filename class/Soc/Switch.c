#include "Switch.h"

void Switch_Init(Switch *sw, bool btn_status)  { if (sw) sw->on = btn_status; }
void Switch_Set(Switch *sw, bool btn_status)   { if (sw) sw->on = btn_status; }
void Switch_Toggle(Switch *sw)                  { if (sw) sw->on = !sw->on; }
bool Switch_IsOn(const Switch *sw)              { return sw ? sw->on : false; }
