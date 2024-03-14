#include "stm32f10x.h"                  // Device header
#include "PWM.h"

#define MotorLeftSwitch GPIOA, GPIO_Pin_0//左电机转向控制
#define MotorLeftForward GPIOA, GPIO_Pin_1//左电机正转
#define MotorLeftBackward GPIOA, GPIO_Pin_2//左电机反转
#define MotorRightForward GPIOA, GPIO_Pin_3//右电机正转
#define MotorRightBackward GPIOA, GPIO_Pin_4//右电机反转

void motor(int left, int right)//电机控制，left为左侧电机的PWM占空比（0-100），right为右侧电机的PWM占空比，为负数代表反转
{
	if (left > 100)//预处理输入值
		left = 100;
	if (left < -100)
		left = -100;
	if (right > 100)
		right = 100;
	if (right < -100)
		right = -100;
	for (int i = 0; 1<1000; i++)//控制电机转动
	{
		if (left > 0)
		{
			
		}
		else
		{
			
		}
		if (right > 0)
		{
			
		}
		else
		{
			
		}
	}
	
}

