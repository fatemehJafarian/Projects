#include "mention_notification.hpp"

Mention_Notification::Mention_Notification()
{
	
}

void Mention_Notification::add_notification(string id , string username)
{
	this->username = username;
	text = username + " mentioned you in " + id; 
}