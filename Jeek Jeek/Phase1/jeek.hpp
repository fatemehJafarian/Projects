#ifndef __JEEK_H__
#define __JEEK_H__


#include <vector>
#include <iostream>
#include <sstream>
#include "user.hpp"
#include "reaction.hpp"

using namespace std;

#define EXIT false
#define HASH_TAG '#'
#define AT_SIGN '@'
#define UNDER_LINE '_'

class User;
class Reaction;
class Reply;
class Comment;


class Jeek
{
public:
	Jeek();
	bool add_jeek(string username , int num);
	bool search_jeek(string jeek_id);
	void show_jeek(string user_display_name);
	bool check_tag(string tag);
	Jeek* check_jeek_id(string jeek_id);
	void add_comment(Comment* new_comment , string comment_text , User* login_user);
	void add_reply(string text_id , string reply_text , User* login_user , vector <Reaction*>& replies);
	void add_num_of_rejeeks();
	void show(string user_display_name);
	string get_text() { return text; }
	string get_jeek_id() { return jeek_id; }
	void rejeek(string text , string username , int num);
	void like();
	void dislike();
	Reaction* check_reaction(string text_id);
	vector <string> get_mentions() { return mentions; }
private:
	string text;
	vector <string> tags;
	vector <string> mentions;
	string jeek_id;
	int num_of_dislikes;
	int num_of_likes;
	int num_of_rejeeks;
	vector <Comment*> comments;
};

#endif