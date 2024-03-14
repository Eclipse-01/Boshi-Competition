#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <actions.h>
#include <sensors.h>
#include <basicfunctions.h>
#include <oled.h>


enum DriveStage{ //定义了一个枚举类型，用来表示小车的状态
    WaitAtLine,//等待在线上
    TurnRight1,//右转
    TurnRight2,//右转
    PrepareForStopby,//准备停车
    Stopby,//停车
    DriveOut,//驶出
    TurnLeft1,//左转
    TurnLeft2,//左转
    SwitchLane,//切换车道
    PrepareForStop,//准备停车
    DriveBack,//开回起点
};

int main(void) //整个自动驾驶程序的入口点，负责调用各种各样的函数
{
    //initMCU(); //初始化各种外设
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_Pin_0);
    GPIO_ResetBits(GPIOA, GPIO_Pin_2);




	while(1)
    {
        
    }	                                                                                                                                            
    
}
