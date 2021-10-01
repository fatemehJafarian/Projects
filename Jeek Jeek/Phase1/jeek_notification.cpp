#include "jeek_notification.hpp"

Jeek_Notification::Jeek_Notification()
{
	
}

void Jeek_Notification::add_notification(string id , string username)
{
	this->username = username;
	text = username + " jeeked " + id;
}