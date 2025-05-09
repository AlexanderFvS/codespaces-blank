#include "encoderM.h"
#include "stm32f4xx_hal.h"

static Phase current_phase = PHASE_A;


int readM () {
	Phase new_phase = (Phase) GPIOF->IDR & 0x03;
	Status curr = state_sieve[current_phase][new_phase];
	current_phase = new_phase;
	
	switch(curr) {
		
		case STAT_F:
			count++;
			break;
		
		case STAT_B:
			count--;
			break;
		
		case STAT_E:
			return -1;					//Error Handling?
			break;
		
		case STAT_N:
			break;
	}
	return 0;
}

