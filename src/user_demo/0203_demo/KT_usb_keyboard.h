#ifndef __KT_USB_KEYBOARD_H_
#define __KT_USB_KEYBOARD_H_

#include <stdint.h>

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

/***  Byte0 ***/    // Byte1 always is 0x00
typedef enum
{
	ctrl_L_Ctrl = 0x01,       //  'Left Ctrl'
	ctrl_L_Shift= 0x02,       //  'Left Shift'
	ctrl_L_Alt	= 0x04,       //  'Left Alt'
	ctrl_L_Win	= 0x08,       //  'Left Win'
	ctrl_R_Ctrl = 0x10,       //  'Right Ctrl'
	ctrl_R_Shift= 0x20,       //  'Right Shift'
	ctrl_R_Alt  = 0x40,       //  'Right Alt'
	ctrl_R_Win  = 0x80,       //  'Right Win'
}KT_USB_HID_SpecialKeyBoard_Descrip_e;

/***  Byte2~Byte6 ***/
typedef enum
{
	char_A = 0x04,       //  'A'
	char_B = 0x05,       //  'B'
	char_C = 0x06,       //  'C'
	char_D = 0x07,       //  'D'
	char_E = 0x08,       //  'E'
	char_F = 0x09,       //  'F'
	char_G = 0x0a,       //  'G'
	char_H = 0x0b,       //  'H'
	char_I = 0x0c,       //  'I'
	char_J = 0x0d,       //  'J'
	char_K = 0x0e,       //  'K'
	char_L = 0x0f,       //  'L'
	char_M = 0x10,       //  'M'
	char_N = 0x11,       //  'N'
	char_O = 0x12,       //  'O'
	char_P = 0x13,       //  'P'
	char_Q = 0x14,       //  'Q'
	char_R = 0x15,       //  'R'
	char_S = 0x16,       //  'S'
	char_T = 0x17,       //  'T'
	char_U = 0x18,       //  'U'
	char_V = 0x19,       //  'V'
	char_W = 0x1a,       //  'W'
	char_X = 0x1b,       //  'X'
	char_Y = 0x1c,       //  'Y'
	char_Z = 0x1d,       //  'Z'

	char_1 = 0x1e,       //  '1!'
	char_2 = 0x1f,       //  '2@'
	char_3 = 0x20,       //  '3#'
	char_4 = 0x21,       //  '4$'
	char_5 = 0x22,       //  '5%'
	char_6 = 0x23,       //  '6^'
	char_7 = 0x24,       //  '7&'
	char_8 = 0x25,       //  '8*'
	char_9 = 0x26,       //  '9('
	char_0 = 0x27,       //  '0)'

	char_Enter 		= 0x28,   //  'Enter'
	char_Esc   		= 0x29,   //  'Esc'
	char_BackSpace 	= 0x2a,   //  'BackSpace'
	char_Tab 		= 0x2b,   //  'Table'
	char_Space 		= 0x2c,   //  'Space'

	char_Sub_UnderLine	= 0x2d,   //  '-_'
	char_Add_Equal		= 0x2e,   //  '+='
	char_L_Brace    	= 0x2f,   //  '[{'
	char_R_Brace    	= 0x30,   //  ']}'
	char_BackSlash_Or  	= 0x31,   //  '\|'

	char_Semicolon_Colon= 0x33,   //  ';:'
	char_Quotation  	= 0x34,   //  ''"'
	char_Inverse		= 0x35,   //  '`~'
	char_Comma_Less		= 0x36,   //  ',<'
	char_Point_Greater	= 0x37,   //  '.>'

	char_Slash		= 0x38,   //  '/?'
	char_CapsLock	= 0x39,	  //  'CAPSLOCK'
	char_F1			= 0x3a,   //  'F1'
	char_F2			= 0x3b,   //  'F2'
	char_F3			= 0x3c,   //  'F3'
	char_F4			= 0x3d,   //  'F4'
	char_F5			= 0x3e,   //  'F5'
	char_F6			= 0x3f,   //  'F6'
	char_F7			= 0x40,   //  'F7'
	char_F8			= 0x41,   //  'F8'
	char_F9			= 0x42,   //  'F9'
	char_F10		= 0x43,   //  'F10'
	char_F11		= 0x44,   //  'F11'
	char_F12		= 0x45,   //  'F12'

	char_PrintScreen= 0x46,   //  'PrintScreen'
	char_Scroll		= 0x47,   //  'Scroll'
    char_Pause		= 0x48,   //  'Pause'

    char_Insert		= 0x49,   //  'Insert'
    char_Home		= 0x4a,   //  'Home',
    char_PageUp		= 0x4b,   //  'PageUp'
    char_Delete		= 0x4c,	  //  'Delete'
    char_End		= 0x4d,   //  'End'
    char_PageDown	= 0x4e,   //  'PageDown'
    char_RightArrow = 0x4f,   //  '->'
    char_LeftArrow	= 0x50,   //  '<-'
    char_DownArrow	= 0x51,   //  'Down Arrow'
    char_UpArrow	= 0x52,   //  'Up Arrow'

    char_NumLock	= 0x53,   //  'NumLock'
    num_Divide		= 0x54,   //  '/'
    num_Multiply	= 0x55,   //  '*'
    num_Sub		    = 0x56,   //  '-'
    num_Add 		= 0x57,   //  '+'
    num_Enter		= 0x58,   //  'Enter'
    num_1_End	    = 0x59,   //  '1End'
    num_2_Down		= 0x5a,   //  '2Down'
    num_3_PageDown  = 0x5b,   //  '3PageDown'
    num_4_Left		= 0x5c,   //  '4<-'
    num_5		    = 0x5d,   //  '5'
    num_6_Right		= 0x5e,   //  '6->'
    num_7_Home		= 0x5f,   //  '7Home'
    num_8_Up		= 0x60,   //  '8Up'
    num_9_PageUp	= 0x61,   //  '8PageUp'
    num_0_Insert	= 0x62,   //  '0Insert'
    num_Point_Del	= 0x63,   //  '.Del'

}KT_USB_HID_CommonKeyBoard_Descrip_e;

extern const uint8_t DemoWebStr[][8];

void Show_Web_init(void);
void Show_Web_schedule(void);

#endif /* KT_USB_KEYBOARD_FUNC_H_ */
