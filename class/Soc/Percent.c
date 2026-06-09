#include "Percent.h"

static uint8_t clamp100(uint16_t v) { return (v > 100) ? 100 : (uint8_t)v; }

void Percent_Init(Percent *p, uint16_t v) { if (p) p->value = clamp100(v); }
void Percent_Set(Percent *p, uint16_t v)  { if (p) p->value = clamp100(v); }
uint8_t Percent_Get(const Percent *p)      { return p ? p->value : 0; }
