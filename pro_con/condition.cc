///
///@date   2016-05-12 21:56:22
///
 
 
#include "condition.hh"

namespace wd
{
condition::condition(mutexlock&mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}
condition::~condition()
{
	pthread_cond_destroy(&_cond);
}

void condition::wait()
{
	pthread_cond_wait(&_cond,_mutex.getMutex());
}

void condition::notify()
{
	pthread_cond_signal(&_cond);
}

void condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}


}//endof namespace wd;
