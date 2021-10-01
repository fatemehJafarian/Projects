#ifndef __COMMENT_NOTIFICATION_H__
#define __COMMENT_NOTIFICATION_H__

#include "notification.hpp"

using namespace std;

class Comment_Notification : public Notification
{
public:
	Comment_Notification();
	void add_notification(string text_id , string username);
};

#endif