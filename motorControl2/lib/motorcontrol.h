
#ifndef __MOTOR_CONTROL_H__
#define __MOTOR_CONTROL_H__

#define MOTORL1 0
#define MOTORL2 1

#define MOTORR1 3
#define MOTORR2 4

extern int LEFT = -1;
extern int RIGHT = -1;
extern int BACK = -1;
extern int  FORWARD = -1;

/*
  speed = 1: slow
  speed = 2: normal
  speed = 3: fast
*/
extern int SPEED = 2;

extern void delay100(int n);
extern void motorControl_init();

extern void leftForward();
extern void rightForward();
extern void leftBack();
extern void rightBack();

extern void robotForward();
extern void robotBack();
extern void robotLeft(int ang);
extern void robotRight(int ang);


//void robotRun();
extern void robotStop();
extern void robotStart();
extern void robotPause();

extern void test();

#endif
