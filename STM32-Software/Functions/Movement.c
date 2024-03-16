#include "stm32f10x.h"                  // Device header


//PA8(Left)和PA9(Right)输出PWM
void PWM_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM1);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR自动重装
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;		//PSC预分频
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR捕获/比较器
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1 , TIM_OCPreload_Enable);
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR捕获/比较器
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM1 , TIM_OCPreload_Enable);
	
	TIM_CtrlPWMOutputs(TIM1 , ENABLE);
	
	TIM_Cmd(TIM1, ENABLE);
}
//输出不同占空比的PWM,1对应左，2对应右
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM1, Compare);
}
void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM1, Compare);
}

void LeftMotor_Forward(void)
{
	GPIO_SetBits(GPIOA , GPIO_Pin_1);
	GPIO_ResetBits(GPIOA , GPIO_Pin_2);
}
void LeftMotor_Reverse(void)
{
	GPIO_SetBits(GPIOA , GPIO_Pin_2);
	GPIO_ResetBits(GPIOA , GPIO_Pin_1);
}
void RightMotor_Forward(void)
{
	GPIO_SetBits(GPIOA , GPIO_Pin_3);
	GPIO_ResetBits(GPIOA , GPIO_Pin_4);
}
void RightMotor_Reverse(void)
{
	GPIO_SetBits(GPIOA , GPIO_Pin_4);
	GPIO_ResetBits(GPIOA , GPIO_Pin_3);
}
//设置左右电机速度，参数尽量控制在+-（50，100）之间
void motor(int16_t S,int16_t R)
{
	int Left_Speed = -S;
	int Right_Speed = -R;
	if(Left_Speed>=0)
	{
		LeftMotor_Forward();
		PWM_SetCompare1(Left_Speed);
	}
	else
	{
		LeftMotor_Reverse();
		PWM_SetCompare1(-Left_Speed);
	}
	if(Right_Speed>=0)
	{
		RightMotor_Forward();
		PWM_SetCompare2(Right_Speed);
	}
	else
	{
		RightMotor_Reverse();
		PWM_SetCompare2(-Right_Speed);
	}


}

