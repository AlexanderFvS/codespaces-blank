#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <stm32f4xx_hal.h>

void initTimeM();
	
uint32_t getTimeM();

double getPeriodM(uint32_t , uint32_t);

#endif
