#include "Decision.h"
#include <process.h>
#include <iostream>

using namespace std;

unsigned int __stdcall threadFunction(void *object)
{
	Decision *decision=(Decision *) object;
	return (unsigned int ) decision->run(decision->param);
}

Decision::Decision()       //类成员初始化
{
	started=false;
	detached=false;
}

Decision::~Decision()
{
	stop();
}

int Decision::start(void *pra)
{
	//msg的指针指向pra,pra指向输入
	char *msg=(char *)pra;
	cout<<msg<<endl;
	if (!started)
        {
                param = pra;
                if (threadHandle = (HANDLE)_beginthreadex(NULL, 0, threadFunction, this, 0, &threadID))
                {
                        if (detached)
                        {
                                CloseHandle(threadHandle);
                        }
                        started = true;
                }
        }
        return started;
}

void *Decision::wait()
{
	DWORD status = (DWORD) NULL;
        if (started && !detached)
        {
                WaitForSingleObject(threadHandle, INFINITE);
                GetExitCodeThread(threadHandle, &status);       
                CloseHandle(threadHandle);
                detached = true;
        }
        return (void *)status;
}

void Decision::detach()
{
	if(started&&!detached)
	{
		CloseHandle(threadHandle);
	}
	detached=true;
}

void Decision::stop()
{
	if(started&&!detached)
	{
		TerminateThread(threadHandle,0);
		CloseHandle(threadHandle);
		detached=true;

	}
	/*detached=true;*/
}

void Decision::sleep(unsigned int delay)
{
        ::Sleep(delay);
}