#include "Socket.h"


void Socket_Server_Init(int port)
{
	printf("Initialising Winsock... \r\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : %d \r\n", WSAGetLastError());
	}

	printf(" Initialised.\r\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	else
	{
		printf(" Socket created.\r\n");

		server.sin_addr.s_addr = htonl(INADDR_ANY);
		server.sin_family = AF_INET;
		server.sin_port = htons(port);

		bind(s, (struct sockaddr*) & server, sizeof(struct sockaddr));
	}
}

void Socket_Client_Init(char* ServerIP, int port)
{
	printf("Initialising Winsock...\r\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : %d\r\n", WSAGetLastError());
	}
	else
	{
		printf(" Initialised.\r\n");

		//Create a socket
		if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		{
			printf("Could not create socket : %d\r\n", WSAGetLastError());
		}
		else
		{
			printf(" Socket created.\r\n");

			server.sin_addr.s_addr = inet_addr(ServerIP);

			server.sin_family = AF_INET;
			server.sin_port = htons(port);

			//Connect to remote server
			if (connect(s, (struct sockaddr*) & server, sizeof(server)) < 0)
			{
				printf("connect error\r\n");
			}
			printf("Connected\r\n");
		}
	}
}

int Send(char* data)
{
	int size = 0;
	while (data[size++] != '\0');
	return send(s, data, size - 1, 0);
}

int Recv(char* buff, int size)
{
	return recv(s, buff, size, 0);
}

int SendOneByte(char data)
{
	return send(s, &data, 1, 0);
}