/*
 * ble_general_data.h
 *
 *  Created on: 14-Dec-2022
 *      Author: GET004
 */

#include <stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef BLE_GENERAL_DATA_H_
#define BLE_GENERAL_DATA_H_

typedef struct
{
	uint8_t ble_connectivity_status;
	struct {
		uint8_t ble_No_Data_Available;
		uint8_t ble_general_data;
		uint8_t ble_phone_call_data;
		uint8_t ble_navigation_data;
		uint8_t ble_music_player_data;
		uint8_t ble_gopro_data;
		uint8_t ble_paired_data;
		uint8_t ble_reserved_1;
	};
	uint8_t Total_message_size;
}ble_gnrl;

void setBlegnrldata(uint8_t *ble_Data);
void getBlegnrldata(uint8_t *ble_Data);
#endif /* BLE_GENERAL_DATA_H_ */
