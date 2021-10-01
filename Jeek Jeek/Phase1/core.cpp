#include "core.hpp"

Core::Core()
{
	login_user = new User();
	login_user = NULL;
}

void Core::get_and_execute_command()
{
	while(true)
	{
		try
		{
			string command;
			cin >> command;
			if (command == "signup")
			{
				string username , display_name , password;
				cin >> username >> display_name >> password;
				signup(username , display_name , password);
			}
			else if (command == "login")
			{
				string username , password;
				cin >> username >> password;
				login(username , password);
			}
			else if (command == "logout")
			{
				login_user = NULL;
			}
			else if (command == "search")
			{
				search();
			}
			else if (command == "showJeek")
			{
				string jeek_id;
				cin >> jeek_id;
				show_jeek(jeek_id);
			}
			else if (command == "showComment")
			{
				show_comment();
			}
			else if (command == "showReply")
			{
				show_reply();
			}
			else
			{
				try
				{
					if (login_user == NULL)
						throw No_Login_User();
					if (command == "jeek")
					{
						jeek();
					}
					else if (command == "comment")
					{
						comment();
					}
					else if (command == "reply")
					{
						reply();
					}
					else if (command == "rejeek")
					{
						rejeek();
					}
					else if (command == "dislike")
					{
						dislike();
					}
					else if (command == "like")
					{
						like();
					}
					else if (command == "follow")
					{
						follow();
					}
					else if (command == "unfollow")
					{
						unfollow();
					}
					else if (command == "notifications")
					{
						login_user->show_notifications();
					}
					else 
					{
						throw Invalid_Input();
					}
				}
				catch (No_Login_User exception)
				{
					exception.what_exception();
					cin.sync();
				}
			}
		}
		catch (Invalid_Input exception)
		{
			exception.what_exception();
			cin.sync();
		}
	}
}

void Core::signup(string username , string display_name , string password)
{
	User* new_user = new User(username , display_name , password);	
	try
	{
		if (!new_user->check_duplication(users))
			users.push_back(new_user);
		else
			throw Duplicate_User();
	}
	catch (Duplicate_User exception)
	{
		exception.what_exception();
	}
}

bool Core::login(string username , string password)
{
	if(login_user = search_user(username , password))
		return true;
	return false;
}

void Core::search()
{
	string string_to_search;
	cin >> string_to_search;
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
}

void Core::show_jeek(string jeek_id)
{
	Jeek* jeek = new Jeek();
	jeek = search_jeek(jeek_id);
	if (jeek != NULL)
	{
		User* user = new User();
		user = search_user(jeek_id);
		if (user != NULL)
			jeek->show_jeek(user->get_display_name());
	}
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

void Core::jeek()
{
	if (login_user->add_jeek())
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

void Core::rejeek()
{
	string jeek_id;
	cin >> jeek_id;
	Jeek* jeek = new Jeek();
	jeek = search_jeek(jeek_id);
	if (jeek != NULL)
	{
		jeek->add_num_of_rejeeks();
		string text = jeek->get_text();
		login_user->rejeek(text);
		Notification* new_notification = new Rejeek_Notification();
		new_notification->add_notification(jeek_id , login_user->get_username());
		User* user = new User();
		user = search_user(jeek_id);
 		user->add_notification(new_notification);
	}
}

void Core::dislike()
{
	string jeek_id;
	cin >> jeek_id;
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

void Core::like()
{
	string jeek_id;
	cin >> jeek_id;
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

void Core::follow()
{
	string username;
	cin >> username;
	User* user = new User();
	user = find_user(username);
	if (user != NULL)
		user->add_follower(login_user);
}

void Core::unfollow()
{
	string username;
	cin >> username;
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

void Core::search_jeeks_of_user(string username)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		if (users[i]->check_username(username))
			users[i]->show_jeeks();
	}
}

void Core::search_jeeks_by_hash_tag(string tag)
{
	for (int i = 0 ; i < users.size() ; i++)
	{
		users[i]->check_tags(tag);
	}
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