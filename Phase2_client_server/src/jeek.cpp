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

bool Jeek::add_jeek(string username , int num , string new_text , string new_tag , string new_mention , string command)
{
	text = new_text;
	tags.push_back(new_tag);
	mentions.push_back(new_mention);
	if (command == "publish")
	{
		jeek_id = username + UNDER_LINE + convert_int_to_string(num);
		return true;
	}
	else if (command == "abort")
	{
		return false;
	}
}

bool Jeek::search_jeek(string jeek_id)
{
	if (this->jeek_id == jeek_id)
		return true;
	return false;
}

string Jeek::show_jeek(string user_display_name)
{
	string result;
	result += "<div style=\"background-color: #DCDCDC;\">";
	result += user_display_name;
	result += " ";
	result += text;
	result += "<br/>";
	for (int i = 0 ; i < tags.size() ; i++)
	{
		result += HASH_TAG + tags[i];
		result += "<br/>";
	}
	for (int i = 0 ; i < mentions.size() ; i++)
	{
		result += AT_SIGN + mentions[i];
		result += "<br/>";
	}
	result += "Likes ";
	result += to_string(num_of_likes);
	result += "		Dislikes ";
	result += to_string(num_of_dislikes);
	result += "		Rejeeks " ;
	result += to_string(num_of_rejeeks);
	result += "<br/>";
	result += "<span style=\"display: inline;\">";
	result += "<form action=\"/rejeek\" method=\"post\">";
	result += "<button name=\"button\" value=\"";
	result += jeek_id;
	result += "\" type=\"submit\" style=\"display:inline;\">Rejeek</button>";
	result += "</form>";
	result += "<form action=\"/like\" method=\"post\">";
	result += "<button name=\"button\" value=\"";
	result += jeek_id;
	result += "\" type=\"submit\" style=\"display:inline;\"><img src=\"/like_image\" width=\"24\" height=\"24\"></button>";
	result += "</form>";
	result += "<form action=\"/dislike\" method=\"post\">";
	result += "<button name=\"button\" value=\"";
	result += jeek_id;
	result += "\" type=\"submit\" style=\"display:inline;\"><img src=\"/dislike_image\" width=\"24\" height=\"24\"></button>";
	result += "</form></span><br/>";
	result += "</div><br/>";
	return result;
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

string Jeek::show(string user_display_name)
{
	string result;
	result += "<div style=\"background-color: #DCDCDC;\">";
	result += jeek_id;
	result += " ";
	result += user_display_name;
	result += "<br/>";
	result += text;
	result += "<br/>";
	result += "<form action=\"/jeekDetails\" method=\"post\">";
	result += "<button name=\"details\" value=\"";
	result += jeek_id;
	result += "\" type=\"submit\" style=\"display:inline-block; width: 15%; padding: 7px;\">More Details</button>";
	result += "</form></div><br/>";
	return result;
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