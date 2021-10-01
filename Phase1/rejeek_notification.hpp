#ifndef __REJEEK_NOTIFICATION_H__
#define __REJEEK_NOTIFICATION_H__

#include "notification.hpp"

using namespace std;

class Rejeek_Notification : public Notification
{
public:
	Rejeek_Notification();
	void add_notification(string jeek_id , string username);
};

#endif