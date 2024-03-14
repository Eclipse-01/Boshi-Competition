#include "basicfunctions.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"

#define NoWire 0
#define Left0 1
#define Left1 2
#define Right1 4
#define Right0 8
#define Stop 15
#define TurnLeft 101
#define TurnRight 102

int LineDetcet()//车道检测
{
    if (Sensor(1) == 0 || Sensor(2) == 0 || Sensor(3) == 0 || Sensor(4))//所有传感器均没有检测到压线
    return NoWire;
    if (Sensor(1) == 1 && Sensor(2) == 0 && Sensor(3) == 0 && Sensor(4) == 0)//左侧检测到压线严重
    return Left0;
    if (Sensor(1) == 1 && Sensor(2) == 1 && Sensor(3) == 0 && Sensor(4) == 0)//左侧检测到压线
    return Left1;
    if (Sensor(1) == 0 && Sensor(2) == 0 && Sensor(3) == 1 && Sensor(4) == 1)//右侧检测到压线
    return Right1;
    if (Sensor(1) == 0 && Sensor(2) == 0 && Sensor(3) == 0 && Sensor(4) == 1)//右侧检测到压线严重
    return Right0;
    if (Sensor(1) == 1 && Sensor(2) == 1 && Sensor(3) == 1 && Sensor(4) == 1)//所有传感器均检测到压线
    return Stop;
    if (Sensor(1) == 1 && Sensor(2) == 1 && Sensor(4) == 0)//左侧均检测到压线，右侧未检测到压线
    return TurnLeft;
    if (Sensor(3) == 1 && Sensor(4) == 1 && Sensor(1) == 0)//右侧均检测到压线，左侧未检测到压线
    return TurnRight;
}

int LineKeep()//车道保持
{
    if (LineDetcet() == NoWire)//没有检测到压线
    {
        //所有电机全部正转
        return 0;
    }
    if (LineDetcet() == Left0)//左侧检测到跑偏严重
    {
        //左侧电机正转，右侧电机停止
        return 0;
    }
    if (LineDetcet() == Left1)//左侧检测到压线
    {
        //左侧电机正转，右侧电机慢正转
        return 0;
    }
    if (LineDetcet() == Right1)//右侧检测到压线
    {
        //左侧电机慢正转，右侧电机正转
        return 0;
    }
    if (LineDetcet() == Right0)//右侧检测到跑偏严重
    {
        //左侧电机停止，右侧电机正转
        return 0;
    }
    if (LineDetcet() == Stop)//所有传感器均检测到压线
    {
        //所有电机全部停止
        return Stop;
    }
    if (LineDetcet() == TurnLeft)//左侧均检测到压线，右侧未检测到压线
    {
        //左侧电机反转，右侧电机正转
        return TurnLeft;
    }
    if (LineDetcet() == TurnRight)//右侧均检测到压线，左侧未检测到压线
    {
        //左侧电机正转，右侧电机反转
        return TurnRight;
    }   
}

