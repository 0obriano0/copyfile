#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
#pragma comment(lib, "Ws2_32.lib") 

#pragma once
class socket_support {
	private:
		SOCKET *client_sockfd;					//servercontrol �|�s�J�h�� �ϥΪ̱o�s�u��T user �|�s�J�@�� �ۤv�������s�u���
		SOCKET server_sockfd = SOCKET_ERROR;	//���A�����s�u���
};