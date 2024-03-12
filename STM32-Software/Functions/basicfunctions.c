#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"

int initMCU()//初始化MCU，包括各种外设
{
    
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
    
}
