/*
arduino32.cpp
Provides missing arduino macros and functions needed by the stepper library 
Copyright (C) 2016  Jonathan Goldnau-Vogt

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "arduino32.h"

uint32_t micros(void){
    return HAL_GetuTick();
    
}

void pinMode(uint8_t pin, uint8_t mode){
    TM_GPIO_Init(pinPort(pin), (uint16_t)gpioPin(pin), mode ? TM_GPIO_Mode_OUT : TM_GPIO_Mode_IN , TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
}
void digitalWrite(uint8_t pin, uint8_t state){
	// Here I am speeding up my specific pins, general case below

    if(pin == PORTA+2){
        TM_GPIO_SetPinValue(GPIOA, GPIO_PIN_2, state);
        return;
    }
    if(pin == PORTA+5){
        TM_GPIO_SetPinValue(GPIOA, GPIO_PIN_5, state);
        return;        
    }
    if(pin == PORTC+3){
        TM_GPIO_SetPinValue(GPIOC, GPIO_PIN_3, state);
        return;
    }
    if(pin == PORTC+4){
        TM_GPIO_SetPinValue(GPIOC, GPIO_PIN_4, state);
        return;
    }
    // General case here
	if(state == HIGH) {
        TM_GPIO_SetPinHigh(pinPort(pin), gpioPin(pin));
    }
	if(state == LOW) {
        TM_GPIO_SetPinLow(pinPort(pin), gpioPin(pin));
    }
    
}
int digitalRead(uint8_t){
    return 1;//not implemented
}
    
int analogRead(uint8_t){
    return 1;//not implemented
}
void analogReference(uint8_t mode){
    //not implemented
}
void analogWrite(uint8_t, int){
   //not implemented 
}

void delayMicroseconds(unsigned int us){
    Delay(us);
    return;
}
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout){
    return 1;
}





GPIO_TypeDef* pinPort(uint8_t pin){
    
    
	GPIO_TypeDef* gpioPort;
	//determine port letter
		if(pin < 15) gpioPort = GPIOA;
		else{
			pin-=16;
			if(pin < 15) gpioPort = GPIOB;
			else{
				pin-=16;
				if(pin < 15) gpioPort = GPIOC;
				else{
					pin-=16;
					if(pin < 15) gpioPort = GPIOD;
					else{
						pin-=16;
						if(pin < 15) gpioPort = GPIOE;
						else{
							pin-=16;
							if(pin < 15) gpioPort = GPIOF;
							else{
								pin-=16;
								if(pin < 15) gpioPort = GPIOG;
								else{
									return 0;
								//add more later?
									
								}
							}
						}
					}
				}
			}
		}		
	
	return gpioPort;
}
uint16_t gpioPin(uint8_t pin){
		uint16_t gpioPin = 0;
		uint8_t _pin = (pin)%16;
		//determine pin number on port
		switch (_pin){
			case 0:
				gpioPin = GPIO_PIN_0;
				break;
			case 1:
				gpioPin = GPIO_PIN_1;
				break;
			case 2:
				gpioPin = GPIO_PIN_2;
				break;
			case 3:
				gpioPin = GPIO_PIN_3;
				break;
			case 4:
				gpioPin = GPIO_PIN_4;
				break;
			case 5:
				gpioPin = GPIO_PIN_5;
				break;
			case 6:
				gpioPin = GPIO_PIN_6;
				break;
			case 7:
				gpioPin = GPIO_PIN_7;
				break;
			case 8:
				gpioPin = GPIO_PIN_8;
				break;
			case 9:
				gpioPin = GPIO_PIN_9;
				break;
			case 10:
				gpioPin = GPIO_PIN_10;
				break;
			case 11:
				gpioPin = GPIO_PIN_11;
				break;
			case 12:
				gpioPin = GPIO_PIN_12;
				break;
			case 13:
				gpioPin = GPIO_PIN_13;
				break;
			case 14:
				gpioPin = GPIO_PIN_14;
				break;
			case 15:
				gpioPin = GPIO_PIN_15;
				break;
			//default:
				
			
				
		}
		return gpioPin;
	}
    
