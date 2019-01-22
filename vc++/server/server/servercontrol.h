#include <omp.h>
#include <iostream>
#include <String.h>

#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
#pragma comment(lib, "Ws2_32.lib") 

#pragma once
class servercontrol{										//�Ĥ@�����~��
	private:
		SOCKET *client_sockfd;					//servercontrol �|�s�J�h�� �ϥΪ̱o�s�u��T user �|�s�J�@�� �ۤv�������s�u���
		SOCKET server_sockfd = SOCKET_ERROR;	//���A�����s�u���
	public:
		servercontrol(int family,char *localhost,int port,int NumberOfUsers,int *error);		//�Q�Ϋغc�� �b�@�}�l�N�N���A�����}�� ���~ error �|�^�� 1
		char* userlist();																		//Ū���b�u���ϥΪ�
		SOCKET GetServer_sockfd();																//���o�s�u���
};

