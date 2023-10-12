/*
 * Push_Button.h
 *
 *  Created on: 28-Nov-2022
 *      Author: GET004
 */

#include<stdint.h>

#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

typedef struct
{
	uint8_t button_state : 3;
	uint8_t button_state_r: 5;
	uint8_t button_Reserved;
}Push_T;

uint8_t Set_button(void);
uint8_t set_Button_reserved_bit(void);

#endif /* PUSH_BUTTON_H_ */
