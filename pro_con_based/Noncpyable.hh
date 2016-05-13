
#ifndef __MY_NONCPYABLE_HH__
#define __MY_NONCPYABLE_HH__

#include <pthread.h>
namespace wd
{
class Noncpyable
{
protected:
	Noncpyable(){}
private:
	Noncpyable(const Noncpyable&rhs){};
	Noncpyable&operator=(const Noncpyable&rhs){};
};
}//endof namespace ed;

#endif
