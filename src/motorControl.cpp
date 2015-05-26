#include "motorControl.h"

void delay100(int n){
    int i,j,k;
    for (i=0;i<n;i++)
        for(j=0;j<100;j++)
        {
            k++;
            k--;
        }
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

void robotLeft(){
    motorClear();
    leftBack();
    rightForward();
    delay100(10);
}

void robotRight(){
    motorClear();
    leftForward();
    rightBack();
    delay100(10);
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

int main()
{
  robotStart();
  robotBack();
  robotStop();
  return 0;
}
