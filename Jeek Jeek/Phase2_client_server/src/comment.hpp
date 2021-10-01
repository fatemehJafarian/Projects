#ifndef __COMMENT_H__
#define __COMMENT_H__

#include "reaction.hpp"

using namespace std;

class User;

class Comment : public Reaction
{
public:
	Comment(string comment_text , User* login_user , string id);
	void show();
};

#endif