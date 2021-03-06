#include "delay.h"

void delay_us(u32 uTime) 
{ 
  u32 temp;
  SysTick->LOAD = 16*uTime/8;//HCLK的1/8
  SysTick->VAL = 0x00;//清空
	SysTick->CTRL = 0x01;//使能
	do
	{
	 temp = SysTick->CTRL;//读取当前倒计时值
	}while((temp&0x01)&&(!(temp&(1<<16))));//等待时间到达
	  
	SysTick->CTRL = 0x00;//关闭计数器
	SysTick->VAL = 0x00;//清空
}

void delay_ms(u32 mTime)
{
  u32 temp;
  SysTick->LOAD = 16*1000*mTime/8;
  SysTick->VAL = 0x00;//清空
	SysTick->CTRL = 0x01;//使能
	do
	{
	 temp = SysTick->CTRL;//读取当前倒计时值
	}while((temp&0x01)&&(!(temp&(1<<16))));//等待时间到达
	  
	SysTick->CTRL = 0x00;//关闭计数器
	SysTick->VAL = 0x00;//清�
}
