#include "KT_usb_keyboard.h"
#include "api.h"


/**
 * HID键盘设备每次发送8Byte数据给:
 *             Byte0	Byte1	Byte2	Byte3	Byte4	Byte5	Byte6	Byte7
 *          |Ctrl byte| Rev.  | Key1  | Key2  | Key3  | Key4  | Key5  | Key6  |
 *
 *           Ctrl Byte0: bit0  |    bit1   |  bit2  |  bit3  |   bit4  |   bit5   |   bit6  |  bit7  |
 *                     :"Ctrl"(L),"Shift"(L),"ALt"(L),"WIN"(L),"Ctrl"(R),"Shift"(R),"ALt"(R),"WIN"(R),
 *
 *
 *           						  Byte0	 Byte1	Byte2	Byte3	Byte4	Byte5	Byte6	Byte7
 *           Key'A' Press:			   0x00, 0x00,  0x04('A'),0x00,  0x00,  0x00,    0x00,  0x00.
 *           Key'A' + 'B' Press:	   0x00,  0x00, 0x04('A'),0x05('B'),0x00,0x00,   0x00,  0x00.
 *           Key'Ctrl'+'A'+'B' :       0x01('Ctrl'),0x00,0x04('A'),0x05('B'),0x00,0x00,0x00,0x00.
 *
 *           No Key Press:             0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00.
 *
 *
 **/

const uint8_t DemoWebStr[32][8] =
{
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // No Key press/Key release    	//0
	{0x00, 0x00, char_Enter, 0x00, 0x00, 0x00, 0x00, 0x00},   				// 'Enter'    	//1
	{0x00, 0x00, char_Esc, 0x00, 0x00, 0x00, 0x00, 0x00},   				// 'Esc'      	//2
	{0x00, 0x00, char_BackSpace, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // 'BackSpace'  //3
	{0x00, 0x00, char_Space, 0x00, 0x00, 0x00, 0x00, 0x00},   		        // 'Space'      //4
	{0x00, 0x00, char_CapsLock, 0x00, 0x00, 0x00, 0x00, 0x00},  			// 'Capslock'   //5
	{0x00, 0x00, char_Delete, 0x00, 0x00, 0x00, 0x00, 0x00},  			    // 'Delete'     //6

	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // Rev.         //7
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // Rev.         //8

	{0x00, 0x00, char_F1, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // 'F1'			//9
	{0x00, 0x00, char_F5, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // 'F5'			//10

	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // Rev.         //11
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // Rev.         //12

	{0x00, 0x00, char_LeftArrow, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // '<--'        //13
	{0x00, 0x00, char_RightArrow, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // '-->'        //14
	{0x00, 0x00, char_UpArrow, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // 'Up'         //15
	{0x00, 0x00, char_DownArrow, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // 'Down'       //16

	{0x00, 0x00, char_PageUp, 0x00, 0x00, 0x00, 0x00, 0x00},   		        // 'PageUp'     //17
	{0x00, 0x00, char_PageDown, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // 'PageDown'   //18
	{0x00, 0x00, char_Home, 0x00, 0x00, 0x00, 0x00, 0x00},   		    	// 'Home'   	//19
	{0x00, 0x00, char_End, 0x00, 0x00, 0x00, 0x00, 0x00},   		    	// 'End'   		//20

	{ctrl_L_Win, 0x00, char_R, 0x00, 0x00, 0x00, 0x00, 0x00}, 				// 'win' + 'r'                          //21
	{0x00, 0x00, char_W, char_W, char_W, char_Point_Greater, 0x00, 0x00}, 	// 'w', 'w', 'w', '.'                   //22
	{0x00, 0x00, char_K, char_T, char_M, char_I, char_C, char_R}, 			// 'k', 't', 'm', 'i', 'c', 'r'         //23
	{0x00, 0x00, char_O, 0x00, 0x00, 0x00, 0x00, 0x00}, 					// 'o'                                  //24
	{0x00, 0x00, char_Point_Greater, char_C, char_O, char_M, 0x00, 0x00}, 	// '.', 'c', 'o', 'm',                  //25
	{0x00, 0x00, char_Point_Greater, char_C, char_N, 0x00, 0x00, 0x00}, 	// '.', 'c', 'n',                       //26

	{ctrl_L_Ctrl, 0x00, char_C, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // 'Ctrl' + 'c'                         //27
	{ctrl_L_Ctrl, 0x00, char_V, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // 'Ctrl' + 'V'                         //28
	{ctrl_L_Alt, 0x00, char_Tab, 0x00, 0x00, 0x00, 0x00, 0x00},   		    // 'Alt'+'Tab'                          //29
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // Rev.                                 //30
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   				    // Rev.                                 //31
};




















