///
///@date   2016-05-12 22:57:15
///
 
 
#include "buffer.hh"
#include <functional>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class producer
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

class consumer
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
	producer pro(buf);
	consumer con(buf);
	
	std::function<void()> f1=std::bind(&producer::run,pro);
	std::function<void()> f2=std::bind(&consumer::run,con);

	wd::Thread proTh(f1);
	wd::Thread conTh(f2);

	proTh.start();
	conTh.start();
	proTh.join();
	conTh.join();

	return 0;
}
