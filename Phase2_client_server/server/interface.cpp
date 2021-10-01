#include "interface.hpp"

Core* Interface::core = new Core();
Interface::Interface(int port) : server(port)
{
	server.get("/head_image" , new ShowImage("static/5.gif"));
	server.get("/home" , new ShowPage("static/home.html"));
	server.get("/login_page" , new ShowPage("static/login.html"));
	server.post("/login" , new LoginHandler());
	server.get("/" , new ShowPage("static/home.html"));
	server.get("/invalidLogin_page" , new ShowPage("static/invalidLogin.html"));
	server.post("/invalidLogin" , new LoginHandler());
	server.get("/signup_page" , new ShowPage("static/signup.html"));
	server.post("/signup" , new SignupHandler());
	server.get("/invalidSignup_page" , new ShowPage("static/invalidSignup.html"));
	server.post("/invalidSignup" , new SignupHandler());
	server.get("/loginHome" , new LoginHomeHandler());
	server.post("/jeekDetails" , new JeekDetailsHandler());
	server.get("/logout" , new LogoutHandler());
	server.post("/search" , new SearchHandler());
	server.get("/search_image" , new ShowImage("static/search.png"));
	server.get("/jeek_page" , new ShowPage("static/jeek.html"));
	server.post("/jeek" , new JeekHandler());
	server.post("/rejeek" , new RejeekHandler());
	server.get("/like_image" , new ShowImage("static/like.png"));
	server.get("/dislike_image" , new ShowImage("static/dislike.png"));
	server.post("/like" , new LikeHandler());
	server.post("/dislike" , new DislikeHandler());
}

void Interface::run()
{
	server.run();
}