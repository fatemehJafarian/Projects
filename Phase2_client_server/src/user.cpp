#include "user.hpp"

User::User()
{

}

User::User(string username , string display_name , string password)
{
	this->username = username;
	this->display_name = display_name;
	this->password = password;
}

bool User::check_username(string username)
{
	if (this->username == username)
		return true;
	return false;
}

bool User::check_matching(string username , string password)
{
	if (this->username == username && this->password == password)
		return true;
	return false;
}

bool User::add_jeek(string text , string new_tag , string new_mention , string command)
{
	Jeek* new_jeek = new Jeek();
	if (new_jeek->add_jeek(username , jeeks.size() , text , new_tag , new_mention , command))
	{
		jeeks.push_back(new_jeek);
		return true;
	}
	else
	{
		new_jeek = NULL;
		delete new_jeek;
		return false;
	}
}

string User::check_tags(string tag)
{
	for (int i = 0 ; i < jeeks.size() ; i++)
	{
		if (jeeks[i]->check_tag(tag))
			return jeeks[i]->show(display_name);
	}
	return " ";
}

string User::show_jeeks()
{
	string result;
	for (int i = jeeks.size() - 1 ; i >= 0 ; i--)
	{
		result += jeeks[i]->show(display_name);
	}
	return result;
}

void User::rejeek(string text)
{
	Jeek* new_jeek = new Jeek();
	new_jeek->rejeek(text , username , jeeks.size());
}

Jeek* User::check_jeek_id(string jeek_id)
{
	for (int i = 0 ; i < jeeks.size() ; i++)
	{
		if (jeeks[i]->check_jeek_id(jeek_id))
			return jeeks[i]->check_jeek_id(jeek_id);
	}
	return NULL;
}

Reaction* User::check_reaction(string text_id)
{
	for (int i = 0 ; i < jeeks.size() ; i++)
	{
		if (jeeks[i]->check_reaction(text_id))
			return jeeks[i]->check_reaction(text_id);
	}
	return NULL;
}

void User::add_follower(User* user)
{
	followers.push_back(user);
}

void User::remove_follower(User* user)
{
	followers.erase(remove(followers.begin() , followers.end() , user) , followers.end());
}

void User::add_notification(Notification* new_notification)
{
	notifications.push_back(new_notification);
}

vector <string> User::get_mentions()
{
	return jeeks[jeeks.size() - 1]->get_mentions(); 
}

string User::get_last_jeek_id() 
{ 
	return jeeks[jeeks.size() - 1]->get_jeek_id(); 
}

void User::show_notifications()
{
	for (int i = 0 ; i < notifications.size() ; i++)
	{
		notifications[i]->show();
	}
}

bool User::check_duplication(vector <User*>& users)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->get_username() == username)
			return true;
	}
	return false;

}