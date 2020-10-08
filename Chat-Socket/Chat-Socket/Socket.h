
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include <stdio.h>
#include "Ws2tcpip.h"
//#include "WinSock2.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library

WSADATA wsa;
SOCKET s;
struct sockaddr_in server;

void Socket_Server_Init(int port);
void Socket_Client_Init(char* ServerIP, int port);

int Send(char* data);
int Recv(char* buff, int size);
int SendOneByte(char data);
