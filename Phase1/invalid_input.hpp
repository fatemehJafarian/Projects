#ifndef __INVALID_INPUT_H__
#define __INVALID_INPUT_H__

#include "bad_exception.hpp"

using namespace std;

class Invalid_Input : public bad_exception
{
public:
	void what_exception();
};

#endif