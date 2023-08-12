/*
 * main.c
 *
 *  Created on: Sep 5, 2022
 *      Author: hp
 */

# include "STD_TYPES.h"
# include "DIO_interface.h"
# include <util/delay.h>



int main()
{
	u8 B1,B2,B3,B4,B5,B6,B7,B8;
	s8 i;
	u32 time1=25,time2=30;

	DIO_VidSetPortDirection(Port_A,0b11111111);
	DIO_VidSetPortDirection(Port_D,0b11111111);
	DIO_VidSetPortValue(Port_D,0x00);


	DIO_VidSetPortDirection(Port_B,0b00000000);

	DIO_VidSetPinValue(Port_B,Pin0,PinHigh);
	DIO_VidSetPinValue(Port_B,Pin1,PinHigh);
	DIO_VidSetPinValue(Port_B,Pin2,PinHigh);
	DIO_VidSetPinValue(Port_B,Pin3,PinHigh);
	DIO_VidSetPinValue(Port_B,Pin4,PinHigh);
	DIO_VidSetPinValue(Port_B,Pin5,PinHigh);
	DIO_VidSetPinValue(Port_B,Pin6,PinHigh);
	DIO_VidSetPinValue(Port_B,Pin7,PinHigh);

	while (1)
	{
		DIO_VidGetPinValue(Port_B,Pin0,&B1);
		DIO_VidGetPinValue(Port_B,Pin1,&B2);
		DIO_VidGetPinValue(Port_B,Pin2,&B3);
		DIO_VidGetPinValue(Port_B,Pin3,&B4);
		DIO_VidGetPinValue(Port_B,Pin4,&B5);
		DIO_VidGetPinValue(Port_B,Pin5,&B6);
		DIO_VidGetPinValue(Port_B,Pin6,&B7);
		DIO_VidGetPinValue(Port_B,Pin7,&B8);

//***************************************************************
		if (B1==0)
		{
			DIO_VidSetPortValue(Port_A,0b11111111);
			_delay_ms(500);

			DIO_VidSetPortValue(Port_A,0x00);
			_delay_ms(500);
		}
//***************************************************************
		else if (B2==0)
		{
			for(i=0;i<8;i++)
			{
				DIO_VidSetPinValue(Port_A,i,PinHigh);
				_delay_ms(time1);

				DIO_VidSetPortValue(Port_A,0x00);
				_delay_ms(time1);
			}

		}
//***************************************************************
		else if (B3==0)
		{
			for(i=7;i>-1;i--)
		    {
		    	DIO_VidSetPinValue(Port_A,i,PinHigh);
		    	_delay_ms(time1);

		    	DIO_VidSetPortValue(Port_A,0x00);
		    	_delay_ms(time1);
		    }

		}
//***************************************************************
		else if (B4==0)
		{
			for (i=0;i<8/2;i++)
			{
				DIO_VidSetPinValue(Port_A,i,PinHigh);
				DIO_VidSetPinValue(Port_A,7-i,PinHigh);
		    	_delay_ms(time2);
		    	DIO_VidSetPortValue(Port_A,0x00);
		    	_delay_ms(time2);
			}

		}
//***************************************************************
		else if (B5==0)
		{
			for (i=(8/2)-1;i>=0;i--)
			{
				DIO_VidSetPinValue(Port_A,i,PinHigh);
				DIO_VidSetPinValue(Port_A,7-i,PinHigh);
		    	_delay_ms(time2);
		    	DIO_VidSetPortValue(Port_A,0x00);
		    	_delay_ms(time2);
			}

		}
//***************************************************************
		else if (B6==0)
		{
			for(i=0;i<8;i++)
		    {
		    	DIO_VidSetPinValue(Port_A,i,PinHigh);
		    	_delay_ms(time1);

		    	DIO_VidSetPortValue(Port_A,0x00);
		    	_delay_ms(time1);
		    }
			for(i=6;i>0;i--)
		    {
		    	DIO_VidSetPinValue(Port_A,i,PinHigh);
		    	_delay_ms(time1);

		    	DIO_VidSetPortValue(Port_A,0x00);
		    	_delay_ms(time1);
		    }

		}
//***************************************************************
		else if (B7==0)
		{
			for(i=0;i<8;i++)
			{
				DIO_VidSetPinValue(Port_A,i,PinHigh);
				_delay_ms(time2);
			}

			DIO_VidSetPortValue(Port_A,0x00);
			for(i=7;i>-1;i--)
		    {
		    	DIO_VidSetPinValue(Port_A,i,PinHigh);
		    	_delay_ms(time2);
		    }

		    DIO_VidSetPortValue(Port_A,0x00);
		}
//***************************************************************
		else if (B8==0)
		{
			for (i=0;i<8/2;i++)
		    {
		    	DIO_VidSetPinValue(Port_A,i,PinHigh);
		    	DIO_VidSetPinValue(Port_A,7-i,PinHigh);
		    	_delay_ms(time2);
		    	DIO_VidSetPortValue(Port_A,0x00);
		    	_delay_ms(time2);
		    }

			for (i=(8/2)-1;i>=0;i--)
			{
				DIO_VidSetPinValue(Port_A,i,PinHigh);
				DIO_VidSetPinValue(Port_A,7-i,PinHigh);
				_delay_ms(time2);
				DIO_VidSetPortValue(Port_A,0x00);
				_delay_ms(time2);
			}
		}
//***************************************************************


	}



}




