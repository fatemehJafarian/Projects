#ifndef __REACTION_H__
#define __REACTION_H__

#include <vector>
#include <sstream>
#include "user.hpp"

using namespace std;

#define UNDER_LINE '_'

class User;

class Reaction
{
public:
	Reaction();
	string convert_int_to_string(int num);
	Reaction* check_reaction(string text_id);
	virtual void reply(string reply_text , User* login_user , string text_id) {}
	virtual void show() {}
	string get_id() { return id; }
protected:
	string text;
	string id;
	User* user;
	vector <Reaction*> replies;
};

#endif 