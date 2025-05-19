#include "led_io.h"
#include <stdio.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"



void setLedD(int mask)
{
	GPIOD->ODR = mask & 0xFFu;
}


void resetLedD()
{
	GPIOD->ODR = 0;
}


void setLedE(int offset)
{
	GPIOE->ODR = 0x01u << offset;
}


int readLedF()
{
	return GPIOF->IDR & 0x03u;
}


bool readButtonF(int offset)
{
	int maskSet = (0x01u << offset);
	int input = GPIOF->IDR;
	
	return maskSet != (input & maskSet);
}
