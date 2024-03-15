#include "basicfunctions.h"
#include "Motor.h"


#define NoWire 0
#define Left0 1
#define Left1 2
#define Right1 4
#define Right0 8
#define Stop 15
#define TurnLeft 101
#define TurnRight 102

#define k 1000//地面摩擦系数参数

int LineDetcet()//车道检测
{
    if (!(Sensor(1) || Sensor(2) || Sensor(3) || Sensor(4)))//所有传感器均没有检测到压线
    return NoWire;
    if (Sensor(2))//左侧检测到压线
    return Left1;
    if (Sensor(3))//右侧检测到压线
    return Right1;
    if ((Sensor(2) && Sensor(3))&&!(Sensor(1)||Sensor(4))) //两边均检测到压线,但同时两边外侧的传感器没有反应
    return Stop;
    if (Sensor(1) == 1 && Sensor(2) == 1 && Sensor(4))//左侧均检测到压线，右侧未检测到压线
    return TurnLeft;
    if (Sensor(3) == 1 && Sensor(4) == 1 && Sensor(1))//右侧均检测到压线，左侧未检测到压线
    return TurnRight;
}

int LineKeep(int LineStatus)//车道保持
{
    switch (LineStatus) {
        case NoWire:
            motor(100, 100); // 左右电机正转
            break;
        case Left1:
            motor(100, 80); // 左侧电机正转，右侧电机慢正转
            break;
        case Right1:
            motor(80, 100); // 左侧电机慢正转，右侧电机正转
            break;
        case Stop:
            motor(0, 0); // 所有电机全部停止
            return Stop;
        case TurnLeft:
            motor(-100, 100); // 左侧电机反转，右侧电机正转
            while(Sensor(4) == 0)//在右侧检测到压线前，一直转
            {
            }
            motor(70,30);
            while(Sensor(2) == 0)//在左侧检测到压线前，一直转
            {
            }
            return TurnLeft;
        case TurnRight:
            motor(100, -100); // 左侧电机正转，右侧电机反转
            while(Sensor(1) == 0)//在左侧检测到压线前，一直转
            {
            }
            motor(30,70);
            while(Sensor(3) == 0)//在右侧检测到压线前，一直转
            {
            }
            return TurnRight;
    }
    return 0;
}

int AutoPark()//倒车入库
{
    motor(-20,-20);
    Delay_ms(1000*k);
    motor(-30,30);//转到正确方向
    Delay_ms(1000*k);
    while(Sensor(1) && Sensor(4))
    {
        if (Sensor(2) == 0 && Sensor(3) == 0)
        {
            motor(0,0);
            return 0;//向主函数返回倒车已经完成
        }
    }
    motor(-20,-20);
    while(Sensor(2) == 1 && Sensor(3) == 1)
    {
    } 
    Delay_ms(1000*k);
    motor(0,0);
    return 0;//向主函数返回倒车已经完成
}

int DriveOut()//开出，代码由Github Copilot生成
{
    motor(20,20);
    while(Sensor(2) == 0 && Sensor(3) == 0)
    {
    }
    motor(30,-30);
    while(Sensor(2) == 0 && Sensor(3) == 0)
    {
    }
    motor(0,0);
    return 0;
}

int SwitchLane()//变道 此代码可能需要用中断来实现
{
    motor(20,20);
    Delay_ms(1000*k);
    motor(30,-30);
    Delay_ms(1000*k);
    motor(20,20);
    while(Sensor(3) == 0)
    {
    }
    return 0;
}
