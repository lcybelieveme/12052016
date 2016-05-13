
#ifndef __MY_BUFFER_HH__
#define __MY_BUFFER_HH__
#include "thread.hh"
#include "condition.hh"
#include "mutex.hh"
#include <queue>

namespace wd
{
using std::queue;

class buff
{
public:
	buff(int);
	void push(int);
	int pop();

	bool empty();
	bool full();
private:
	mutexlock _mutex;
	condition _notEmpty;
	condition _notFull;
	int _quesize;
	queue<int> _que;
};


}//endof namespace wd;

#endif
