#include "timestamp.h"
#include "stm32f4xx_hal.h"
#include "timer.h"

void initTimeM()
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; /* Takt fuer Timer 2 einschalten */
    TIM2->CR1 = 0;                      /* Timer disabled                */
    TIM2->CR2 = 0;                      /*                               */
    TIM2->PSC = 0;                  		/* Prescaler für ms (180MHz) 		 */
    TIM2->ARR = 0xffffffff;             /* Auto reload register          */
    TIM2->DIER = 0;                     /* Interrupt ausschalten         */
    TIM2->CR1 = TIM_CR1_CEN;            /* Enable Timer                  */
}

uint32_t getTimeM()
{
	return TIM2->CNT;
}

double getPeriodM(uint32_t t1, uint32_t t2)
{
	uint32_t diff = (t2 >= t1) ? (t2 - t1) : (0xFFFFFFFF - t1 + t2 + 1); // Bitmanipulation mit ~?
	
	return diff / 90e6; // * 90.000.000 für Sekunden;
}
