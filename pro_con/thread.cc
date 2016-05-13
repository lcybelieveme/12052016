///
///@date   2016-05-12 22:09:55
///
 
 
#include "thread.hh"

namespace wd
{
Thread::Thread()
:_pId(0)
,isrunning(false)
{
}

Thread::~Thread()
{
	if(isrunning)
	{
		pthread_detach(_pId);
	}
}

void Thread::start()
{
	pthread_create(&_pId,NULL,ThreadFunc,this);
	isrunning=true;
}

void Thread::join()
{
	if(isrunning)
	{
		pthread_join(_pId,NULL);
		isrunning=false;
	}
}

void*Thread::ThreadFunc(void*rhs)
{
	Thread*pth=static_cast<Thread*>(rhs);
	if(pth)
		pth->run();
}

}//endof namespace wd;
