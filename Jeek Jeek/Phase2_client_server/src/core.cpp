#include "core.hpp"

Core::Core()
{
	login_user = new User();
	login_user = NULL;
}

bool Core::signup(string username , string display_name , string password)
{
	User* new_user = new User(username , display_name , password);	
	if (!new_user->check_duplication(users))
	{
		users.push_back(new_user);
		return true;
	}
	else
		return false;
}

bool Core::login(string username , string password)
{
	if(login_user = search_user(username , password))
		return true;
	return false;
}

string Core::search(string string_to_search)
{
	if (string_to_search[0] == HASH_TAG)
	{
		string_to_search = string_to_search.substr(1);
		return search_jeeks_by_hash_tag(string_to_search);
	}
	else if (string_to_search[0] == AT_SIGN)
	{
		string_to_search = string_to_search.substr(1);
		return search_jeeks_of_user(string_to_search);
	}
	return "";
}

string Core::show_jeek(string jeek_id)
{
	Jeek* jeek = new Jeek();
	jeek = search_jeek(jeek_id);
	if (jeek != NULL)
	{
		User* user = new User();
		user = search_user(jeek_id);
		if (user != NULL)
			return jeek->show_jeek(user->get_display_name());
	}
	return "";
}

void Core::show_comment()
{
	string comment_id;
	cin >> comment_id;
	Reaction* comment = new Reaction();
	comment = search_reaction(comment_id);
	if (comment != NULL)
		comment->show();
}

void Core::show_reply()
{
	string reply_id;
	cin >> reply_id;
	Reaction* reply = new Reaction();
	reply = search_reaction(reply_id);
	if (reply != NULL)
		reply->show();
}

void Core::jeek(string text , string new_tag , string new_mention , string command)
{
	if (login_user->add_jeek(text , new_tag , new_mention , command))
	{
		vector <string> mentions = login_user->get_mentions();
		for (int i = 0 ; i < mentions.size() ; i++)
		{
			if (find_user(mentions[i]))
			{
				Notification* new_notification = new Mention_Notification();
				new_notification->add_notification(login_user->get_last_jeek_id() , mentions[i]);
				User* user = new User();
				user = find_user(mentions[i]);
				user->add_notification(new_notification);
			}
		}
		vector <User*> followers = login_user->get_followers();
		for (int i = 0 ; i < followers.size() ; i++)
		{
			Notification* new_notification = new Jeek_Notification();
			new_notification->add_notification(login_user->get_last_jeek_id() , followers[i]->get_username());
			User* user = new User();
			user = find_user(followers[i]->get_username());
			user->add_notification(new_notification);
		}
	}
}

void Core::comment()
{
	string jeek_id , comment_text;
	cin >> jeek_id >> comment_text;
	Jeek* jeek = new Jeek();
	jeek = search_jeek(jeek_id);
	if (jeek != NULL)
	{
		Comment* new_comment;
		jeek->add_comment(new_comment , comment_text , login_user);
		User* user = new User();
		user = search_user(jeek_id);
		Notification* new_notification = new Comment_Notification();
		new_notification->add_notification(jeek_id , login_user->get_username());
		user->add_notification(new_notification);
	}
}

void Core::reply()
{
	string text_id , reply_text;
	cin >> text_id >> reply_text;
	Reaction* help = new Reaction;
	help = search_reaction(text_id);
	help->reply(reply_text , login_user , text_id);
	Notification* new_notification = new Reply_Notification();
	new_notification->add_notification(text_id , login_user->get_username());
	User* user = new User();
	user = search_user(text_id);
	user->add_notification(new_notification);
}

void Core::rejeek(string jeek_id)
{
	Jeek* jeek = new Jeek();
	jeek = search_jeek(jeek_id);
	if (jeek != NULL)
	{
		jeek->add_num_of_rejeeks();
		string text = jeek->get_text();
		login_user->rejeek(text);
		Notification* new_notification = new Rejeek_Notification;
		new_notification->add_notification(jeek_id , login_user->get_username());
		User* user = new User();
		user = search_user(jeek_id);
 		user->add_notification(new_notification);
	}
}

void Core::dislike(string jeek_id)
{
	Jeek* jeek = new Jeek();
	jeek = search_jeek(jeek_id);
	if (jeek != NULL)
	{
		jeek->dislike();
		User* user = new User();
		user = search_user(jeek_id);
		Notification* new_notification = new Dislike_Notification();
		new_notification->add_notification(jeek_id , login_user->get_username());
		user->add_notification(new_notification);
	}
}

void Core::like(string jeek_id)
{
	Jeek* jeek = new Jeek();
	jeek = search_jeek(jeek_id);
	if (jeek != NULL)
	{
		jeek->like();
		User* user = new User();
		user = search_user(jeek_id);
		Notification* new_notification = new Like_Notification();
		new_notification->add_notification(jeek_id , login_user->get_username());
		user->add_notification(new_notification);
	}
}

void Core::follow(string username)
{
	User* user = new User();
	user = find_user(username);
	if (user != NULL)
		user->add_follower(login_user);
}

void Core::unfollow(string username)
{
	User* user = new User();
	user = find_user(username);
	if (user != NULL)
		user->remove_follower(login_user);
}

User* Core::search_user(string username , string password)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_matching(username , password))
			return users[i];
	}
	return NULL;
}

string Core::search_jeeks_of_user(string username)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_username(username))
			return users[i]->show_jeeks();
	}
	return "";
}

string Core::search_jeeks_by_hash_tag(string tag)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_tags(tag) != " ")
			return users[i]->check_tags(tag);
	}
	return "";
}

Jeek* Core::search_jeek(string jeek_id)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_jeek_id(jeek_id))
			return users[i]->check_jeek_id(jeek_id);
	}
	return NULL;
}

User* Core::search_user(string jeek_id)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_jeek_id(jeek_id))
			return users[i];
	}
	return NULL;
}

User* Core::find_user(string username)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_username(username))
			return users[i];
	}
	return NULL;
}

Reaction* Core::search_reaction(string text_id)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_reaction(text_id))
			return users[i]->check_reaction(text_id);
	}
	return NULL;
}

string Core::make_session_information()
{
	int session_id;
	do
	{
		session_id = rand() % (sessions_information.size() + 2);
	}
	while (!check_session_id_duplication(to_string(session_id)));
	string id = to_string(session_id);
	Session_Information new_session_information;
	new_session_information.session_id = id;
	new_session_information.user = new User;
	new_session_information.user = login_user;
	sessions_information.push_back(new_session_information);
	return id;	
}

bool Core::check_session_id_duplication(string session_id)
{
	for (int i = 0 ; i < sessions_information.size() ; i++)
	{
		if (sessions_information[i].session_id == session_id)
			return false;
	}
	return true;
}

string Core::find_username(string session_id)
{
	for (int i = 0 ; i < sessions_information.size() ; i++)
	{
		if (sessions_information[i].session_id == session_id)
			return sessions_information[i].user->get_username();
	}
	return	"";
}

int Core::find_session_information(User* user)
{
	for (int i = 0 ; i < sessions_information.size() ; i++)
	{
		if (sessions_information[i].user == user)
			return i;
	}
	return -1;
}

void Core::logout()
{
	int index = find_session_information(login_user);
	if (index != -1)
	{
		sessions_information.erase(sessions_information.begin() + index);
		login_user = NULL;
	}
}

void Core::set_login_user(string session_id)
{
	for (int i = 0 ; i < sessions_information.size() ; i++)
	{
		if (sessions_information[i].session_id == session_id)
			login_user = sessions_information[i].user;
	}
}