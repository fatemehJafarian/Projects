#ifndef __USER_H__
#define __USER_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include "jeek.hpp"
#include "notification.hpp"
#include "like_notification.hpp"
#include "dislike_notification.hpp"
#include "comment_notification.hpp"
#include "reply_notification.hpp"
#include "jeek_notification.hpp"
#include "mention_notification.hpp"
#include "rejeek_notification.hpp"

using namespace std;

class Jeek;
class Reaction;

class User
{
public:
	User();
	User(string username , string display_name , string password);
	string get_username() { return username; }
	bool check_username(string username);
	bool check_matching(string username , string password);
	bool add_jeek(string text , string new_tag , string new_mention , string command);
	string check_tags(string tag);
	string show_jeeks();
	void reply(string text_id , string reply_text , User* login_user);
	void rejeek(string text);
	Jeek* check_jeek_id(string jeek_id);
	string get_display_name() { return display_name; }
	Reaction* check_reaction(string text_id);
	vector <string> get_mentions();
	void add_notification(Notification* new_notification);
	void add_follower(User* user);
	string get_last_jeek_id();
	void remove_follower(User* user);
	vector <User*> get_followers() { return followers; }
	void show_notifications();
	bool check_duplication(vector <User*>& users);
private:
	vector <Jeek*> jeeks;
	string username;
	string display_name;
	string password;
	vector <User*> followers;
	vector <Notification*> notifications;
};

#endif