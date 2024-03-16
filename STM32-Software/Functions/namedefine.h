/*为了方便开发，我们将GPIO引脚的编号定义为对于外设的名称，这样在开发时就不需要记住引脚的编号了
这个文件定义了一些常用的引脚名称，以及一些常用的引脚编号
这个文件是一个头文件，可以被其他文件包含
*/

//电机类
#define MotorLeftSwitch GPIOA_Pin_0//电机开关
#define MotorLeftForward GPIOA_Pin_1//左电机正转
#define MotorLeftBackward GPIOA_Pin_2//左电机反转
#define MotorRightForward GPIOA_Pin_4//右电机正转
#define MotorRightBackward GPIOA_Pin_8//右电机反转

/*
//传感器类(废弃)
#define LightSensor1 GPIOA_Pin_5//循迹传感器1
#define LightSensor2 GPIOA_Pin_6//循迹传感器2
#define LightSensor3 GPIOA_Pin_7//循迹传感器3
#define LightSensor4 GPIOB_Pin_0//循迹传感器4
#define LightSensor5 GPIOB_Pin_1//循迹传感器5（在车头正中间，用来检测终点）
#define Button1 GPIOB_Pin_1//按钮1
*/

//其他的输出
#define LED1 GPIOB_Pin_5//LED1
#define LED2 GPIOB_Pin_6//LED2
#define LED3 GPIOB_Pin_7//LED3
#define Beep GPIOB_Pin_8//蜂鸣器


