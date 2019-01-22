#include "servercontrol.h"

#pragma once
class user {
	private:
		SOCKET *client_sockfd;
		SOCKET *server_sockfd;
	public:
		user();					//建構式
		~user();				//解建構式
};

