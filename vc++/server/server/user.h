#include "servercontrol.h"

#pragma once
class user {
	private:
		SOCKET *client_sockfd;
		SOCKET *server_sockfd;
	public:
		user();					//�غc��
		~user();				//�ѫغc��
};

