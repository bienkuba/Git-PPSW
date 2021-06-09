#include "Led.h" //testgit
#include "Keyboard.h"

enum LedState {LED_LEFT, LED_RIGHT, LED_STOP};
enum LedState eLedState = LED_STOP;

void Delay(int iTime){
	int iDelay = 0;
  for(iDelay = 0; iDelay <=(iTime*5455); iDelay++);
}

int main(void){
	LedInit();
	KeyboardInit();
	while(1){
		switch(eLedState){
			case LED_LEFT:
				if (eKeyboardRead() == BUTTON_1){
					eLedState = LED_STOP;
				}
				else{
					LedStepLeft();
					eLedState = LED_LEFT;
				}
				break;
			case LED_RIGHT:
				if (eKeyboardRead() == BUTTON_1){
					eLedState = LED_STOP;
				}
				else{
					LedStepRight();
					eLedState = LED_RIGHT;
				}
				break;
			case LED_STOP:
				if (eKeyboardRead() == BUTTON_0){ 
					eLedState = LED_LEFT;
				}
				else if (eKeyboardRead() == BUTTON_2){
					eLedState = LED_RIGHT;
				}
				else{
					eLedState = LED_STOP;
				}
				break;
	}
  Delay(160); 
 }
}
