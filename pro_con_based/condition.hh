
#ifndef __MY_CONDITION_HH__
#define __MY_CONDITION_HH__

#include "Noncpyable.hh"
#include "mutex.hh"

namespace wd
{
class condition:Noncpyable
{
public:
	condition(mutexlock&);
	~condition();
	
	void wait();
	void notify();
	void notifyall();

private:
	mutexlock &_mutex;
	pthread_cond_t _cond;
};
}//endof namespace wd;


#endif
