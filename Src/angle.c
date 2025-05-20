#include "angle.h"
#include "encoder.h"
#include "timestamp.h"
#include "stm32f4xx_hal.h"

// 300 Schlitze = 1200 Phasenwechsel pro Umdrehung
#define WINKEL_PRO_SCHRITT 0.3

double calcWinkel()
{
	return getCount() * WINKEL_PRO_SCHRITT;
}

double calcGeschw(int count1, int count2, double periode)
{
	double winkel = ((double) count2 - count1) * WINKEL_PRO_SCHRITT;
	
	return (winkel / (periode/ 1000.0));
}
