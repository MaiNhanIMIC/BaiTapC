#include "Socket.h"
#include <stdio.h>
char resp[128] = { 0 };
WINAPI sockThread(LPVOID arg)
{
	char buff[128] = { 0 };
	SOCKET *tempSock = arg;
	while (1)
	{
		recv(tempSock, buff, sizeof(buff), 0);
		printf("[data]: %s\r\n", buff);
	}
	
	closesocket(*tempSock);
}


void main()
{
	Socket_Server_Init(1234);

	listen(s, 10);

	while (1)
	{
		SOCKET *tempSock = malloc(sizeof(SOCKET));
		*tempSock = accept(s, NULL, NULL);
		CreateThread(NULL, 512, sockThread, tempSock, NULL, NULL);
	}
}