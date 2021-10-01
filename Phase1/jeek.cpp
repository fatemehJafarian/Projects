#include "jeek.hpp"
#include "reply.hpp"
#include "comment.hpp"

Jeek::Jeek()
{
	num_of_dislikes = 0;
	num_of_likes = 0;
	num_of_rejeeks = 0;
}

string convert_int_to_string(int num)
{
	stringstream help;
	help << num;
	string result = help.str();
	return result;
}

bool Jeek::add_jeek(string username , int num)
{
	while (!EXIT)
	{
		string command;
		cin >> command;
		if (command == "text")
		{
			string new_text;
			cin >> new_text;
			text = new_text;
		} 
		else if (command == "tag")
		{
			string new_tag;
			cin >> new_tag;
			tags.push_back(new_tag);
		}
		else if (command == "mention")
		{
			string new_mention;
			cin >> new_mention;
			mentions.push_back(new_mention);
		}
		else if (command == "publish")
		{
			jeek_id = username + UNDER_LINE + convert_int_to_string(num);
			return true;
		}
		else if (command == "abort")
		{
			return false;
		}
	}
}

bool Jeek::search_jeek(string jeek_id)
{
	if (this->jeek_id == jeek_id)
		return true;
	return false;
}

void Jeek::show_jeek(string user_display_name)
{
	cout << user_display_name << "	" << text << endl;
	for (int i = 0 ; i < tags.size() ; i++)
		cout << HASH_TAG << tags[i] << endl;
	for (int i = 0 ; i < mentions.size() ; i++)
		cout << AT_SIGN << mentions[i] << endl;
	cout << "Likes " << num_of_likes << endl << "Rejeeks " << num_of_rejeeks << endl << "comments:\n";
	for (int i = 0 ; i < comments.size() ; i++)
		cout << comments[i]->get_id();
}

bool Jeek::check_tag(string tag)
{
	for (int i = 0 ; i < tags.size() ; i++)
	{
		if (tags[i] == tag)
			return true;
	}
	return false;
}

Jeek* Jeek::check_jeek_id(string jeek_id)
{
	if (this->jeek_id == jeek_id)
		return this;
	return NULL;
}

void Jeek::show(string user_display_name)
{
	cout << jeek_id << "	" << user_display_name << endl << text << endl;
}

void Jeek::add_comment(Comment* new_comment , string comment_text , User* login_user)
{
	string id = jeek_id + UNDER_LINE + convert_int_to_string(comments.size());
	new_comment = new Comment(comment_text , login_user , id);
	comments.push_back(new_comment);	
}

void Jeek::add_reply(string text_id , string reply_text , User* login_user , vector <Reaction*>& replies)
{
	string id = text_id + UNDER_LINE + convert_int_to_string(replies.size());
	Reply* new_reply = new Reply(reply_text , id , login_user);
	replies.push_back(new_reply);
}

void Jeek::add_num_of_rejeeks()
{
	num_of_rejeeks++;
}

void Jeek::rejeek(string text , string username , int num)
{
	this->text = text;
	jeek_id = username + UNDER_LINE + convert_int_to_string(num);
}

void Jeek::like()
{
	num_of_likes++;
}

void Jeek::dislike()
{
	num_of_dislikes++;
}

Reaction* Jeek::check_reaction(string text_id)
{
	for (int i = 0 ; i < comments.size() ; i++)
	{
		if (comments[i]->check_reaction(text_id))
			return comments[i]->check_reaction(text_id);
	}
	return NULL;	
}