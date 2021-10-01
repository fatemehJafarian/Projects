CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build

all: $(BUILD_DIR) server.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/interface.o: server/interface.cpp server/interface.hpp server/server.hpp src/core.o src/user.o src/jeek.o src/reaction.o src/reply.o src/comment.o src/notification.o src/like_notification.o src/dislike_notification.o src/comment_notification.o src/reply_notification.o src/jeek_notification.o
	$(CC) $(CF) -c server/interface.cpp -o $(BUILD_DIR)/interface.o

$(BUILD_DIR)/server_main.o: server/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/interface.hpp src/core.hpp
	$(CC) $(CF) -c server/main.cpp -o $(BUILD_DIR)/server_main.o

server.out: $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/interface.o src/core.o src/user.o src/jeek.o src/reaction.o src/reply.o src/comment.o src/notification.o src/like_notification.o src/dislike_notification.o src/comment_notification.o src/reply_notification.o src/jeek_notification.o src/mention_notification.o src/rejeek_notification.o src/bad_exception.o src/invalid_input.o src/no_login_user.o src/duplicate_user.o $(BUILD_DIR)/server_main.o
	$(CC) $(CF) $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/interface.o src/core.o src/user.o src/jeek.o src/reaction.o src/reply.o src/comment.o src/notification.o src/like_notification.o src/dislike_notification.o src/comment_notification.o src/reply_notification.o src/jeek_notification.o src/mention_notification.o src/rejeek_notification.o src/bad_exception.o src/invalid_input.o src/no_login_user.o src/duplicate_user.o $(BUILD_DIR)/server_main.o -o server.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null
