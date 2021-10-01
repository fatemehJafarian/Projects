#include "reply.hpp"

Reply::Reply(string reply_text , string id , User* login_user)
{
	this->text = reply_text;
	this->id = id;
	this->user = login_user;
}

void Reply::reply(string reply_text , User* login_user , string text_id)
{
	string id = text_id + UNDER_LINE + convert_int_to_string(replies.size());
	Reply* new_reply = new Reply(reply_text , id , login_user);
	replies.push_back(new_reply);
}

void Reply::show()
{
	cout << user->get_display_name() << endl << text << "\nReplies:\n";
	for (int i = 0 ; i < replies.size() ; i++)
	{
		cout << replies[i]->get_id() << endl;
	}
}