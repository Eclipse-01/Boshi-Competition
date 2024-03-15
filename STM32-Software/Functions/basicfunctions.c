#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "Movement.h"

int initMCU()//初始化MCU，包括各种外设
{
    PWM_Init();
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

int LED(int state)//State取0或1，表示LED的状态
{
    
}

int Beep(int state)//State取0或1，表示蜂鸣器的状态
{
    GPIO_SetBits(GPIOA, GPIO_Pin_8);//设置GPIOA的8号引脚为高电平
}

int Button()//返回按键的状态
{
    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
}

int Sensor(int sensor)//Sensor取1-4的值，表示传感器的编号
{
    return GPIO_ReadInputDataBit(GPIOB, sensor);
}
