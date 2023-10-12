/*
 * Push_Button.c
 *
 *  Created on: 28-Nov-2022
 *      Author: GET004
 */
#include "Push_Button.h"
#include "DAVE.h"


Push_T Push;
/*Function called to  set Push Button values in uart array*/
uint8_t Set_button(void)
{

	// Check status of the gpio and set value to Push.button_state accordingly
	if((DIGITAL_IO_GetInput(&DIGITAL_IO_0)) == 1)
	{
		Push.button_state = Push.button_state | (0x1);
	}
	else if((DIGITAL_IO_GetInput(&DIGITAL_IO_1)) == 1)
	{
		Push.button_state = Push.button_state | (0x2);
	}
	else  if((DIGITAL_IO_GetInput(&DIGITAL_IO_2)) == 1)
	{
		Push.button_state = Push.button_state | (0x3);
	}
	else if((DIGITAL_IO_GetInput(&DIGITAL_IO_3)) == 1)
	{
		Push.button_state = Push.button_state | (0x4);
	}
	else if((DIGITAL_IO_GetInput(&DIGITAL_IO_4)) == 1)
	{
		Push.button_state = Push.button_state | (0x5);
	}
	else
	{
		Push.button_state = Push.button_state & ~(0x7);
	}

	return Push.button_state;

}

uint8_t set_Button_reserved_bit(void)
{
	Push.button_Reserved = 0;
	return Push.button_Reserved;
}
