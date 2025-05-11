#ifndef LEDM_H
#define LEDM_H

#include <stdbool.h>

void setLedE (int);

void clearLedE (int);

void setLedMaskD (int);

void resetLedMaskD ();

bool readButton (int);

#endif
