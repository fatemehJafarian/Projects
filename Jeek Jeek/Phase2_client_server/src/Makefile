all:	test

test:	core.o user.o jeek.o reaction.o reply.o comment.o notification.o like_notification.o dislike_notification.o comment_notification.o reply_notification.o jeek_notification.o mention_notification.o rejeek_notification.o bad_exception.o invalid_input.o no_login_user.o duplicate_user.o
	g++ core.cpp user.cpp jeek.cpp reaction.cpp reply.cpp comment.cpp notification.cpp like_notification.cpp dislike_notification.cpp comment_notification.cpp reply_notification.cpp jeek_notification.cpp mention_notification.cpp rejeek_notification.cpp bad_exception.cpp invalid_input.cpp no_login_user.cpp duplicate_user.cpp 

core.o: core.cpp core.hpp user.hpp bad_exception.hpp invalid_input.hpp no_login_user.hpp duplicate_user.hpp
	g++ -c core.cpp

user.o:	user.cpp user.hpp jeek.hpp notification.hpp notification.hpp like_notification.hpp dislike_notification.hpp comment_notification.hpp reply_notification.hpp jeek_notification.hpp mention_notification.hpp rejeek_notification.hpp
	g++ -c user.cpp

jeek.o:	jeek.cpp jeek.hpp user.hpp reaction.hpp
	g++ -c jeek.cpp 

reaction.o: reaction.cpp reaction.hpp user.hpp
	g++ -c reaction.cpp

reply.o: reply.cpp reply.hpp reaction.hpp
	g++ -c reply.cpp

comment.o: comment.cpp comment.hpp reaction.hpp
	g++ -c comment.cpp

notification.o: notification.cpp notification.hpp
	g++ -c notification.cpp

like_notification.o: like_notification.cpp like_notification.hpp notification.hpp
	g++ -c like_notification.cpp

dislike_notification.o: dislike_notification.cpp dislike_notification.hpp notification.hpp
	g++ -c dislike_notification.cpp

comment_ntification.o: comment_notification.cpp comment_notification.hpp notification.hpp
	g++ -c comment_notification.cpp

reply_notification.o: reply_notification.cpp reply_notification.hpp notification.hpp
	g++ -c reply_notification.cpp

jeek_notification.o: jeek_notification.cpp jeek_notification.hpp notification.hpp
	g++ -c jeek_notification.cpp

mention_notification.o: mention_notification.cpp mention_notification.hpp notification.hpp
	g++ -c mention_notification.cpp

rejeek_notification.o: rejeek_notification.cpp rejeek_notification.hpp notification.hpp
	g++ -c rejeek_notification.cpp	

bad_exception.o: bad_exception.cpp bad_exception.hpp
	g++ -c bad_exception.cpp

invalid_input.o: invalid_input.cpp invalid_input.hpp bad_exception.hpp
	g++ -c invalid_input.cpp

no_login_user.o: no_login_user.cpp no_login_user.hpp bad_exception.hpp
	g++ -c no_login_user.cpp

duplicate_user.o: duplicate_user.cpp duplicate_user.hpp bad_exception.hpp
	g++ -c duplicate_user.cpp
