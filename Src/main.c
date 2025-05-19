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

#define ZEITFENSTER 50.0												// Zeitfenster für Geschwindigkeitsberechnung in Sekunden

Phase currPhase;															// Letzte Phase des Encoders 
Phase newPhase;

int main()
{
	initITSboard();
	GUI_init(DEFAULT_BRIGHTNESS);
	lcdSetFont(20);
	
	printLabels();																// Initialisierung
	initTimeM();
	int time1 = getTimeM();					
	int count1 = getCount();
	double winkel1;
	double geschw1;
	currPhase = readLedF();
	newPhase = readLedF();
	int printCount = 0;
	
	
	//____________________________________Superloop____________________________________________//
	
	
	while (1)
	{
		//GPIOE->BSRR = (0x01U);										// Oszilloskop  D16
		newPhase = readLedF();																// Aktuelle Phase von den GPIOs lesen
		int time2 = getTimeM();								// Zeitdifferenz berechnen
		
		if (setPhase(newPhase, currPhase))															// Encoder-Status abfragen (gibt -1 zurück bei Fehler somit true)
		{
			printError();
			while (!readButtonF(6)) {}								// Warte so lange bis S6 gedrückt wird. Dann Reset Error
			clearError();
			resetCount();
			currPhase = newPhase = readLedF();
		}
		
		
		double period = getPeriodM(time1, time2);
		
		if (period > 200.0 || (period > ZEITFENSTER && printCount != 0 && newPhase != currPhase)) {						// Nur berechnen und drucken wenn genug Zeit vergangen ist (ZEITFENSTER)
			int count2 = getCount();
			
			if (printCount == 0) {															// Berechnung
				//winkel1 , geschw1
			}
			
			winkel1 = calcWinkel();
			geschw1 = calcGeschw(count1, count2, period);
			
			printWinkel(winkel1, printCount);										// Ausgabe
			printGeschw(geschw1, printCount);
			printCount++;
			
			
			if (printCount >=10) {
				printCount = 0;
				//count1 = count2
				//time1 = time2
					
			}		
			
				count1 = count2;													// Werte für nächsten Durchlauf aktualisieren
				time1 = time2;
			
		}
		//GPIOE->BSRR = (0x01U << 16);						// Oszilloskop
		currPhase = newPhase;
		
	}
}
