#include "LCD_GUI.h"
#include "LCD_Demos.h"
#include "lcd.h"
#include <stdint.h>
#include <stdio.h>


// My comment lol

void print (double drehwinkel, double drehgeschwindigkeit) {
	
	char wink[12];
	sprintf(wink, "%.2f", drehwinkel);
	lcdGotoXY(13,3);
	lcdPrintS(wink);
	
	char dreh[12];
	sprintf(dreh, "%.2f", drehgeschwindigkeit);
	lcdGotoXY(13,9);
	lcdPrintS(dreh);
	
}
