///
///@date   2016-05-12 22:57:15
///
 
 
#include "buffer.hh"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class producer:public wd::Thread
{
public:
	producer(wd::buff &b)
	:_buf(b)
	{}
 void run()
	{
		srand(time(NULL));
		while(1)
		{
			int num=rand()%100;
			cout<<"produce "<<num<<endl;
			_buf.push(num);
			sleep(1);
		}
	}
private:
	wd::buff& _buf;
};

class consumer:public wd::Thread
{
public:
	consumer(wd::buff &b)
	:_buf(b)
	{}

	void run()
	{
		while(1)
		{
			cout<<"consume "<<_buf.pop()<<endl;
			sleep(2);
		}
	}
private:
	wd::buff& _buf;
};

int main()
{
	wd::buff buf(10);
	wd::Thread *ppro=new producer(buf);
	wd::Thread *pcon=new consumer(buf);

	ppro->start();
	pcon->start();
	ppro->join();
	pcon->join();

	return 0;
}
