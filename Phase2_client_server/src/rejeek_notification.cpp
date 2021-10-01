#include "rejeek_notification.hpp"

void Rejeek_Notification::add_notification(string jeek_id , string username)
{
	this->username = username;
	text = username + " rejeeked " + jeek_id;
}