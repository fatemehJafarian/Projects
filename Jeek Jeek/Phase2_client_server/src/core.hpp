#ifndef __Core_H__
#define __Core_H__

#include <vector>
#include <string>
#include <cstdlib>	
#include "user.hpp"
#include "bad_exception.hpp"
#include "invalid_input.hpp"
#include "no_login_user.hpp"
#include "duplicate_user.hpp"
							
using namespace std;

#define HASH_TAG '#'
#define AT_SIGN '@'

struct Session_Information
{
    string session_id;
    User* user;
};

typedef Session_Information Session_Information;

class Core
{
public:
	Core();
	User* search_user(string username , string password);
	string search_jeeks_of_user(string username);
	string search_jeeks_by_hash_tag(string tag);
	Jeek* search_jeek(string jeek_id);
	User* search_user(string jeek_id);
	User* find_user(string username);
	Reaction* search_reaction(string text_id);	
	bool signup(string username , string display_name , string password);
	bool login(string username , string password);
	void logout();
	string search(string string_to_search);
	string show_jeek(string jeek_id);
	void show_comment();
	void show_reply();
	void jeek(string text , string new_tag , string new_mention , string command);
	void comment();
	void reply();
	void rejeek(string jeek_id);
	void dislike(string jeek_id);
	void like(string jeek_id);
	void follow(string username);
	void unfollow(string username);
	string make_session_information();
	bool check_session_id_duplication(string session_id);
	string find_username(string session_id);
	void delete_session_id(string session_id);
	int find_session_information(User* user);
	void set_login_user(string session_id);
private:
	vector <User*> users;
	User* login_user;
	vector <Session_Information> sessions_information;
};

#endif