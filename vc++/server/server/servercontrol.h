#include <omp.h>
#include <iostream>
#include <String.h>

#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
#pragma comment(lib, "Ws2_32.lib") 

#pragma once
class servercontrol{										//第一次玩繼承
	private:
		SOCKET *client_sockfd;					//servercontrol 會存入多個 使用者得連線資訊 user 會存入一個 自己本身的連線資料
		SOCKET server_sockfd = SOCKET_ERROR;	//伺服器的連線資料
	public:
		servercontrol(int family,char *localhost,int port,int NumberOfUsers,int *error);		//利用建構式 在一開始就將伺服器給開啟 錯誤 error 會回傳 1
		char* userlist();																		//讀取在線的使用者
		SOCKET GetServer_sockfd();																//取得連線資料
};

