///
///@date   2016-05-12 19:32:45
///
 
 
#include "mythread.hh"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace wd
{
Thread::Thread(std::function<void() > Threadcallback)
:_Threadcallback(Threadcallback)
,isrunning(false)
,_mutex(0)
{
}

Thread::~Thread()
{
	if(isrunning)
	{
		isrunning=false;
		pthread_detach(_mutex);
	}
}

void Thread::setcallback(std::function<void()> rhs)
{
	_Threadcallback=rhs;
}

void Thread::start()
{
	isrunning=true;
	pthread_create(&_mutex,NULL,&Thread::ThreadFunc,this);
}

void Thread::join()
{
	if(isrunning)
	{
		pthread_join(_mutex,NULL);
		isrunning=false;
	}
}
#if 1
void *Thread::ThreadFunc(void*arg)
{
	Thread*pt=static_cast<Thread*>(arg);
	if(pt)
	{
		pt->_Threadcallback();
	}
}
#endif







}//endof namespace wd;
