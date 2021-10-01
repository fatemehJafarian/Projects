#ifndef __MENTION_NOTIFICATION_H__
#define __MENTION_NOTIFICATION_H__

#include "notification.hpp"

using namespace std;

class Mention_Notification : public Notification
{
public:
	Mention_Notification();
	void add_notification(string id , string username);
};

#endif