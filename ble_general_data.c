/*
 * ble_general_data.c
 *
 *  Created on: 14-Dec-2022
 *      Author: GET004
 */
#include "ble_general_data.h"

ble_gnrl ble_gnrl_D;

void setBlegnrldata(uint8_t *ble_Data)
{
	memcpy(&ble_gnrl_D, ble_Data ,sizeof(ble_gnrl_D));
}

void getBlegnrldata(uint8_t *ble_Data)
{

}
