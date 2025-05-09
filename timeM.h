#ifndef TIMEM_H
#define TIMEM_H

#include <stm32f4xx_hal.h>
#include <stdbool.h>

void initTimeM(void);
	
uint32_t getTimeM(void);

double getTimeMD(void);

double getPeriodM(bool* , uint32_t , uint32_t);




















#endif //TIMERMM_H