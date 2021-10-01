#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "server.hpp"
#include "../src/core.hpp"

using namespace std;

class Interface
{
public:
	Interface(int port);
	void run();
	static Core* core;
private:
	Server server;
};

class LoginHandler : public RequestHandler 
{
public:
  Response *callback(Request *req) {
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    if (Interface::core->login(username , password))
    {	
        Response *res = new Response;
        res = Response::redirect("/loginHome");
        res->setSessionId(Interface::core->make_session_information());
    	return res;
    }
    else
    {
    	return Response::redirect("/invalidLogin_page");
    }
  }
};

class SignupHandler : public RequestHandler
{
public:
  Response *callback(Request *req) 
  {
    string username = req->getBodyParam("username");
    string displayName = req->getBodyParam("displayName");
    string password = req->getBodyParam("password");
    if (Interface::core->signup(username , displayName , password))
    	return Response::redirect("/login_page");
    else
    	return Response::redirect("/invalidSignup_page");
	}
};	

class LoginHomeHandler : public RequestHandler
{
public:
	Response *callback(Request *req)
	{
		Response *res = new Response;
        string sessionId = req->getSessionId();
        Interface::core->set_login_user(sessionId);
        string username = Interface::core->find_username(sessionId);
    	res->setHeader("Content-Type", "text/html");
    	string body;
    	body += "<!DOCTYPE html>";
        body += "<font face=\"courier\">";
    	body += "<html>";
        body += "<head style=\"text-align: center;\">";
        body += "<title>AP HTTP</title>";
        body += "<div style=\"background-color: #708090; padding: 1%; border-radius: 3px; margin: auto; \">";
        body += "<h1>JeekJeek</h1>";   
        body += "</div style=\"background-color: #DCDCDC; padding: 1%; max-width: 300px; border-radius: 3px; margin: auto; \">";
        body += "<h3>Hi ";
        body += username;
        body += "!</h3></div>";
        body += "</head><br/><br/>";
    	body += "<body style=\"text-align: center; background-color: #E0E0E0;\">";
        body += "<form action=\"/search\" method=\"post\">";
        body += "<input name=\"search\" type=\"text\" placeholder=\"Search...\" style=\"display:inline-block; width:400; height:96;\" />";
    	body += "<input type=\"image\" src=\"/search_image\" style=\"alt=\"submit\" width=\"12\" height=\"12\" \" />";
        body += "<br/><br/></form>";
        body += Interface::core->search_jeeks_of_user(username);
        body += "<div style=\"text-align: center; background-color: #708090; padding: 1%; width: 100px; border-radius: 3px; margin: auto; border: 3px; \">";
        body += "<a href=\"/jeek_page\">Jeek<a>";
        body += "</div><br/><div style=\"text-align: center; background-color: #708090; padding: 1%; width: 100px; border-radius: 3px; margin: auto; border: 3px; \">";
        body += "<a href=\"/logout\">Logout</a>";
        body += "</div></body></font>";
    	body += "</html>";
    	res->setBody(body);
    	return res;	
	}
};

class JeekDetailsHandler : public RequestHandler
{
public:
    Response *callback(Request *req)
    {
        Response *res = new Response;
        string sessionId = req->getSessionId();
        string jeekId = req->getBodyParam("details");
        Interface::core->set_login_user(sessionId);
        string username = Interface::core->find_username(sessionId);
        res->setHeader("Content-Type", "text/html");
        string body;
        body += "<!DOCTYPE html>";
        body += "<font face=\"courier\">";
        body += "<html>";
        body += "<head style=\"text-align: center;\">";
        body += "<title>AP HTTP</title>";
        body += "<div style=\"background-color: #708090; padding: 1%; border-radius: 3px; margin: auto; \">";
        body += "<h1>JeekJeek</h1>";
        body += "</div><div style=\"background-color: #DCDCDC; padding: 1%; max-width: 300px; border-radius: 3px; margin: auto; \">";
        body += "<h3>Hi ";
        body += username;
        body += "!</h3></div>";
        body += "</head><br/><br/>";
        body += "<body style=\"text-align: center; background-color: #E0E0E0;\">";
        body += Interface::core->show_jeek(jeekId);
        body += "<div style=\"text-align: center; background-color: #708090; padding: 1%; width: 100px; border-radius: 3px; margin: auto; border: 3px; \">";
        body += "<a href=\"/logout\">Logout</a>";
        body += "</div></body></font>";
        body += "</html>";
        res->setBody(body);
        return res; 
    }
};

class LogoutHandler : public RequestHandler
{
public:
    Response *callback(Request *req)
    {
        Response *res = new Response;
        res = Response::redirect("/login_page");
        Interface::core->logout();
        res->setSessionId("");
        return res; 
    }
};

class SearchHandler : public RequestHandler
{
public:
    Response *callback(Request *req)
    {
        string search = req->getBodyParam("search");
        Response *res = new Response;
        string sessionId = req->getSessionId();
        Interface::core->set_login_user(sessionId);
        string username = Interface::core->find_username(sessionId);
        res->setHeader("Content-Type", "text/html");
        string body;
        body += "<!DOCTYPE html>";
        body += "<font face=\"courier\">";
        body += "<html>";
        body += "<head style=\"text-align: center;\">";
        body += "<title>AP HTTP</title>";
        body += "<div style=\"background-color: #708090; padding: 1%; border-radius: 3px; margin: auto; \">";
        body += "<h1>JeekJeek</h1>";
        body += "</div style=\"background-color: #DCDCDC; padding: 1%; max-width: 300px; border-radius: 3px; margin: auto; \">";
        body += "<h3>Hi ";
        body += username;
        body += "!</h3></div>";
        body += "</head><br/><br/>";
        body += "<body style=\"text-align: center; background-color: #E0E0E0;\">";
        body += Interface::core->search(search);
        body += "<br/><div style=\"text-align: center; background-color: #708090; padding: 1%; width: 100px; border-radius: 3px; margin: auto; border: 3px; \">";
        body += "<a href=\"/logout\">Logout</a></div>";
        body += "</body></font>";
        body += "</html>";
        res->setBody(body);
        return res; 
    }
};

class JeekHandler : public RequestHandler
{
public:
    Response *callback(Request *req)
    {
        string sessionId = req->getSessionId();
        Interface::core->set_login_user(sessionId);
        string text = req->getBodyParam("text");
        string mention = req->getBodyParam("mention");
        string tag = req->getBodyParam("tag");
        string command = req->getBodyParam("command");
        Interface::core->jeek(text , tag , mention , command);
        return Response::redirect("/loginHome");
    }
};

class RejeekHandler : public RequestHandler
{
public:
    Response *callback(Request *req)
    {
        string sessionId = req->getSessionId();
        string jeekId = req->getBodyParam("button");
        Interface::core->set_login_user(sessionId);
        Interface::core->rejeek(jeekId);
        return Response::redirect("/loginHome");
    }
};

class LikeHandler : public RequestHandler
{
public:
    Response *callback(Request *req)
    {
        string sessionId = req->getSessionId();
        string jeekId = req->getBodyParam("button");
        Interface::core->set_login_user(sessionId);
        Interface::core->like(jeekId);
        return Response::redirect("/loginHome");
    }
};

class DislikeHandler : public RequestHandler
{
public:
    Response *callback(Request *req)
    {
        string sessionId = req->getSessionId();
        string jeekId = req->getBodyParam("button");
        Interface::core->set_login_user(sessionId);
        Interface::core->dislike(jeekId);
        return Response::redirect("/loginHome");
    }
};


#endif