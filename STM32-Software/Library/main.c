#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

int isCurrentPressed = 1;
int LEDStatus = 1;

// 初始化GPIO
void init_GPIO(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    // 启用GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    // 配置GPIOA Pin 0为推挽输出（LED）
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    // 配置GPIOA Pin 6为输入上拉（按钮）
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void switch_LED()
{
    if (LEDStatus)
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_0);
    }
    else
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_0);
    }
}

void status_Manager()
{
    isCurrentPressed = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6);// 获取按钮状态
    if (isCurrentPressed == 1)// 按钮被按下
    {
        for (int i = 0; i < 100000; i++){}
        while(isCurrentPressed == 1)// 等待按钮释放
        {
            for (int i = 0; i < 100000; i++){}
            isCurrentPressed = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6); // 更新按钮状态
        }
        LEDStatus = !LEDStatus;
        switch_LED();
    }
}

int main(void)
{
    init_GPIO();
    GPIO_SetBits(GPIOA, GPIO_Pin_0);
    while (1)
    {
        status_Manager(); // 管理LED和按钮的状态
    }
    return 0;
}
