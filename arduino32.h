// Arduino32.h
// Jonathan Lukas Goldnau-Vogt
// Used to run Arduino libraries on STM32F4xx
#include <stdbool.h>
#include <stdint.h>
#include <algorithm>
#include <math.h>
#include "tm_stm32_delay.h"
#include "tm_stm32_gpio.h"
#include "defines.h"

typedef uint8_t boolean;
typedef uint8_t byte;
    


	
#define min(a,b) ((a)<(b)?(a):(b))		
#define max(a,b) ((a)>(b)?(a):(b))	
#define abs(x) ((x)>0?(x):-(x))	
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))		
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))		
#define radians(deg) ((deg)*DEG_TO_RAD)		
#define degrees(rad) ((rad)*RAD_TO_DEG)		
#define sq(x) ((x)*(x))



uint32_t micros(void);

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);
GPIO_TypeDef* pinPort(uint8_t pin);
uint16_t gpioPin(uint8_t pin);

void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
