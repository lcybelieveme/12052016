///
///@date   2016-05-12 20:01:11
///
 
 
#include "mythread.hh"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;

class Task
{
public:
	void fun()
	{
		srand(time(NULL));
		while(1)
		{
			cout<<rand()%100<<endl;
			sleep(1);
		}
	}
};


int main()
{
	Task task;
	wd::Thread thread(std::bind(&Task::fun,&task));
	thread.start();
	thread.join();

	return 0;
}
