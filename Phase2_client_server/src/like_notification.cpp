#include "like_notification.hpp"

void Like_Notification::add_notification(string jeek_id , string username)
{
	this->username = username;
	text = username + " liked " + jeek_id;
}