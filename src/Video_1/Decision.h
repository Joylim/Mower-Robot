//≥ÈœÛ¿‡
#ifndef _DECISION_H
#define _DECISION_H

#include<windows.h>

static unsigned int __stdcall threadFunction(void *);

class Decision
{
	friend unsigned int __stdcall threadFunction(void *);

public:
	Decision();
	virtual ~Decision();
	int start(void * =NULL);
	void stop();
	void detach();
	void *wait();
	static void sleep(unsigned int);

private:
	unsigned int threadID;
	bool started;
	bool detached;
	HANDLE threadHandle;
	void *param;

protected:
	 virtual void * run(void *) = 0;
};
#endif