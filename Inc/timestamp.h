#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <stm32f4xx_hal.h>


/*
 ****************************************************************************************
 *  @brief      Initialisierung der Clock.
 *
 *  @return     void
 ****************************************************************************************/
 
void initTimeM();

/*
 ****************************************************************************************
 *  @brief      Liefert den aktuellen Zeitstempel.
 *
 *  @return     uint32_t: Zeitstempel
 ****************************************************************************************/
	
uint32_t getTimeM();

/*
 ****************************************************************************************
 *  @brief      Berechnet die Zeit zwischen zwei Zeitstempel.
 *
 *	@param  		t1: uint32_t Zeitstempel 1
 *	@param 			t2: uint32_t Zeitstempel 2
 *
 *  @return     double: Zeitdifferent
 ****************************************************************************************/

double getPeriodM(uint32_t , uint32_t);

#endif
