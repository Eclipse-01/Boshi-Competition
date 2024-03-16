#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <actions.h>
#include <basicfunctions.h>
#include <OLED.h>
#include <Movement.h>
#include <Delay.h>

#define NoWire 0    
#define Left0 1
#define Left1 2
#define Right1 4
#define Right0 8
#define Stop 15
#define TurnLeft 101
#define TurnRight 102

int main(void) //整个自动驾驶程序的入口点，负责调用各种各样的函数
{
    initMCU(); //初始化MCU,包括端口，总线，定时器等
    while(1)
    {
        LineKeep(LineDetect());
    }
    /*
    while(Button()==0);//等待按键按下
    LED(1,1);//点亮LED
    while(Button()==1);//等待按键松开
    Delay_ms(500);//延时
    LED(1,0);//熄灭LED
      */                                      //int DriveStage = 0;//初始化小车状态
    int SensorStatus = 0;//初始化传感器状态
    while(1)//开到停车线前
    {
        if (LineDetect() == Stop)//如果检测到停车线
        {
            motor(0,0);//停车
            break;
        }
        LineKeep(LineDetect());//保持车道
    }

    Delay_s(2);
    return 0;

    while(1)//等待停车线
    {
        SensorStatus = LineDetect();//检测传感器状态
        if (LineDetect() == Stop)//如果检测到停车线
        {
            break;
        }
        LineKeep(SensorStatus);//保持车道(车道保持也有转弯功能)
    }

	AutoPark();//停车

    while(Button()==0);//等待按键按下(发车)
    LED(1,1);//点亮LED
    while(Button()==1);//等待按键松开
    Delay_ms(500);//延时
    LED(1,0);//熄灭LED

    DriveOut();//驶出
    
    while(1)//进入变道区域，并忽略停车线
    {
        SensorStatus = LineDetect();//检测传感器状态
        if (SensorStatus == Stop)//如果检测到停车线
        {
            SensorStatus = NoWire; 
        }
        LineKeep(SensorStatus);//保持车道

        if (LineDetect() == TurnLeft)//如果检测此次为左转
        {
            break;
        }
    }

    for (int i = 0; i < 9999; i++)//通过修改 i 的值来控制小车的行驶距离
    {
        SensorStatus = LineDetect();//检测传感器状态
        LineKeep(SensorStatus);//保持车道
    }

    SwitchLane();//切换车道

    for (int i = 0; i < 9999; i++)//通过修改 i 的值来控制小车的行驶距离
    {
        SensorStatus = LineDetect();//检测传感器状态
        LineKeep(SensorStatus);//保持车道
    }

    while(Button()==0);//等待按键按下(发车)
    LED(1,1);//点亮LED
    while(Button()==1);//等待按键松开
    Delay_ms(500);//延时
    LED(1,0);//熄灭LED
    motor(-50,50);//掉头
    while(Sensor(2)==0);//等待左转完成
    
    int counter = 0;
    while(1)
    {
        SensorStatus = LineDetect();//检测传感器状态
        if (LineDetect() == TurnRight)//如果检测到停车线
        {
            counter++;
            if (counter == 2)
            {
                break;
            }
        }
        LineKeep(SensorStatus);//保持车道(车道保持也有转弯功能)
    }
    motor(50,50);//前进
    Delay_ms(500);//延时
    while(1)
    {
        motor(50,50);//前进
        if (Sensor(1)||Sensor(2)||Sensor(3)||Sensor(4))//如果检测到线
        {
            motor(0,0);//停车
            break;
        }
    }
END:
    LED(1,1);//点亮LED
    motor(0,0);//停车
}