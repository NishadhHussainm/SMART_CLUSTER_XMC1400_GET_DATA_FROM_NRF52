/*
 * Uart_Data.c
 *
 *  Created on: 16-Nov-2022
 *      Author: GET004
 */

#include "DAVE.h"
#include "Uart_Data.h"
#include "PETS_CAN_DATA.h"
#include "Spi_Data.h"
#include "Push_Button.h"

uint8_t To_imx[UARTMAXSIZE] = {0};
uint8_t From_imx[UART_RX_MAXSIZE] = {0};
Uart_Genrl_S Uart_Genrl_T;   //general data
Uart_Phcall_S Uart_Phcall_T; //phone call data
Uart_Navi_S Uart_Navi_T;     //navigation data
Uart_Music_S Uart_Music_T;   //music data


/*Timer called every 50ms*/

void Timer_50_ms(void)
{
   // TIMER_ClearEvent(&TIMER_0);
 	set_Button();
 	setUartarr(To_imx);
 	UART_Transmit(&UART_0,To_imx, UARTMAXSIZE);
}

void Uart_Rx(void)
{
	UART_Receive(&UART_0, From_imx, UART_RX_MAXSIZE);  // Receive data from IMX
	DIGITAL_IO_ToggleOutput(&DIGITAL_IO_6);          //InBuild LED (P4.3)
}

void setUartarr(uint8_t* To_imx)
{
	setBle_Genrl_Data();
	memcpy(To_imx ,&Uart_Genrl_T,sizeof(Uart_Genrl_T));

	if((Uart_Genrl_T.ble_Data_Availablity == SET) && (Uart_Genrl_T.ble_phone_call_data == SET))
	{
		setBle_Phcall_Data();
		memcpy(To_imx + ENDOFSTART,&Uart_Phcall_T,sizeof(Uart_Phcall_T));
	}

	else if((Uart_Genrl_T.ble_Data_Availablity == SET) && (Uart_Genrl_T.ble_navigation_data == SET))
	{
		setBle_Navi_Data();
		memcpy(To_imx + ENDOFSTART,&Uart_Navi_T,sizeof(Uart_Navi_T));
	}

	else if((Uart_Genrl_T.ble_Data_Availablity == SET) && (Uart_Genrl_T.ble_music_player_data == SET))
	{
		setBle_Music_Player_Data();
		memcpy(To_imx + ENDOFSTART,&Uart_Music_T,sizeof(Uart_Music_T));
	}

}

void setUartdata1aa()
{
	Uart_Genrl_T.Ride_Mode = CanH_Get_CAN1aa_Ride_Mode();
	Uart_Genrl_T.Low_Battery = CanH_Get_CAN1aa_Low_Battery();
	Uart_Genrl_T.Side_Stand = CanH_Get_CAN1aa_Side_Stand();
	Uart_Genrl_T.Right_Indicator = CanH_Get_CAN1aa_Right_Indicator();
	Uart_Genrl_T.Left_Indicator = CanH_Get_CAN1aa_Left_Indicator();
	Uart_Genrl_T.High_Beam = CanH_Get_CAN1aa_High_Beam();
	Uart_Genrl_T.Low_Beam = CanH_Get_CAN1aa_Low_Beam();
	Uart_Genrl_T.Parking_Alert = CanH_Get_CAN1aa_Parking_Alert();
	Uart_Genrl_T.Vehicle_Battery_Percentage = CanH_Get_Vehicle_Battery_Percentage();
	Uart_Genrl_T.Vehicle_speed = CanH_Get_Vehicle_Speed();
	Uart_Genrl_T.TripA_Battery_Consumption = CanH_Get_TripA_Battery_Consumption();
	Uart_Genrl_T.TripB_Battery_Consumption = CanH_Get_TripB_Battery_Consumption();
	Uart_Genrl_T.Odometer_1 = CanH_Get_Odometer_1();
	Uart_Genrl_T.Odometer_2 = CanH_Get_Odometer_2();
	Uart_Genrl_T.Odometer_3 = CanH_Get_Odometer_3();
}

void setUartdata2aa()
{
	Uart_Genrl_T.Odometer_1 = CanH_Get_Odometer_1();
	Uart_Genrl_T.Odometer_2 = CanH_Get_Odometer_2();
	Uart_Genrl_T.Odometer_3 = CanH_Get_Odometer_3();
	Uart_Genrl_T.Front_TPMS = CanH_Get_Front_TPMS();
	Uart_Genrl_T.Rear_TPMS = CanH_Get_Rear_TPMS();
	Uart_Genrl_T.Rest_Range_1 = CanH_Get_Rest_Range_1();
	Uart_Genrl_T.Rest_Range_2 = CanH_Get_Rest_Range_2();
	Uart_Genrl_T.Rest_Range_3 = CanH_Get_Rest_Range_3();

	Uart_Genrl_T.TripA_Time_Hr = CanH_Get_TripA_Time_Hr();
	Uart_Genrl_T.TripA_Time_Min= CanH_Get_TripA_Time_Min();
	Uart_Genrl_T.TripB_Time_Hr = CanH_Get_TripB_Time_Hr();
}

void setUartdata3aa()
{
	Uart_Genrl_T.TripA_Time_Hr = CanH_Get_TripA_Time_Hr();
	Uart_Genrl_T.TripA_Time_Min= CanH_Get_TripA_Time_Min();
	Uart_Genrl_T.TripB_Time_Hr = CanH_Get_TripB_Time_Hr();
	Uart_Genrl_T.TripB_Time_Min = CanH_Get_TripB_Time_Min();

	Uart_Genrl_T.TripA_1 = CanH_Get_TripA_1();
	Uart_Genrl_T.TripA_2 = CanH_Get_TripA_2();
	Uart_Genrl_T.TripA_3 = CanH_Get_TripA_3();

	Uart_Genrl_T.TripB_1 = CanH_Get_TripB_1();
	Uart_Genrl_T.TripB_2 = CanH_Get_TripB_2();
	Uart_Genrl_T.TripB_3 = CanH_Get_TripB_3();
	Uart_Genrl_T.CAN_Reserved_Bit = CAN_Reserved_Bit();
}

void set_Button(void)
{
	Uart_Genrl_T.Msg_Start_id= UARTID;
	Uart_Genrl_T.Msg_Can_id= UARTID;
	Uart_Genrl_T.Msg_Button_id= UARTID;
	Uart_Genrl_T.Msg_Ble_id= UARTID;
	Uart_Genrl_T.Button_state=Set_button();
	Uart_Genrl_T.Button_state_Reserved = set_Button_reserved_bit();
}
void setBle_Genrl_Data(void)
{

	Uart_Genrl_T.ble_connectivity_status = set_ble_connectivity_status();
	Uart_Genrl_T.ble_Data_Availablity = set_ble_Data_Availablity();
	Uart_Genrl_T.ble_general_data =set_ble_general_data();
	Uart_Genrl_T.ble_phone_call_data =set_ble_phone_call_data();
	Uart_Genrl_T.ble_navigation_data =set_ble_navigation_data();
	Uart_Genrl_T.ble_music_player_data =set_ble_music_player_data();
	Uart_Genrl_T.ble_gopro_data =set_ble_gopro_data();
	Uart_Genrl_T.ble_paired_devices =set_ble_paired_devices();
	Uart_Genrl_T.ble_reserved_1 =set_ble_reserved_1();
	Uart_Genrl_T.Ble_Total_message_size = set_Total_message_size();
	Uart_Genrl_T.Reserved_1 =set_Reserved_1();
}
void setBle_Phcall_Data(void)
{

	Uart_Phcall_T.Phone_Data_Availablity =set_Phone_Data_Availablity();
	Uart_Phcall_T.Phone_Message_Notification =set_Phone_Message_Notification();
	Uart_Phcall_T.Phone_Incomming_call =set_Phone_Incomming_call();
	Uart_Phcall_T.Phone_Ongoing_Call_notifiaction =set_Phone_Ongoing_Call_notifiaction();
	Uart_Phcall_T.Phone_End_Call =set_Phone_End_Call();
	Uart_Phcall_T.Phone_Missed_Call_Notification =set_Phone_Missed_Call_Notification();
	Uart_Phcall_T.phone_reserved_1 =set_phone_reserved_1();
	Uart_Phcall_T.Phone_volume=set_Phone_volume();
	Uart_Phcall_T.Phone_Ongoing_call_Timer_Start =set_Phone_Ongoing_call_Timer_Start();
	Uart_Phcall_T.Phone_Ongoing_call_Timer_Stop=set_Phone_Ongoing_call_Timer_Stop(); //next line reserved dosn't exist
	Uart_Phcall_T.Phone_Caller_Name_Identifier=set_Phone_Caller_Name_Identifier();
	Uart_Phcall_T.Call_name_size = set_Call_name_size();
	memcpy(&Uart_Phcall_T.Call_name,set_Call_name(),M_CALL_NAME);
	Uart_Phcall_T.Phone_Caller_Number_Identifier = set_Phone_Caller_Number_Identifier();
	Uart_Phcall_T.Call_num_size = set_Call_num_size();
	memcpy(&Uart_Phcall_T.Call_num,set_Call_num(),M_CALL_NUM);
	memcpy(&Uart_Phcall_T.Reserved_2,set_Reserved_2(),M_PHCALL_RESERVED_2);
}

	/* Navigation */

void setBle_Navi_Data(void)
{
	Uart_Navi_T.Navigation_Data_Availablity =set_Navigation_Data_Availablity();
	Uart_Navi_T.Navigation_Turn_Type =set_Navigation_Turn_Type();
	Uart_Navi_T.Navigation_Turn_Distance_Identifier =set_Navigation_Turn_Distance_Identifier();
	Uart_Navi_T.Navigation_Turn_Distance_Size =set_Navigation_Turn_Distance_Size();
	memcpy(&Uart_Navi_T.Navigation_Turn_Distance,set_Navigation_Turn_Distance(),M_NAVIGATION_TURN_DISTANCE);
	Uart_Navi_T.Navigation_Overall_Distance_Identifier =set_Navigation_Overall_Distance_Identifier();
	Uart_Navi_T.Navigation_Overall_Distance_Size =set_Navigation_Overall_Distance_Size();
	memcpy(&Uart_Navi_T.Navigation_Overall_Distance,set_Navigation_Overall_Distance(),M_NAVIGATION_OVERALL_DISTANCE);
	Uart_Navi_T.Navigation_ETA_Identifier =set_Navigation_ETA_Identifier();
	Uart_Navi_T.Navigation_ETA_Hours =set_Navigation_ETA_Hours();
	Uart_Navi_T.Navigation_ETA_Minutes =set_Navigation_ETA_Minutes();
	memcpy(&Uart_Navi_T.Navigation_Reserved,set_Navigation_Reserved(),M_NAVIGATION_RESERVED);
}

/*Music player   */


void setBle_Music_Player_Data(void)
{
	Uart_Music_T.Music_Player_Data_Availablity =set_Music_Player_Data_Availablity();
	Uart_Music_T.Music_Player_Song_Status =set_Music_Player_Song_Status();
	Uart_Music_T.Music_Player_reserved_1 =set_Music_Player_reserved_1();
	Uart_Music_T.Music_Player_Volume =set_Music_Player_Volume();
	Uart_Music_T.Music_Player_Song_Name_Identifier =set_Music_Player_Song_Name_Identifier();
	Uart_Music_T.Music_Player_Song_Name_Size = set_Music_Player_Song_Name_Size();
	memcpy(&Uart_Music_T.Music_Player_Song_Name,set_Music_Player_Song_Name(),M_MUSIC_PLAYER_SONG_NAME);
	Uart_Music_T.Music_Player_Total_Min = set_Music_Player_Total_Min();
	Uart_Music_T.Music_Player_Total_Sec =set_Music_Player_Total_Sec();
	Uart_Music_T.Music_Player_Current_Playing_Min =set_Music_Player_Current_Playing_Min();
	Uart_Music_T.Music_Player_Current_Playing_Sec =set_Music_Player_Current_Playing_Sec();
	memcpy(&Uart_Music_T.Music_Player_Reserved,set_Music_Player_Reserved(),M_MUSIC_PLAYER_RESERVED);
}


