#ifndef ENCODER_H
#define ENCODER_H

typedef enum
{
	PHASE_A = 0x00u,
	PHASE_B = 0x10u,
	PHASE_C = 0x11u,
	PHASE_D = 0x01u
} Phase;

typedef enum
{
	FORWARDS,
	BACKWARDS,
	INVALID,
	NO_CHANGE
} Direction;

int getPhase();

int getCount();

void resetCount();

#endif
