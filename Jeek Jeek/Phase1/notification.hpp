#ifndef __NOTIFICATION_H__
#define __NOTIFICATION_H__

#include <iostream>

using namespace std;

class Notification
{
public:
	Notification();
	virtual void add_notification(string id , string username) {}
	void show();
protected:
	string username;
	string text;
};

#endif