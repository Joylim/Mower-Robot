#include <wiringPi.h>
#include <unistd.h>

#define motorL1 0
#define motorL2 1

#define motorR1 3
#define motorR2 4

/*
  direction control
  LEFT: means turn left
  RIGHT: means turn right
  BACK: means move back
  FORWARD: means move forward
*/
int LEFT = -1;
int RIGHT = -1;
int BACK = -1;
int FORWARD = -1;

/*
  speed control
  SLOW: means move SLOWLY
  FAST: means move fast
*/
int SLOW = -1;
int FAST = -1;

void delay100(int n){
    int i,j,k;
    for (i=0;i<n;i++)
        for(j=0;j<100;j++)
        {
            k = k + 1;
            k = k - 1;
        }
}
void motorControl_init(){
    wiringPiSetup();

    pinMode(motorL1, OUTPUT);
    pinMode(motorL2, OUTPUT);
    pinMode(motorR1, OUTPUT);
    pinMode(motorR2, OUTPUT);

    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,LOW);
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,LOW);
    delay100(10);
}

void leftForward(){
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    delay100(10);
}

void rightForward(){
    digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    delay100(10);
}

void leftBack(){
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,HIGH);
    delay100(10);
}

void rightBack(){
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,HIGH);
    delay100(10);
}
//function

void robotForward(){
    motorControl_init();
    leftForward();
    rightForward();
    delay100(10);
}

void robotBack(){
    motorControl_init();
    leftBack();
    rightBack();
    delay100(10);
}

void robotLeft(){
    motorControl_init();
    leftBack();
    rightForward();
    delay100(10);
}

void robotRight(){
    motorControl_init();
    leftForward();
    rightBack();
    delay100(10);
}
void robotRun(){
    if(1==FORWARD)
	robotForward();
    else if(1==LEFT)
	robotLeft();
    else if(1==RIGHT)
	robotRIGHT();
    else if(1==BACK)
	robotBck();
    FORWARD = 0;
    BACK = 0;
    LEFT = 0;
    RIGHT = 0;
}
void robotStop(){
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,LOW);
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,LOW);
}

void test1();

int main()
{
    
    test1();
    return 0;
}
void test1(){
    FORWARD = 1;
    robotRun();
    sleep(100);
    LEFT = 1;
    robotRun();
    sleep(10);
    BACK = 1;
    robotRun();
    sleep(10);
    FORWARD = 1;
    sleep(100);
    robotStop();
}
