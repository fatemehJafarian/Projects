#ifndef __DISLIKE_NOTIFICATION_H__
#define __DISLIKE_NOTIFICATION_H__

#include "notification.hpp"

using namespace std;

class Dislike_Notification : public Notification
{
public:
	Dislike_Notification();
	void add_notification(string jeek_id , string username);
};

#endif 