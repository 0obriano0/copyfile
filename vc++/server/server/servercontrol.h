#include "MyForm.h"
#include "socket_support.h"

#pragma once
class servercontrol : public socket_support{										//第一次玩繼承
	private:
	public:
		servercontrol(char *localhost,int port,int NumberOfUsers,bool *error);		//利用建構式 在一開始就將伺服器給開啟 錯誤 error 會回傳 1
		char* userlist();															//讀取在線的使用者
};

