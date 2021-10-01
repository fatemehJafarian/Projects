#include "reply_notification.hpp"

void Reply_Notification::add_notification(string text_id , string username)
{
	this->username = username;
	text = username + " replied " + text_id;
}