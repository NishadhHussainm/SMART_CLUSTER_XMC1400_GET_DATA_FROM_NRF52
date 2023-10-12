/*
 * PETS_CAN_DATA.c
 *
 *  Created on: 27-Sep-2022
 *      Author: shiva
 */
#include "PETS_CAN_DATA.h"


CAN1aa msg1aa;
CAN2aa msg2aa;
CAN2cc msg2cc;

/*Function called if any data received in can*/

/*Function called for data received under can id 1AA*/
void Can1aa_rx_callback(void)
{
	DIGITAL_IO_SetOutputLow(&DIGITAL_IO_6);
		//DIGITAL_IO_SetOutputLow(&DIGITAL_IO_6);
		XMC_CAN_MO_t* lmsgobjct_ptr_0 = CAN_NODE_0.lmobj_ptr[0]->mo_ptr; // CAN_NODE_1 transmit message object pointer
		CAN_NODE_MO_Receive((void*)CAN_NODE_0.lmobj_ptr[0]);

		/*Function to set received can data in the predefined structure */
		CANH_SetCAN1aa((void*)lmsgobjct_ptr_0->can_data_byte);
		setUartdata1aa();
}

/*Function called for data received under can id 2AA*/
void Can2aa_rx_callback(void)
{
	//DIGITAL_IO_SetOutputLow(&DIGITAL_IO_6);
	XMC_CAN_MO_t* lmsgobjct_ptr_1 = CAN_NODE_0.lmobj_ptr[1]->mo_ptr; // CAN_NODE_1 transmit message object pointer
	CAN_NODE_MO_Receive((void*)CAN_NODE_0.lmobj_ptr[1]);
	CANH_SetCAN2aa((void*)lmsgobjct_ptr_1->can_data_byte);

	setUartdata2aa();
}

/*Function called for data received under can id 3AA*/
void Can3aa_rx_callback(void)
{
	//DIGITAL_IO_SetOutputLow(&DIGITAL_IO_6);
		XMC_CAN_MO_t* lmsgobjct_ptr_2 = CAN_NODE_0.lmobj_ptr[2]->mo_ptr; // CAN_NODE_1 transmit message object pointer
		CAN_NODE_MO_Receive((void*)CAN_NODE_0.lmobj_ptr[2]);
		CANH_SetCAN3aa((void*)lmsgobjct_ptr_2->can_data_byte);
		setUartdata3aa();
}

void CANH_SetCAN1aa(uint8_t* arraycandatabyte[])
{
	memcpy(&msg1aa ,arraycandatabyte,8);
}

void CANH_SetCAN2aa(uint8_t* arraycandatabyte)
{
	memcpy(&msg2aa ,arraycandatabyte,8);
}

void CANH_SetCAN3aa(uint8_t* arraycandatabyte[])
{
	memcpy(&msg2cc ,arraycandatabyte,8);
}

uint8_t CanH_Get_CAN1aa_Ride_Mode(void)
{
	return msg1aa.Ride_Mode;
}
uint8_t CanH_Get_CAN1aa_Low_Battery(void)
{
	return msg1aa.Low_Battery;
}
uint8_t CanH_Get_CAN1aa_Side_Stand(void)
{
	return msg1aa.Side_Stand;
}
uint8_t CanH_Get_CAN1aa_Right_Indicator(void)
{
	return msg1aa.Right_Indicator;
}
uint8_t CanH_Get_CAN1aa_Left_Indicator(void)
{
	return msg1aa.Left_Indicator;
}
uint8_t CanH_Get_CAN1aa_High_Beam(void)
{
	return msg1aa.High_Beam;
}
uint8_t CanH_Get_CAN1aa_Low_Beam(void)
{
	return msg1aa.Low_Beam;
}
uint8_t CanH_Get_CAN1aa_Parking_Alert(void)
{
	return msg1aa. Parking_Alert;
}

uint8_t CanH_Get_Vehicle_Battery_Percentage(void)
{
	return msg1aa.Vehicle_Battery_Percentage;
}
uint8_t CanH_Get_Vehicle_Speed(void)
{
	return msg1aa.Vehicle_speed;
}
uint8_t CanH_Get_TripA_Battery_Consumption(void)
{
	return msg1aa.TripA_Battery_Consumption;
}
uint8_t CanH_Get_TripB_Battery_Consumption(void)
{
	return msg1aa.TripB_Battery_Consumption;
}
uint8_t CanH_Get_Odometer_1(void)
{
	return msg1aa.Odometer_1;
}
uint8_t CanH_Get_Odometer_2(void)
{
	return msg1aa.Odometer_2;
}
uint8_t CanH_Get_Odometer_3(void)
{
	return msg1aa.Odometer_3;
}


uint8_t CanH_Get_Front_TPMS(void)
{
	return msg2aa.Front_TPMS;
}
uint8_t CanH_Get_Rear_TPMS(void)
{
	return msg2aa.Rear_TPMS;
}

uint8_t CanH_Get_Rest_Range_1(void)
{
	return msg2aa.Rest_Range_1;
}
uint8_t CanH_Get_Rest_Range_2(void)
{
	return msg2aa.Rest_Range_2;
}
uint8_t CanH_Get_Rest_Range_3(void)
{
	return msg2aa.Rest_Range_3;
}

uint8_t CanH_Get_TripA_Time_Hr(void)
{
	return msg2aa.TripA_Time_Hr;
}
uint8_t CanH_Get_TripA_Time_Min(void)
{
	return msg2aa.TripA_Time_Min;
}
uint8_t CanH_Get_TripB_Time_Hr(void)
{
	return msg2aa.TripB_Time_Hr;
}



uint8_t CanH_Get_TripB_Time_Min(void)
{
	return msg2cc.TripB_Time_Min;
}
uint8_t CanH_Get_TripA_1(void)
{
	return msg2cc.TripA_1;
}
uint8_t CanH_Get_TripA_2(void)
{
	return msg2cc.TripA_2;
}
uint8_t CanH_Get_TripA_3(void)
{
	return msg2cc.TripA_3;
}
uint8_t CanH_Get_TripB_1(void)
{
	return msg2cc.TripB_1;
}
uint8_t CanH_Get_TripB_2(void)
{
	return msg2cc.TripB_2;
}
uint8_t CanH_Get_TripB_3(void)
{
	return msg2cc.TripB_3;
}
uint8_t CAN_Reserved_Bit(void)
{
	return msg2cc.CAN_Reserved_Bit;
}
