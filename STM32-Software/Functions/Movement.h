#ifndef __MOVEMNET_H
#define __MOVEMNET_H

void PWM_Init(void);
void PWM_SetCompare1(int Compare);
void PWM_SetCompare2(int Compare);
void LeftMotor_Forward(void);
void LeftMotor_Reverse(void);
void RightMotor_Forward(void);
void RightMotor_Reverse(void);
void motor(int Left_Speed,int Right_Speed);
#endif
