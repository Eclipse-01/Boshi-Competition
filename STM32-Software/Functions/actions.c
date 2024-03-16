#include "basicfunctions.h"
#include "Delay.h"
#include "Movement.h"

#define NoWire 0
#define Left0 1
#define Left1 2
#define Right1 4
#define Right0 8
#define Stop 15
#define TurnLeft 101
#define TurnRight 102

#define k 1 // 地面摩擦系数参数

int LineDetect() // 车道检测
{
    int leftOuter = Sensor(1);
    int leftInner = Sensor(2);
    int rightInner = Sensor(3);
    int rightOuter = Sensor(4);

    if (!(leftOuter || leftInner || rightInner || rightOuter)) {//无线检测
        return NoWire;
    }
    if (leftOuter) {
        return TurnLeft;
    }
    if (rightOuter) {
        return TurnRight;
    }
    if (leftInner && rightInner) {
        return Stop;
    }
    if (leftInner) {
        return Left1;
    }
    if (rightInner) {
        return Right1;
    }
}

int LineKeep(int LineStatus) // 车道保持
{
    switch (LineStatus) {
        case NoWire:
            motor(70, 70); // 左右电机正转
            break;
        case Left1:
            motor(60, 80); // 减少左侧电机速度，增加右侧电机速度
            break;
        case Right1:
            motor(80, 60); // 增加左侧电机速度，减少右侧电机速度
            break;
        case Stop:
            motor(0, 0); // 所有电机全部停止
            break;
         case TurnLeft:
            motor(-80, 80); // 左侧电机反转，右侧电机正转
            while(Sensor(4) == 0)//在右侧检测到压线前，一直转
            {
            }
            motor(70,60);
            while(Sensor(2) == 0)//在左侧检测到压线前，一直转
            {
            }
            motor(0,0);
            break;
        case TurnRight:
            motor(80, -80); // 左侧电机正转，右侧电机反转
            while(Sensor(1) == 0)//在左侧检测到压线前，一直转
            {
            }
            motor(60,70);
            while(Sensor(3) == 0)//在右侧检测到压线前，一直转
            {
            }
            motor(0,0);
            break;
    }
    return 0;
}


int AutoPark()//倒车入库
{
    motor(-80,-80);
    while(((Sensor(1) && Sensor(4))) == 0)
    {
        if (Sensor(1)==1)
        {
            motor(0,-60);
        }
        if (Sensor(4)==1)
        {
            motor(-60,0);
        }
    }

    motor(-60,-60);
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
