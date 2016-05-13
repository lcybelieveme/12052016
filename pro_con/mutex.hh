
#ifndef __MY_MUTEX_HH__
#define __MY_MUTEX_HH__
#include "Noncpyable.hh"
#include <pthread.h>

namespace wd
{
class mutexlock:Noncpyable
{
public:
	mutexlock();
	~mutexlock();
	void lock();
	void unlock();
	pthread_mutex_t*getMutex();
private:
	pthread_mutex_t _mutex;
	bool _islocked;
};
}//endof namespace wd;

#endif
