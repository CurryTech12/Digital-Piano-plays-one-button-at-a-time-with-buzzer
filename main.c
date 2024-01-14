//main.c
#include <SI_EFM8BB1_Register_Enums.h>
void InitDevice(void)
{
	
//Disable Watchdog Timer with key sequence
WDTCN = 0xDE; //First key
WDTCN = 0xAD; //Second key

//Setup Defaults for P1
P1MDOUT = P1MDOUT_B0__OPEN_DRAIN | P1MDOUT_B1__OPEN_DRAIN
| P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__OPEN_DRAIN
| P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__OPEN_DRAIN
| P1MDOUT_B6__OPEN_DRAIN | P1MDOUT_B7__OPEN_DRAIN;
//Enable Weak Pullups
XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
//Disable Interrupts
IE = IE_EA__DISABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
| IE_ESPI0__DISABLED | IE_ET0__DISABLED | IE_ET1__DISABLED
| IE_ET2__ENABLED | IE_ES0__DISABLED;
}
unsigned char q,s;
unsigned int number,new_number,start;
void ISR_OVERFLOW(void) interrupt 1{
	TCON &= ~(1<<4);
	P0 ^= (1<<3);//toggles pin p0.3
	TH0 = s;
	TL0 = q;
	TCON |= (1<<4);
}

void main(void){
	InitDevice();
	TMOD = 0x01;
	IE = 0x82;
	TH0 = s;
	TL0 = q;
	while(1){
		if((!(P0 & (1<<4))) && (!(P1 & (1<<5)))){//when p0.4 pressed 440hz
			s = 0xFE;//
			q = 0xDE;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<4)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
		if((!(P0 & (1<<5))) && (!(P1 & (1<<5)))){//when p0.4 pressed 466hz
			s = 0xFE;//
			q = 0xEF;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<5)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P0 & (1<<6))) && (!(P1 & (1<<5)))){//when p0.4 pressed 493hz
			s = 0xFE;//
			q = 0xFE;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<6)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P0 & (1<<7))) && (!(P1 & (1<<5)))){//when p0.4 pressed 523.25
			s = 0xFF;//
			q = 0x0C;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<7)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P0 & (1<<2))) && (!(P1 & (1<<5)))){//when p0.4 pressed 554.37
			s = 0xFF;//
			q = 0x1A;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<2)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P0 & (1<<1))) && (!(P1 & (1<<5)))){//when p0.4 pressed 587.33
			s = 0xFF;//
			q = 0x26;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<1)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P0 & (1<<0))) && (!(P1 & (1<<5)))){//when p0.4 pressed 622.25hz
			s = 0xFF;//
			q = 0x33;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<0)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P1 & (1<<0))) && (!(P1 & (1<<5)))){//when p0.4 pressed 659.25hz
			s = 0xFF;//
			q = 0x3F;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<0)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P1 & (1<<1))) && (!(P1 & (1<<5)))){//when p0.4 pressed 698hz
			s = 0xFF;//
			q = 0x47;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<1)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P1 & (1<<2))) && (!(P1 & (1<<5)))){//when p0.4 pressed 739.99hz
			s = 0xFF;//
			q = 0x54;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<2)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P1 & (1<<3))) && (!(P1 & (1<<5)))){//when p0.4 pressed 783hz
			s = 0xFF;//
			q = 0x5E;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<3)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((!(P1 & (1<<4))) && (!(P1 & (1<<5)))){//when p0.4 pressed 830hz
			s = 0xFF;//
			q = 0x66;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<4)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once
		}
		if((P1 & (1<<5))){
			if(!(P0 & (1<<4))){//when p0.4 pressed 880hz
			s = 0xFF;//
			q = 0x6F;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<4)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P0 & (1<<5))){//when p0.4 pressed 932hz
			s = 0xFF;//
			q = 0x78;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<5)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P0 & (1<<6))){//when p0.4 pressed 987hz
			s = 0xFF;//
			q = 0x7F;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<6)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P0 & (1<<7))){//when p0.4 pressed 1046hz
			s = 0xFF;//
			q = 0x87;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<7)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P0 & (1<<2))){//when p0.4 pressed 1108hz
			s = 0xFF;//
			q = 0x8D;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<2)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P0 & (1<<1))){//when p0.4 pressed 1174hz
			s = 0xFF;//
			q = 0x94;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<1)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P0 & (1<<0))){//when p0.4 pressed 1244hz
			s = 0xFF;//
			q = 0x9A;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P0 & (1<<0)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P1 & (1<<0))){//when p0.4 pressed 1318hz
			s = 0xFF;//
			q = 0xA0;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<0)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P1 & (1<<1))){//when p0.4 pressed 1396hz
			s = 0xFF;//
			q = 0xA5;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<1)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P1 & (1<<2))){//when p0.4 pressed 1479hz
			s = 0xFF;//
			q = 0xAA;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<2)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P1 & (1<<3))){//when p0.4 pressed 1567hz
			s = 0xFF;//
			q = 0xAF;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<3)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
			if(!(P1 & (1<<4))){//when p0.4 pressed 1661hz
			s = 0xFF;//
			q = 0xB4;// load timer with specfic value when pressed
			TCON |= (1<<4);//start the timer
			while(!(P1 & (1<<4)));//if button is held keep it stuck in this while loop
			TCON &= ~(1<<4);// once user lets go stop the timer
		}
	}
}
}
