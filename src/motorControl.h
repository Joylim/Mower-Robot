#include <wiringPi.h>
#include <unistd.h>

#define MOTORL1 0
#define MOTORL2 1

#define MOTORR1 3
#define MOTORR2 4

int LEFT = -1;
int RIGHT = -1;
int BACK = -1;
int FORWARD = -1;

/*
  speed = 1: slow
  speed = 2: normal
  speed = 3: fast
*/
int SPEED = 2;

void delay100(int n);
void motorControl_init();

void leftForward();
void rightForward();
void leftBack();
void rightBack();

void robotForward();
void robotBack();
void robotLeft(int ang);
void robotRight(int ang);


//void robotRun();
void robotStop();
void robotStart();
void robotPause();
