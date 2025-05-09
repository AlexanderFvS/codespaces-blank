#include "timeM.h"
#include "timer.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>






void initTimeM(void){
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; /* Takt fuer Timer 2 einschalten */
    TIM2->CR1 = 0;                      /* Timer disabled                */
    TIM2->CR2 = 0;                      /*                               */
    TIM2->PSC = 0;                  		/* Prescaler für ms (180MHz) 		 */
    TIM2->ARR = 0xffffffff;             /* Auto reload register          */
    TIM2->DIER  = 0;                    /* Interrupt ausschalten         */
    TIM2->CR1 = TIM_CR1_CEN;            /* Enable Timer                  */
}



uint32_t getTimeM(void) {									// liefert den aktuellen Zeitstempel
	
	return TIM2->CNT;
}

double getTimeMD(void) {									// nur zum testen
	
	return (double) TIM2->CNT * (1.0/ 90e6);
}

double getPeriodM(bool* status, uint32_t t1, uint32_t t2) { 								// liefert die Zeit in Sekunden zwischen zwei Zeitstempel
	double periode = 1.0/ 90e6; 																							// * 90.000.000 für Sekunden
	uint32_t diff = (t2 >= t1) ? (t2 - t1) : (0xFFFFFFFF - t1 + t2 + 1);
	
	return (double) diff * periode;
	
	
}