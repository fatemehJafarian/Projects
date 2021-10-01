#ifndef __NO_LOGIN_USER_H__
#define __NO_LOGIN_USER_H__

#include "bad_exception.hpp"

using namespace std;

class No_Login_User : public bad_exception
{
public:
	void what_exception();
};

#endif