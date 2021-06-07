#include <LPC21xx.H>
#include "Led.h"

#define LED0_bm 	 (1<<16)
#define LED1_bm 	 (1<<17)
#define LED2_bm 	 (1<<18)
#define LED3_bm 	 (1<<19)

enum StepsLeds{ToLeft, ToRight};

void LedInit(){
  IO1DIR = (IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm);
  }

void LedOn(unsigned char uc_Nr_LED){
	IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	switch(uc_Nr_LED){
		case 0: IO1SET = LED0_bm;
			break;
		case 1: IO1SET = LED1_bm;
			break;
		case 2: IO1SET = LED2_bm;
			break;
		case 3: IO1SET = LED3_bm;
			break;
		default: break;
	}
}

void LedStep(enum StepsLeds eDirection){
	static unsigned int suiTurnToSide;
	if (eDirection == ToLeft){
		suiTurnToSide++;
	}
	if (eDirection == ToRight){
		suiTurnToSide--;
	}
	LedOn(suiTurnToSide%4);
}

void LedStepRight(void) {
  LedStep(ToRight);
  }
void LedStepLeft(void){
  LedStep(ToLeft);
  }
