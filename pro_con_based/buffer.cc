///
///@date   2016-05-12 22:37:48
///
 
 
#include "buffer.hh"

namespace wd
{
buff::buff(int size)
:_quesize(size)
,_mutex()
,_notEmpty(_mutex)
,_notFull(_mutex)
{
}

bool buff::empty()
{
	return _que.empty();
}

bool buff::full()
{
	return _que.size()==_quesize;
}

void buff::push(int rhs)
{
	_mutex.lock();

	while(full())
	{
		_notFull.wait();
	}
	_que.push(rhs);
	_notEmpty.notify();
	_mutex.unlock();
}

int buff:: pop()
{
	_mutex.lock();
	
	while(empty())
	{
		_notEmpty.wait();
	}
	int num=_que.front();
	_que.pop();
	_notFull.notify();
	_mutex.unlock();
	return num;
}



}//endof namespace wd;
