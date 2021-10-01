#include "dislike_notification.hpp"

Dislike_Notification::Dislike_Notification()
{
	
}

void Dislike_Notification::add_notification(string jeek_id , string username)
{
	this->username = username;
	text = username + " disliked " + jeek_id;
}