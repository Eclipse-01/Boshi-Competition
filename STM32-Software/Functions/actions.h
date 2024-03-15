/*
Actions库将巡线任务的不同子任务进行封装，方便在主程序中调用。
*/
#ifndef __ACTIONS_H
#define __ACTIONS_H

int LineDetcet(void);
int LineKeep(int LineStatus);
int AutoPark(void);
int DriveOut(void);
int SwitchLane(void);

#endif