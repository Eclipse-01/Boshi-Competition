#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"

int initMCU()//初始化MCU，包括各种外设
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    typedef struct
    {
        uint16_t GPIO_Pin;
        GPIOMode_TypeDef GPIO_Mode;
        GPIOSpeed_TypeDef GPIO_Speed;
    }GPIO_InitTypeDef;
    GPIO_InitTypeDef GPIO_InitStructure;

}

int Forward(int speed)//Speed取0-100的值，表示小车的速度
{
    
}

int Backward(int speed)//Speed取0-100的值，表示小车的速度
{
    
}

int TurnLeft(unsigned angle)//Angle取大于0的值，表示小车左转的角度
{
    
}

int TurnRight(unsigned angle)//Angle取大于0的值，表示小车右转的角度
{
    
}

int RunOnLine()//小车沿着线行驶,当某一侧两边传感器均检测到黑线时，小车退出巡线
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