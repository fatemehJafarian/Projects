#ifndef _JEEK_NOTIFICATION_H__
#define _JEEK_NOTIFICATION_H__

#include "notification.hpp"

using namespace std;

class Jeek_Notification : public Notification
{
public:
	Jeek_Notification();
	void add_notification(string jeek_id , string username);
};

#endif