#ifndef __MY_THREAD_HH__
#define __MY_THREAD_HH__

#include "Noncpyable.hh"
#include <functional>
namespace wd
{
class Thread:Noncpyable
{
public:
	typedef std::function<void()> Threadcallback;
	Thread(Threadcallback cb);
	~Thread();

	void start();
	void join();
	static void*ThreadFunc(void*);
//	virtual void run()=0;
private:
	pthread_t _pId;
	Threadcallback _cb;
	bool isrunning;
};

}//endof namespace wd;

#endif
