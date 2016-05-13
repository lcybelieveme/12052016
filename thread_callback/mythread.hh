
#ifndef __MY_THREAD_HH__
#define __MY_THREAD_HH__

#include "Noncpyable.hh"
#include <pthread.h>
#include <functional>

namespace wd
{
class Thread:Noncpyable
{
public:
	Thread(std::function<void()> Threadcallback);
	~Thread();

	pthread_mutex_t*getMutex();
	void start();
	void join();
	
	static void* ThreadFunc(void*);
	void setcallback(std::function<void()> );
private:
	pthread_t _mutex;
	bool isrunning;
	std::function<void()> _Threadcallback;
};
}//endof namespace std;

#endif
