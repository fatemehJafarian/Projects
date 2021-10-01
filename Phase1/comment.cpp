#include "comment.hpp"

Comment::Comment(string comment_text , User* login_user , string id)
{
	text = comment_text;
	user = login_user;
	this->id = id;
}

void Comment::show()
{
	cout << user->get_display_name() << endl << text << "\nRepleis:\n";
	for (int i = 0 ; i < replies.size() ; i++)
	{
		cout << replies[i]->get_id() << endl;
	}
}