/*
 * Uart_Data.h
 *
 *  Created on: 16-Nov-2022
 *      Author: GET004
 */

#include <stdio.h>
#include<stdbool.h>
#include<stdint.h>

#ifndef UART_DATA_H_
#define UART_DATA_H_

#define UARTMAXSIZE 100
#define UART_RX_MAXSIZE 2
#define ENDOFSTART 34
#define SET 1
#define UARTID '!'
#define M_CALL_NAME 15
#define M_CALL_NUM 13
#define M_PHCALL_RESERVED_2 4
#define M_NAVIGATION_TURN_DISTANCE 10
#define M_NAVIGATION_OVERALL_DISTANCE 10
#define M_NAVIGATION_RESERVED 4
#define M_MUSIC_PLAYER_SONG_NAME 15
#define M_MUSIC_PLAYER_RESERVED 4


void setUartdata1aa(void);
void setUartdata2aa(void);
void setUartdata3aa(void);
void setBle_Genrl_Data(void);
void setBle_Phcall_Data(void);
void setBle_Navi_Data(void);
void set_Button(void);
void setBle_Music_Player_Data(void);
void setUartarr(uint8_t* To_imx);


typedef struct {
	uint8_t Msg_Start_id;
	uint8_t Msg_Can_id;
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

	struct {
		uint8_t Odometer_1;
		uint8_t Odometer_2;
		uint8_t Odometer_3;
	};

	uint8_t Front_TPMS;
	uint8_t Rear_TPMS;
	struct {
		uint8_t Rest_Range_1;
		uint8_t Rest_Range_2;
		uint8_t Rest_Range_3;
	};

	uint8_t TripA_Time_Hr;
	uint8_t TripA_Time_Min;
	uint8_t TripB_Time_Hr;
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
	uint8_t Msg_Button_id;
	uint8_t	Button_state;
	uint8_t	Button_state_Reserved;
	uint8_t Msg_Ble_id;
	uint8_t ble_connectivity_status;
	struct {
		uint8_t ble_Data_Availablity :1;
		uint8_t ble_general_data:1;
		uint8_t ble_phone_call_data:1;
		uint8_t ble_navigation_data:1;
		uint8_t ble_music_player_data:1;
		uint8_t ble_gopro_data:1;
		uint8_t ble_paired_devices:1;
		uint8_t ble_reserved_1:1;
		};
	uint8_t Ble_Total_message_size;
	uint8_t Reserved_1;
}Uart_Genrl_S;

typedef struct{

	struct{
		uint8_t Phone_Data_Availablity:1;
		uint8_t Phone_Message_Notification:1;
		uint8_t Phone_Incomming_call:1;
		uint8_t Phone_Ongoing_Call_notifiaction:1;
		uint8_t Phone_End_Call:1;
		uint8_t Phone_Missed_Call_Notification:1;
		uint8_t phone_reserved_1:2;
	};
	uint8_t Phone_volume;
	struct{
			uint8_t Phone_Ongoing_call_Timer_Start:1;
			uint8_t Phone_Ongoing_call_Timer_Stop:1;
			uint8_t Reserved:6;
		};
	uint8_t Phone_Caller_Name_Identifier;
	uint8_t Call_name_size;
	uint8_t Call_name[15];
	uint8_t Phone_Caller_Number_Identifier;
	uint8_t Call_num_size;
	uint8_t Call_num[13];
	uint8_t Reserved_2[4];
}Uart_Phcall_S;

	/*Navigation*/

typedef struct{

	struct{
	uint8_t Navigation_Data_Availablity:1;
    uint8_t Navigation_Turn_Type:7;
	};
    uint8_t Navigation_Turn_Distance_Identifier;
    uint8_t Navigation_Turn_Distance_Size;
	uint8_t Navigation_Turn_Distance[10];
	uint8_t Navigation_Overall_Distance_Identifier;
	uint8_t Navigation_Overall_Distance_Size;
	uint8_t Navigation_Overall_Distance[10];
	uint8_t Navigation_ETA_Identifier;
	uint8_t Navigation_ETA_Hours;
	uint8_t Navigation_ETA_Minutes;
	uint8_t Navigation_Reserved[4];

}Uart_Navi_S;

/* Music  */

typedef struct{
	struct{
		uint8_t Music_Player_Data_Availablity:1;
		uint8_t Music_Player_Song_Status:1;
		uint8_t Music_Player_reserved_1:6;
	};
		uint8_t Music_Player_Volume;
		uint8_t Music_Player_Song_Name_Identifier;
		uint8_t Music_Player_Song_Name_Size;
		uint8_t Music_Player_Song_Name[15];
		uint8_t Music_Player_Total_Min;
		uint8_t Music_Player_Total_Sec;
		uint8_t Music_Player_Current_Playing_Min;
		uint8_t Music_Player_Current_Playing_Sec;
		uint8_t Music_Player_Reserved[4];
	}Uart_Music_S;

/* typedef struct{
	struct{
		uint8_t Imx_Data_Request:1;
		uint8_t Imx_phone_Data:1;
		uint8_t Imx_Navigation_Data:1;
		uint8_t Imx_Music_Data:1;
		uint8_t Imx_GoPro_Data:1;
		uint8_t Imx_Vehicle_Data:1;
		uint8_t Imx_Ble_data:1;
		uint8_t Imx_Reserved:1;
	};
}Uart_Genrl_Imx_S; */


#endif /* UART_DATA_H_ */
