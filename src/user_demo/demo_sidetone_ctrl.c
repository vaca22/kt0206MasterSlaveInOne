	
    

/* 
call the follow function in a 100ms task in user.c
the task loop time could be 100ms or other acceptable time.
*/
void task_100ms(void)
{
    extern uint8_t usb_in_aud_flag;
	extern uint8_t usb_out_aud_flag;
    
	if(usb_in_aud_flag)
	{
		LED1_ON;
	}
	else
	{
		LED1_OFF;
	}
	if(usb_out_aud_flag)
	{
		LED2_ON;
		g_mute_bit |= BIT_ST; //turn off sidetone
	}
	else
	{
		LED2_OFF;
		g_mute_bit &= ~BIT_ST; //turn on sidetone
	}
	usb_in_aud_flag = 0;
	usb_out_aud_flag = 0;
}

