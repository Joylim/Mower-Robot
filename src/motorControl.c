#include <wiringPi.h>
#include <unistd.h>

#define motorL1 0
#define motorL2 1

#define motorR1 3
#define motorR2 4

void delay(int n){
    for (int i=0;i<n;i++)
        for(int j=0;j<100;j++)
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
    delay(10);
}

void leftForward(){
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    delay(10);
}

void rightForward(){
    digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    delay(10);
}

void leftBack(){
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,HIGH);
    delay(10);
}

void rightBack(){
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,HIGH);
    delay(10);
}
//function

void robotForward(){
    motorControl_init();
    leftForward();
    rightForward();
    delay(10);
}

void robotBack(){
    motorControl_init();
    leftBack();
    rightBack();
    delay(10);
}

void robotLeft(){
    motorControl_init();
    leftBack();
    rightForward();
    delay(10);
}

void robotRight(){
    motorControl_init();
    leftForward();
    rightBack();
    delay(10);
}

int main()
{
    robotForward();
    sleep(200);
    return 0;
}
