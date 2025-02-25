#include <STC89C5xRC.H>
#include <intrins.h>

void Delay500ms(void)    //@11.0592MHz
{
    unsigned char data i, j, k;
    _nop_();
    i = 4;
    j = 129;
    k = 119;
    do {
        do {
            while (--k);
        } while (--j);
    } while (--i);
}

void main() {
    unsigned char led1 = 0x80; // ��һ���ƣ���ʼ��P0.7��
    unsigned char led2 = 0x00; // �ڶ����ƣ���ʼδ���
    unsigned char led3 = 0x00; // �������ƣ���ʼδ���
    unsigned char count = 1;   // �Ѽ���ĵ���
    
    P0 = led1; // ��ʼ״̬����һ������
    
    while(1) {
        Delay500ms();
        
        // �ƶ������Ѽ���ĵ�
        led1 >>= 1;
        if (led1 == 0x00) led1 = 0x80; // ѭ������ͷ
        
        if (count >= 2) {
            led2 >>= 1;
            if (led2 == 0x00) led2 = 0x80;
        }
        
        if (count >= 3) {
            led3 >>= 1;
            if (led3 == 0x00) led3 = 0x80;
        }
        
        // �����µƣ�ÿ�����ƺ󼤻�һ����
        if (count < 3) {
            if (count == 1) {
                led2 = 0x80; // ����ڶ�����
            } else if (count == 2) {
                led3 = 0x80; // �����������
            }
            count++;
        }
        
        // �ϲ��Ƶ�״̬
        P0 = led1 | led2 | led3;
    }
}