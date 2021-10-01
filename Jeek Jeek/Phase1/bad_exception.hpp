#ifndef __BAD_EXCEPTION_H__
#define __BAD_EXCEPTION_H__

#include <iostream>

using namespace std;

class Bad_Exception
{
public:
	virtual void what_exception() {}
};

#endif