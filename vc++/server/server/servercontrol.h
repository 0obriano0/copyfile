#include "MyForm.h"
#include "socket_support.h"

#pragma once
class servercontrol : public socket_support{										//�Ĥ@�����~��
	private:
	public:
		servercontrol(char *localhost,int port,int NumberOfUsers,bool *error);		//�Q�Ϋغc�� �b�@�}�l�N�N���A�����}�� ���~ error �|�^�� 1
		char* userlist();															//Ū���b�u���ϥΪ�
};

