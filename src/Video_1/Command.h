#include <iostream>
#include"Decision.h"

using namespace std;

#ifndef _COMMAND_H
#define _COMMAND_H

class Command:public Decision
{
protected:
	void *run(void * param)
	{
		char *msg=(char*) param;
		cout<<msg<<endl;
		sleep(100);
		cout<<"Get out of here!"<<endl;
		return NULL;
	}
};

#endif