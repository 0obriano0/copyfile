#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
#pragma comment(lib, "Ws2_32.lib") 

#pragma once
class socket_support {
	private:
		SOCKET *client_sockfd;					//servercontrol 會存入多個 使用者得連線資訊 user 會存入一個 自己本身的連線資料
		SOCKET server_sockfd = SOCKET_ERROR;	//伺服器的連線資料
};