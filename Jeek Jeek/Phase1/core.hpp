#ifndef __Core_H__
#define __Core_H__

#include <vector>
#include "user.hpp"
#include "bad_exception.hpp"
#include "invalid_input.hpp"
#include "no_login_user.hpp"
#include "duplicate_user.hpp"
							
using namespace std;

#define HASH_TAG '#'
#define AT_SIGN '@'

class Core
{
public:
	Core();
	void get_and_execute_command();
	User* search_user(string username , string password);
	void search_jeeks_of_user(string username);
	void search_jeeks_by_hash_tag(string tag);
	Jeek* search_jeek(string jeek_id);
	User* search_user(string jeek_id);
	User* find_user(string username);
	Reaction* search_reaction(string text_id);	
	void signup(string username , string display_name , string password);
	bool login(string username , string password);
	void search();
	void show_jeek(string jeek_id);
	void show_comment();
	void show_reply();
	void jeek();
	void comment();
	void reply();
	void rejeek();
	void dislike();
	void like();
	void follow();
	void unfollow();
private:
	vector <User*> users;
	User* login_user;
};

#endif