#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"

int initMCU()//初始化MCU，包括各种外设
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
}

int Motor(int motor, int position, int speed)//Motor表示电机，Position代表正反转，0正1反， Speed取0-100的值，表示电机的速度
{
    
}

int LED(int state)//State取0或1，表示LED的状态
{
    
}

int Beep(int state)//State取0或1，表示蜂鸣器的状态
{
    GPIO_SetBits(GPIOA, GPIO_Pin_8);//设置GPIOA的8号引脚为高电平
}

int Sensor(int sensor)//Sensor取1-5的值，表示传感器的编号
{
    GPIO_ReadInputDataBit(GPIOA, sensor);
}