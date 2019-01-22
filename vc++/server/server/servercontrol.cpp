#include "servercontrol.h"

servercontrol::servercontrol(int family,char *localhost, int port, int NumberOfUsers, int *error){
	int server_len;
	struct sockaddr_in server_address;
	*error = 1;

	WSADATA wsadata;
	if (WSAStartup(0x101, (LPWSADATA)&wsadata) != 0) {
		printf("Winsock Error\n");
		*error = 0;
		server_sockfd = SOCKET_ERROR;
		return ;
	}

	// 產生 server socket
	server_sockfd = socket(family, SOCK_STREAM, 0);										
	if (server_sockfd == SOCKET_ERROR) {
		printf("Socket Error\n");
		*error = 0;
		server_sockfd = SOCKET_ERROR;
		return ;
	}

	int a = inet_pton(family, localhost, &server_address.sin_addr);		// AF_INET(使用IPv4); SOCK_STREAM; 0(使用預設通訊協定，即TCP)
	server_address.sin_port = port; //設定埠號
	server_len = sizeof(server_address);

	if (bind(server_sockfd, (struct sockaddr *)&server_address, server_len) < 0) {
		printf("Bind Error\n");
		*error = 0;
		server_sockfd = SOCKET_ERROR;
		return ;
	}

	if (listen(server_sockfd, 5) < 0) {
		printf("Listen Error\n");
		*error = 0;
		server_sockfd = SOCKET_ERROR;
		return ;
	}
}

char* servercontrol::userlist() {
	return NULL;
}

SOCKET servercontrol::GetServer_sockfd() {
		return server_sockfd;
}