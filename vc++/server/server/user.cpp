#include "user.h"

user::user(){
	int client_len;
	struct sockaddr_in client_address;

	client_len = sizeof(client_address);
	*client_sockfd = accept(*server_sockfd, (struct sockaddr *)&client_address, &client_len);
}

user::~user(){

}