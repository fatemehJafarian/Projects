#include "comment_notification.hpp"

Comment_Notification::Comment_Notification()
{
	
}

void Comment_Notification::add_notification(string jeek_id , string username)
{
	this->username = username;
	text = username + " commented on " + jeek_id;
}