#ifndef __LIKE_NOTIFICATIONS_H__
#define __LIKE_NOTIFICATIONS_H__

#include "notification.hpp"

using namespace std;

class Like_Notification : public Notification
{
public:
	Like_Notification() {}
	void add_notification(string id , string username);
};

#endif