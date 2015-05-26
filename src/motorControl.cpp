#include "motorControl.h"
//#include <softPwm.h>

/*
  TODO: ADD SPEED CONTROL BY USING PWM
  int softPwmCreate(int pin, int initialVal,int pwmRange);
  if return 0  :success
  void softPwmWrite(int pin, int value);
  update PWM value
  an example:
  pinMode(GPIO1,OUTPUT);
  digitalWrite(GPIO1,LOW);
  softPwmCreate(GPIO1,0,200);//basic pulse unit is 100 micro 200*100=20ms
  softPWMWrite(GPIO1,15);
  compile: cc -o * *.cpp -lwiringPi -lpthread
  
*/


void delay100(int n){
    int i,j,k;
    for (i=0;i<n;i++)
        for(j=0;j<100;j++)
        {
            k++;
            k--;
        }
}
void delay10000(int n){
   int i,j,k;
   for(i = 0;i<n;i++)
      for(j = 0;j<10000;j++)
       {
           k++;
           k--;
       }
}
void delaySec(int n){
    for(int i = 0;i<n;i++)
	delay(1000);
}

void motorControl_init(){
    wiringPiSetup();

    pinMode(MOTORL1, OUTPUT);
    pinMode(MOTORL2, OUTPUT);
    pinMode(MOTORR1, OUTPUT);
    pinMode(MOTORR2, OUTPUT);

    digitalWrite(MOTORL1,LOW);
    digitalWrite(MOTORL2,LOW);
    digitalWrite(MOTORR1,LOW);
    digitalWrite(MOTORR2,LOW);
    delay100(10);
}

void motorClear(){
    digitalWrite(MOTORL1,LOW);
    digitalWrite(MOTORL2,LOW);
    digitalWrite(MOTORR1,LOW);
    digitalWrite(MOTORR2,LOW);
    delay100(3);
}

void leftForward(){
    digitalWrite(MOTORL1,HIGH);
    digitalWrite(MOTORL2,LOW);
    delay100(2);
}

void rightForward(){
    digitalWrite(MOTORR1,HIGH);
    digitalWrite(MOTORR2,LOW);
    delay100(2);
}

void leftBack(){
    digitalWrite(MOTORL1,LOW);
    digitalWrite(MOTORL2,HIGH); 
    delay100(2);
}

void rightBack(){
    digitalWrite(MOTORR1,LOW);
    digitalWrite(MOTORR2,HIGH);
    delay100(2);
}


//function

void robotForward(){
    motorClear();
    leftForward();
    rightForward();
    delay100(10);
}

void robotBack(){
    motorClear();
    leftBack();
    rightBack();
    delay100(10);
}

void robotLeft(int ang){
    motorClear();
    leftBack();
    rightForward();
    delay10000(ang*30);
    motorClear();
}


void robotRight(int ang){
    motorClear();
    leftForward();
    rightBack();
    delay10000(50*ang);
    motorClear();
}

void robotPause(){
    digitalWrite(MOTORL1,LOW);
    digitalWrite(MOTORL2,LOW);
    digitalWrite(MOTORR1,LOW);
    digitalWrite(MOTORR2,LOW);
}

//need to update
void robotStop(){
   robotPause();
}

void robotStart(){
    motorControl_init();
}

//SPEED CONTROL
//test
void test()
{
   robotStart();
   delay(20);
   //forward 8s
   robotForward();
   delaySec(3);
   robotStop();
   delaySec(1);
   robotLeft(90);
   robotStop();
   delaySec(1);
   robotForward();
   delaySec(3);
   robotStop();
   delaySec(1);
   robotLeft(90);
   robotStop();
   delaySec(1);
   robotForward();
   delaySec(3);
   robotStop();
   delaySec(1);
   robotLeft(90);
   robotStop();
   delaySec(1);
   robotForward();
   delaySec(3);
   robotStop();
}
int main()
{
  test();
  return 0;
}
