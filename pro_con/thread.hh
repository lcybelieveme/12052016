#ifndef __MY_THREAD_HH__
#define __MY_THREAD_HH__

#include "Noncpyable.hh"
namespace wd
{
class Thread:Noncpyable
{
public:
	Thread();
	~Thread();

	void start();
	void join();
	static void*ThreadFunc(void*);
	virtual void run()=0;
private:
	pthread_t _pId;
	bool isrunning;
};

}//endof namespace wd;

#endif
