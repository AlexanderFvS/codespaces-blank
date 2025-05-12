#include <stdio.h>
#include "display_output.h"
#include "lcd.h"

void printLabels()
{
	lcdGotoXY(1,1);
	lcdPrintS("Drehwinkel in Grad");
	
	lcdGotoXY(1,4);
	lcdPrintS("Drehgesch. in Grad/Sek.");
}

void printError()
{
	lcdGotoXY(1, 8);
	lcdPrintS("ERROR: INVALID STATE");
}

void clearError()
{
	lcdGotoXY(1, 8);
	lcdPrintS(" ");																						// Funktion löscht alles rechts vom Cursor
}

void printWinkel(double winkel)
{
	char temp[12];
	sprintf(temp, "%5.1f", winkel);														// 5.1 reserviert 5 chars vor dem komme und 1 Nachkommastelle, da die Berechnung nicht mehr darstellt
	lcdGotoXY(1,2);
	lcdPrintReplS(temp);
}

void printGeschw(double geschw)
{
	char temp[12];
	sprintf(temp, "%5.1f", geschw);
	lcdGotoXY(1,5);
	lcdPrintReplS(temp);
}
