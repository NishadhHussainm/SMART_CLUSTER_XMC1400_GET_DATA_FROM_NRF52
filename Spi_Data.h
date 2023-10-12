/*
 * Spi_Data.h
 *
 *  Created on: 23-Nov-2022
 *      Author: GET004
 */

#ifndef SPI_DATA_H_
#define SPI_DATA_H_


#define PH_DATA 5
#define NAVI_DATA 9
#define MUSIC_DATA 17
#define DATA_CHECK 1
#define SPI_GNRL_DATA_PASS 1
#define SPI_GNRL_DATA_CHECK 0
#define SPI_REC_SIZE 43
#define ENDOFGENRL 4
#define SPI_MAXSIZE 43
/*
 #define SPI_IMAX_TX_SIZE 100
  */

/* General data */
typedef struct {
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
	uint8_t Total_message_size;
	uint8_t Reserved_1;
}Spi_Genrl_S;

 /* Phone data */
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
}Spi_Phcall_S;

 /* Navigation */
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
 }Spi_Navi_S;

 /* music player   */
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
}Spi_Music_S;

 /* General data */
 uint8_t	set_ble_connectivity_status(void);
 uint8_t	set_ble_Data_Availablity(void);
 uint8_t	set_ble_general_data(void);
 uint8_t	set_ble_phone_call_data(void);
 uint8_t	set_ble_navigation_data(void);
 uint8_t	set_ble_music_player_data(void);
 uint8_t	set_ble_gopro_data(void);
 uint8_t	set_ble_paired_devices(void);
 uint8_t	set_ble_reserved_1(void);
 uint8_t	set_Total_message_size(void);
 uint8_t	set_Reserved_1(void);

 /* Phone data */
 uint8_t	set_Phone_Data_Availablity(void);
 uint8_t	set_Phone_Message_Notification(void);
 uint8_t	set_Phone_Incomming_call(void);
 uint8_t	set_Phone_Ongoing_Call_notifiaction(void);
 uint8_t	set_Phone_End_Call(void);
 uint8_t	set_Phone_Missed_Call_Notification(void);
 uint8_t	set_phone_reserved_1(void);
 uint8_t	set_Phone_volume(void);
 uint8_t	set_Phone_Ongoing_call_Timer_Start(void);
 uint8_t	set_Phone_Ongoing_call_Timer_Stop(void);
 uint8_t	set_Phone_Caller_Name_Identifier(void);
 uint8_t	set_Call_name_size(void);
 uint8_t*   set_Call_name(void);
 uint8_t	set_Phone_Caller_Number_Identifier(void);
 uint8_t	set_Call_num_size(void);
 uint8_t*	set_Call_num(void);
 uint8_t*	set_Reserved_2(void);

 /* Navigation */
 uint8_t    set_Navigation_Data_Availablity(void);
 uint8_t    set_Navigation_Turn_Type(void);
 uint8_t    set_Navigation_Turn_Distance_Identifier(void);
 uint8_t    set_Navigation_Turn_Distance_Size(void);
 uint8_t*   set_Navigation_Turn_Distance(void);
 uint8_t    set_Navigation_Overall_Distance_Identifier(void);
 uint8_t    set_Navigation_Overall_Distance_Size(void);
 uint8_t*   set_Navigation_Overall_Distance(void);
 uint8_t    set_Navigation_ETA_Identifier(void);
 uint8_t    set_Navigation_ETA_Hours(void);
 uint8_t    set_Navigation_ETA_Minutes(void);
 uint8_t*    set_Navigation_Reserved(void);

 /* Music    */
 uint8_t    set_Music_Player_Data_Availablity(void);
 uint8_t    set_Music_Player_Song_Status(void);
 uint8_t    set_Music_Player_reserved_1(void);
 uint8_t    set_Music_Player_Volume(void);
 uint8_t    set_Music_Player_Song_Name_Identifier(void);
 uint8_t    set_Music_Player_Song_Name_Size(void);
 uint8_t*   set_Music_Player_Song_Name(void);
 uint8_t    set_Music_Player_Total_Min(void);
 uint8_t    set_Music_Player_Total_Sec(void);
 uint8_t    set_Music_Player_Current_Playing_Min(void);
 uint8_t    set_Music_Player_Current_Playing_Sec(void);
 uint8_t*   set_Music_Player_Reserved(void);

#endif /* SPI_DATA_H_*/
