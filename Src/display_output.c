#include <stdio.h>
#include "display_output.h"
#include "lcd.h"

void printLabels()
{
	lcdGotoXY(1,1);
	lcdPrintS("Drehwinkel:");
	
	lcdGotoXY(1,4);
	lcdPrintS("Drehgesch.:");
}

void printError()
{
	lcdGotoXY(1, 8);
	lcdPrintS("ERROR: INVALID STATE");
}

void clearError()
{
	lcdGotoXY(1, 8);
	lcdPrintS(" ");
}

void printWinkel(double winkel)
{
	char temp[12];
	sprintf(temp, "%.2f", winkel);
	lcdGotoXY(1,2);
	lcdPrintS(temp);
	lcdPrintS(" Grad");
}

void printGeschw(double geschw)
{
	char temp[12];
	sprintf(temp, "%.2f", geschw);
	lcdGotoXY(1,5);
	lcdPrintS(temp);
	lcdPrintS(" Grad/Sek.");
}
