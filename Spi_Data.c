/*
 * Spi_Data.c
 *
 *  Created on: 23-Nov-2022
 *      Author: GET004
 */
#include "DAVE.h"
#include "Uart_Data.h"
#include "Spi_Data.h"

uint8_t Spi_Data[SPI_MAXSIZE] = {0};
 uint8_t Send_Data[SPI_MAXSIZE] = {0};
Spi_Genrl_S Spi_Genrl_T;     //for spi general data
Spi_Phcall_S Spi_Phcall_T;   //for phone data
Spi_Navi_S Spi_Navi_T;       //for navigation data
Spi_Music_S Spi_Music_T;     //for music player

void Spi_rx(void)
{
	SPI_SLAVE_Receive(&SPI_SLAVE_0, Spi_Data, SPI_REC_SIZE);
	DIGITAL_IO_ToggleOutput(&DIGITAL_IO_6);          //InBuild LED

	if(Spi_Data[SPI_GNRL_DATA_CHECK] == SPI_GNRL_DATA_PASS)
	{
		memcpy(&Spi_Genrl_T ,Spi_Data,sizeof(Spi_Genrl_T));  //General data

		if(Spi_Data[DATA_CHECK] == PH_DATA)                  //Phone data
		{
			memcpy(&Spi_Phcall_T ,Spi_Data + ENDOFGENRL,sizeof(Spi_Phcall_T));
		}

		else if(Spi_Data[DATA_CHECK] == NAVI_DATA)           //Navigation Data
		{
			memcpy(&Spi_Navi_T ,Spi_Data + ENDOFGENRL ,sizeof(Spi_Navi_T));
		}

		else if(Spi_Data[DATA_CHECK] == MUSIC_DATA)           //Music player Data
		{
			memcpy(&Spi_Music_T,Spi_Data + ENDOFGENRL ,sizeof(Spi_Music_T));
		}
	}
	//transfer data
	SPI_SLAVE_Transmit(&SPI_SLAVE_0, Send_Data, sizeof(Send_Data));
}


uint8_t set_ble_connectivity_status(void)
{
	return Spi_Genrl_T.ble_connectivity_status;
}
uint8_t set_ble_Data_Availablity(void)
{
	return Spi_Genrl_T.ble_Data_Availablity;
}
uint8_t set_ble_general_data(void)
{
	return Spi_Genrl_T.ble_general_data;
}
uint8_t set_ble_phone_call_data(void)
{
	return Spi_Genrl_T.ble_phone_call_data;
}
uint8_t	set_ble_navigation_data(void)
{
	return Spi_Genrl_T.ble_navigation_data;
}
uint8_t	set_ble_music_player_data(void)
{
	return Spi_Genrl_T.ble_music_player_data;
}
uint8_t	set_ble_gopro_data(void)
{
	return Spi_Genrl_T.ble_gopro_data;
}
uint8_t	set_ble_paired_devices(void)
{
	return Spi_Genrl_T.ble_paired_devices;
}
uint8_t	set_ble_reserved_1(void)
{
	return Spi_Genrl_T.ble_reserved_1;
}
uint8_t	set_Total_message_size(void)
{
	return Spi_Genrl_T.Total_message_size;
}
uint8_t	set_Reserved_1(void)
{
	return Spi_Genrl_T.Reserved_1;
}

/* Phone_Call */

uint8_t	set_Phone_Data_Availablity(void)
{
	return Spi_Phcall_T.Phone_Data_Availablity;
}
uint8_t	set_Phone_Message_Notification(void)
{
	return Spi_Phcall_T.Phone_Message_Notification;
}
uint8_t	set_Phone_Incomming_call(void)
{
	return Spi_Phcall_T.Phone_Incomming_call;
}
uint8_t	set_Phone_Ongoing_Call_notifiaction(void)
{
	return Spi_Phcall_T.Phone_Ongoing_Call_notifiaction;
}
uint8_t	set_Phone_End_Call(void)
{
	return Spi_Phcall_T.Phone_End_Call;
}
uint8_t	set_Phone_Missed_Call_Notification(void)
{
	return Spi_Phcall_T.Phone_Missed_Call_Notification;
}
uint8_t	set_phone_reserved_1(void)
{
	return Spi_Phcall_T.phone_reserved_1;
}
uint8_t	set_Phone_volume(void)
{
	return Spi_Phcall_T.Phone_volume;
}
uint8_t	set_Phone_Ongoing_call_Timer_Start(void)
{
	return Spi_Phcall_T.Phone_Ongoing_call_Timer_Start;
}
uint8_t	set_Phone_Ongoing_call_Timer_Stop(void)
{
	return Spi_Phcall_T.Phone_Ongoing_call_Timer_Stop;
}
uint8_t	set_Phone_Caller_Name_Identifier(void)
{
	return Spi_Phcall_T.Phone_Caller_Name_Identifier;
}
uint8_t	set_Call_name_size(void)
{
	return Spi_Phcall_T.Call_name_size;
}
uint8_t* set_Call_name(void)
{
	return Spi_Phcall_T.Call_name;
}
uint8_t set_Phone_Caller_Number_Identifier(void)
{
	return Spi_Phcall_T.Phone_Caller_Number_Identifier;
}
uint8_t	set_Call_num_size(void)
{
	return Spi_Phcall_T.Call_num_size;
}
uint8_t*	set_Call_num(void)
{
	return Spi_Phcall_T.Call_num;
}
uint8_t*    set_Reserved_2(void)
{
	return Spi_Phcall_T.Reserved_2;
}

/* Navigation  */

uint8_t   set_Navigation_Data_Availablity(void)
{
	return Spi_Navi_T.Navigation_Data_Availablity;
}
uint8_t   set_Navigation_Turn_Type(void)
{
	return Spi_Navi_T.Navigation_Turn_Type;
}
uint8_t   set_Navigation_Turn_Distance_Identifier(void)
{
	return Spi_Navi_T.Navigation_Turn_Distance_Identifier;
}
uint8_t   set_Navigation_Turn_Distance_Size(void)
{
	return Spi_Navi_T.Navigation_Turn_Distance_Size;
}
uint8_t*  set_Navigation_Turn_Distance(void)
{
	return Spi_Navi_T.Navigation_Turn_Distance;
}
uint8_t   set_Navigation_Overall_Distance_Identifier(void)
{
	return Spi_Navi_T.Navigation_Overall_Distance_Identifier;
}
uint8_t   set_Navigation_Overall_Distance_Size(void)
{
	return Spi_Navi_T.Navigation_Overall_Distance_Size;
}
uint8_t*  set_Navigation_Overall_Distance(void)
{
	return Spi_Navi_T.Navigation_Overall_Distance;
}
uint8_t   set_Navigation_ETA_Identifier(void)
{
	return Spi_Navi_T.Navigation_ETA_Identifier;
}
uint8_t   set_Navigation_ETA_Hours(void)
{
	return Spi_Navi_T.Navigation_ETA_Hours;
}
uint8_t   set_Navigation_ETA_Minutes(void)
{
	return Spi_Navi_T.Navigation_ETA_Minutes;
}
uint8_t*   set_Navigation_Reserved(void)
{
	return Spi_Navi_T.Navigation_Reserved;
}

	 /*music player    */

uint8_t    set_Music_Player_Data_Availablity(void)
{
	return Spi_Music_T.Music_Player_Data_Availablity;
}
uint8_t    set_Music_Player_Song_Status(void)
{
	return Spi_Music_T.Music_Player_Song_Status;
}
uint8_t    set_Music_Player_reserved_1(void)
{
	return Spi_Music_T.Music_Player_reserved_1;
}
uint8_t    set_Music_Player_Volume(void)
{
	return Spi_Music_T.Music_Player_Volume;
}
uint8_t    set_Music_Player_Song_Name_Identifier(void)
{
	return Spi_Music_T.Music_Player_Song_Name_Identifier;
}
uint8_t    set_Music_Player_Song_Name_Size(void)
{
	return Spi_Music_T.Music_Player_Song_Name_Size;
}
uint8_t*   set_Music_Player_Song_Name(void)
{
	return Spi_Music_T.Music_Player_Song_Name;
}
uint8_t    set_Music_Player_Total_Min(void)
{
	return Spi_Music_T.Music_Player_Total_Min;
}
uint8_t    set_Music_Player_Total_Sec(void)
{
	return Spi_Music_T.Music_Player_Total_Sec;
}
uint8_t    set_Music_Player_Current_Playing_Min(void)
{
	return Spi_Music_T.Music_Player_Current_Playing_Min;
}
uint8_t    set_Music_Player_Current_Playing_Sec(void)
{
	return Spi_Music_T.Music_Player_Current_Playing_Sec;
}
uint8_t*   set_Music_Player_Reserved(void)
{
	return Spi_Music_T.Music_Player_Reserved;
}


