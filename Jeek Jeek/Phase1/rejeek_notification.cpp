#include "rejeek_notification.hpp"

Rejeek_Notification::Rejeek_Notification()
{
	
}

void Rejeek_Notification::add_notification(string jeek_id , string username)
{
	this->username = username;
	text = username + " rejeeked " + jeek_id;
}