#ifndef ENCODERM_H
#define ENCODERM_H

#include "stm32f4xx_hal.h"

int count = 0;

typedef enum {
STAT_F,							// Vorwaerts
STAT_B, 						// Rueckwaerts
STAT_E, 						// Error
STAT_N} 						// Nichts
Status; 

typedef enum {
PHASE_A = 0,				// =00
PHASE_B = 2,				// =10
PHASE_C = 3, 				// =11
PHASE_D = 1} 				// =01
Phase;

Status state_sieve[4][4] = {
[PHASE_A] = {STAT_N, STAT_B, STAT_F, STAT_E},   // A - D - B - C 
[PHASE_B]	= {STAT_B, STAT_E, STAT_N, STAT_F}, 
[PHASE_C] = {STAT_E, STAT_F, STAT_B, STAT_N},
[PHASE_D] = {STAT_F, STAT_N, STAT_E, STAT_B}};


int readM ();

void resetCount ();

#endif 
