#include <stdio.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"


void setLedE (int num) {
	
	int maskSet = (0x01U << num);
	GPIOE->ODR = GPIOE->ODR | maskSet;
	
}

void clearLedE (int num) {
	
	int maskSet = (0x01U << num);
	GPIOE->ODR = GPIOE->ODR & ~maskSet;
	
}

void setLedMaskD (int mask) {
	
	int maskSet = (mask & 0b11111111);
	GPIOD->ODR = maskSet;
	
}

void resetLedMaskD () {
	
	GPIOD->ODR = 0b00000000;
	
}

bool readButton (int num) {
	
	int maskSet = (0x01U << num);
	int input = GPIOF->IDR;
		
	return maskSet != (input & maskSet);
	
}
