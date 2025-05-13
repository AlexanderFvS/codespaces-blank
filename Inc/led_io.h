#include "led_io.h"
#include <stdio.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"


/*
 ****************************************************************************************
 *  @brief      Bekommt eine Bitmaske und schaltet die LEDs in GPIOF an, bzw. aus.
 *
 *  @param  		mask: int mit der Bitmaske
 *
 *  @return     void
 ****************************************************************************************/
 
void setLedD(int mask)
{
	GPIOD->ODR = mask & 0xFFu;
}

/*
 ****************************************************************************************
 *  @brief      Setzt alle LEDs in GPIOD wieder auf 0.
 *
 *
 *  @return     void
 ****************************************************************************************/

void resetLedD()
{
	GPIOD->ODR = 0;
}

/*
 ****************************************************************************************
 *  @brief      Bekommt eine Bitmaske und schaltet die LEDs in GPIOF an, bzw. aus.
 *
 *  @param  		offset: int mit dem Offset der entsprechenden LED
 *
 *  @return     void
 ****************************************************************************************/

void setLedE(int offset)
{
	GPIOE->ODR = 0x01u << offset;
}

/*
 ****************************************************************************************
 *  @brief      Liest die Inputs an GPIOF ein.
 *
 *
 *  @return     int: PF0, PF1
 ****************************************************************************************/

int readLedF()
{
	return GPIOF->IDR & 0x03u;
}

/*
 ****************************************************************************************
 *  @brief      Prüft ob ein Input an GPIOF geschaltet ist.
 *
 *  @param  		offset: int mit dem Offsets des Inputs
 *
 *  @return     bool: true wenn geschaltet, false wenn nicht.
 ****************************************************************************************/

bool readButtonF(int offset)
{
	int maskSet = (0x01u << offset);
	int input = GPIOF->IDR;
	
	return maskSet != (input & maskSet);
}
