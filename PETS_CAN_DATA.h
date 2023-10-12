/*
 * PETS_CAN_DATA.h
 *
 *  Created on: 27-Sep-2022
 *      Author: shiva
 */

#include <stdio.h>
#include <string.h>

#include "DAVE.h"
#include "Uart_Data.h"

#ifndef PETS_CAN_DATA_H_
#define PETS_CAN_DATA_H_

//0x1AA

typedef struct {
	struct {
	    uint8_t Ride_Mode : 1;
	    uint8_t Low_Battery : 1;
	    uint8_t Side_Stand : 1;
	    uint8_t Right_Indicator : 1;
	    uint8_t Left_Indicator : 1;
	    uint8_t High_Beam : 1;
	    uint8_t Low_Beam : 1;
	    uint8_t Parking_Alert : 1;
	};
	uint8_t Vehicle_Battery_Percentage;
	uint8_t Vehicle_speed;
	uint8_t TripA_Battery_Consumption;
	uint8_t TripB_Battery_Consumption;
	struct{
			uint8_t Odometer_1;
			uint8_t Odometer_2;
			uint8_t Odometer_3;
		};

}CAN1aa;

//0x2AA

void CANH_SetCAN1aa(uint8_t* arraycandatabyte[]);

uint8_t CanH_Get_CAN1aa_Ride_Mode(void);
uint8_t CanH_Get_CAN1aa_Low_Battery(void);
uint8_t CanH_Get_CAN1aa_Side_Stand(void);
uint8_t CanH_Get_CAN1aa_Right_Indicator(void);
uint8_t CanH_Get_CAN1aa_Left_Indicator(void);
uint8_t CanH_Get_CAN1aa_High_Beam(void);
uint8_t CanH_Get_CAN1aa_Low_Beam(void);
uint8_t CanH_Get_CAN1aa_Parking_Alert(void);
uint8_t CanH_Get_Vehicle_Battery_Percentage(void);
uint8_t CanH_Get_Vehicle_Speed(void);
uint8_t CanH_Get_TripA_Battery_Consumption(void);
uint8_t CanH_Get_TripB_Battery_Consumption(void);
uint8_t CanH_Get_Odometer_1(void);
uint8_t CanH_Get_Odometer_2(void);
uint8_t CanH_Get_Odometer_3(void);

typedef struct {

	uint8_t Front_TPMS;
	uint8_t Rear_TPMS;
	struct{
			uint8_t Rest_Range_1;
			uint8_t Rest_Range_2;
			uint8_t Rest_Range_3;
		};
	uint8_t TripA_Time_Hr;
	uint8_t TripA_Time_Min;
	uint8_t TripB_Time_Hr;
}CAN2aa;

void CANH_SetCAN2aa(uint8_t* arraycandatabyte);

uint8_t CanH_Get_Front_TPMS(void);
uint8_t CanH_Get_Rear_TPMS(void);
uint8_t CanH_Get_Rest_Range_1(void);
uint8_t CanH_Get_Rest_Range_2(void);
uint8_t CanH_Get_Rest_Range_3(void);
uint8_t CanH_Get_TripA_Time_Hr(void);
uint8_t CanH_Get_TripA_Time_Min(void);
uint8_t CanH_Get_TripB_Time_Hr(void);

//2CC
typedef struct {

	uint8_t TripB_Time_Min;
	struct{
		uint8_t TripA_1;
		uint8_t TripA_2;
		uint8_t TripA_3;
			};
	struct{
		uint8_t TripB_1;
		uint8_t TripB_2;
		uint8_t TripB_3;
			};
	uint8_t CAN_Reserved_Bit;

}CAN2cc;

void CANH_SetCAN3aa(uint8_t* arraycandatabyte[]);

uint8_t CanH_Get_TripB_Time_Min(void);
uint8_t CanH_Get_TripA_1(void);
uint8_t CanH_Get_TripA_2(void);
uint8_t CanH_Get_TripA_3(void);
uint8_t CanH_Get_TripB_1(void);
uint8_t CanH_Get_TripB_2(void);
uint8_t CanH_Get_TripB_3(void);
uint8_t CAN_Reserved_Bit(void);

#endif /* PETS_CAN_DATA_H_ */

