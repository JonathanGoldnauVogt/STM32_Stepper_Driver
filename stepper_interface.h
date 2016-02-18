/*
stepper_interface.h
Use this file to provide c access to c++ functions. Change the file to suit your needs
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
#include "stdint.h"
#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

//#include "tm_stm32f4_delay.h"
//#include "tm_stm32f4_gpio.h"

EXTERNC void stepperProgram(void);
EXTERNC void initSteppers(void);
EXTERNC void setSteppingMode(uint8_t);
EXTERNC void setStepperMaxSpeed(uint16_t);
EXTERNC void setStepperAccel(uint16_t);
EXTERNC void setStepperSpeed(float);
EXTERNC void runSpeed(void);
EXTERNC void dWrite(uint8_t, uint8_t);
EXTERNC void stepperMoveTo(int16_t);
EXTERNC void stepperRun(void);
EXTERNC int32_t stepperCurrentPosition(void);
EXTERNC void stepperMove(int16_t);
EXTERNC void setStepperCurrentPosition(uint16_t);
