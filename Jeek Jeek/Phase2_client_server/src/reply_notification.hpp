#ifndef __REPLY_NOTIFICATION_H__
#define __REPLY_NOTIFICATION_H__

#include "notification.hpp"

using namespace std;

class Reply_Notification : public Notification
{
public:
	Reply_Notification() {}
	void add_notification(string text_id , string username);
};

#endif