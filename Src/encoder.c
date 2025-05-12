#include "encoder.h"
#include "led_io.h"

int count = 0;
static Phase currPhase;

Direction transitions[4][4] =
{ //   A   |    D    |    B    |    C
	{NO_CHANGE, BACKWARDS, FORWARDS, INVALID}, // A
	{FORWARDS, NO_CHANGE, INVALID, BACKWARDS}, // D
	{BACKWARDS, INVALID, NO_CHANGE, FORWARDS}, // B
	{INVALID, FORWARDS, BACKWARDS, NO_CHANGE}  // C
};

int getPhase()
{
	int newPhase = readLedF();
	Direction currDir = transitions[currPhase][newPhase];
	currPhase = newPhase;
	
	switch(currDir)
	{
		case FORWARDS:
			count++;
			setLedD(count);
			setLedE(7); // D23
			break;
		
		case BACKWARDS:
			count--;
			setLedD(count);
			setLedE(6); // D22
			break;
		
		case INVALID:
			count = 0;
			resetLedD();
			setLedE(5); // D21
			return -1;
		
		case NO_CHANGE:
			break;
	}
	
	return 0;
}

int getCount()
{
	return count;
}

void resetCount()
{
	count = 0;
}

void setPhase() {
	currPhase = readLedF();
}
