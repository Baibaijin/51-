# include <STC89C5xRC.H>
# include <intrins.h>
void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(){
	
	P0=0x7F;
	while(1){
		Delay500ms();
		P0=(P0>>1)+0x80;
		if(P0==0xFF){
			P0=0x7F;
		}
	}
	
}