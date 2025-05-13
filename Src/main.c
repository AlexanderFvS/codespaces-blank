#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "LCD_GUI.h"
#include "init.h"
#include "lcd.h"
#include "encoder.h"
#include "display_output.h"
#include "angle.h"
#include "timestamp.h"
#include "led_io.h"
#include "delay.h"

#define ZEITFENSTER 0.5													// Zeitfenster für Geschwindigkeitsberechnung in Sekunden

int main()
{
	initITSboard();
	GUI_init(DEFAULT_BRIGHTNESS);
	lcdSetFont(20);
	
	printLabels();																// Initialisierung
	initTimeM();
	uint32_t time1 = getTimeM();					
	int count1 = getCount();
	double winkel1 = 0.0;
	double geschw1 = 0.0;
	printWinkel(winkel1);
	printGeschw(geschw1);
	setPhase();
	
	//____________________________________Superloop____________________________________________//
	
	while (1)
	{
		if (getPhase())															// Encoder-Status abfragen (gibt -1 zurück bei Fehler somit true)
		{
			printError();
			while (!readButtonF(6));									// Warte so lange bis S6 gedrückt wird. Dann Reset Error
			clearError();
			setPhase();
		}
		
		uint32_t time2 = getTimeM();								// Zeitdifferenz berechnen
		double period = getPeriodM(time1, time2);
		
		if (period > ZEITFENSTER)										// Nur berechnen und drucken wenn genug Zeit vergangen ist (ZEITFENSTER)
		{
			int count2 = getCount();
			
			double winkel2 = calcWinkel();
			double geschw2 = calcGeschw(count1, count2, period);
			
			//GPIOE->BSRR = (0x01U);									// Oszilloskop
			if (winkel2 != winkel1) { 								// Display nur aktualisieren wenn sich Werte geändert haben
				printWinkel(winkel2);
			}
			 if (geschw2 != geschw1) {
				 printGeschw(geschw2);
			 }
			//GPIOE->BSRR = (0x01U << 16);						// Oszilloskop
			 
			count1 = count2;													// Werte für nächsten Durchlauf aktualisieren
			time1 = time2;
			winkel1 = winkel2;
			geschw1 = geschw2;
		}
	}
}
