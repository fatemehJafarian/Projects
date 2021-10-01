#ifndef __REPLY_H__
#define __REPLY_H__

#include "reaction.hpp"

using namespace std;

class User;

class Reply : public Reaction
{
public:
	Reply();
	Reply(string reply_text , string id , User* login_user);
	void reply(string reply_text , User* login_user , string text_id);
	void show();
};

#endif