///
///@date   2016-05-12 21:42:54
///
 
 
#include "mutex.hh" 

namespace wd
{	
mutexlock::mutexlock()
:_islocked(false)
{
	pthread_mutex_init(&_mutex,NULL);
}

mutexlock::~mutexlock()
{
	pthread_mutex_destroy(&_mutex);
}

void mutexlock::lock()
{
	pthread_mutex_lock(&_mutex);
	_islocked=true;
}

void mutexlock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_islocked=false;
}

pthread_mutex_t*mutexlock::getMutex()
{
	return &_mutex;
}

}//endof namespace wd;
