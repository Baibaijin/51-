#include <STC89C5xRC.H>

void Delay100ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}

void main(){
	P0 = 0xFE;  // 初始化 P0 为 11111110（第一个灯亮，其他灯灭）
	while(1){
		Delay100ms();  // 延时 100ms
		P0 = (P0 << 1) | 0x01;  // 左移一位并在最低位加1
		if (P0 == 0xFF) {  // 如果 P0 变为 11111111（所有灯灭），则重新初始化为 11111110
			P0 = 0xFE;
		}
	}
}