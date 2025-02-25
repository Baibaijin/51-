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
	P0 = 0xFE;  // ��ʼ�� P0 Ϊ 11111110����һ����������������
	while(1){
		Delay100ms();  // ��ʱ 100ms
		P0 = (P0 << 1) | 0x01;  // ����һλ�������λ��1
		if (P0 == 0xFF) {  // ��� P0 ��Ϊ 11111111�����е��𣩣������³�ʼ��Ϊ 11111110
			P0 = 0xFE;
		}
	}
}