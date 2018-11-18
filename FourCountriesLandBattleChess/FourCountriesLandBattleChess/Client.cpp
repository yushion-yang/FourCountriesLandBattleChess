
#include "ClientManager.h"
#include "Mediator.h"

ClientManager::ClientManager(Mediator *mediator1)
{
	mediator = mediator1;
	mediator->SetClient(this);

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in sockaddr;

	sockaddr.sin_family = PF_INET;
	sockaddr.sin_addr.S_un.S_addr = inet_addr("112.74.162.122");
	sockaddr.sin_port = htons(8080);
	
	//while (connect(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	//{
	////	system("cls");
	//}
}

ClientManager::~ClientManager()
{
	closesocket(s);
	WSACleanup();
}

void ClientManager::Update()
{

}
