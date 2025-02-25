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
    unsigned char led1 = 0x80; // 第一个灯（初始在P0.7）
    unsigned char led2 = 0x00; // 第二个灯（初始未激活）
    unsigned char led3 = 0x00; // 第三个灯（初始未激活）
    unsigned char count = 1;   // 已激活的灯数
    
    P0 = led1; // 初始状态：第一个灯亮
    
    while(1) {
        Delay500ms();
        
        // 移动所有已激活的灯
        led1 >>= 1;
        if (led1 == 0x00) led1 = 0x80; // 循环到开头
        
        if (count >= 2) {
            led2 >>= 1;
            if (led2 == 0x00) led2 = 0x80;
        }
        
        if (count >= 3) {
            led3 >>= 1;
            if (led3 == 0x00) led3 = 0x80;
        }
        
        // 激活新灯（每次右移后激活一个）
        if (count < 3) {
            if (count == 1) {
                led2 = 0x80; // 激活第二个灯
            } else if (count == 2) {
                led3 = 0x80; // 激活第三个灯
            }
            count++;
        }
        
        // 合并灯的状态
        P0 = led1 | led2 | led3;
    }
}