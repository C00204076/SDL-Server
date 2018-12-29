#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <string>
#include <iostream>

//
// C00204076
// Brandon Seah-Dempsey
// Started at 13:06 13 December 2018
//
// Time taken:
// Known bugs:

enum Packet
{
	P_ChatMessage,
	P_Test
};

class Server
{
public:
	Server(int PORT, bool BroadcastPublically = false);
	bool ListenForNewConnection();

private:
	bool sendall(int ID, char * data, int totalbytes);
	bool recvall(int ID, char * data, int totalbytes);

	bool SendInt(int ID, int _int);
	bool GetInt(int ID, int & _int);

	bool SendPacketType(int ID, Packet _packettype);
	bool GetPacketType(int ID, Packet & _packettype);

	bool SendString(int ID, std::string & _string);
	bool GetString(int ID, std::string & _string);

	bool ProcessPacket(int ID, Packet _packettype);

	static void ClientHandlerThread(int ID);

private:
	SOCKET Connections[100];
	int TotalConnections = 0;

	SOCKADDR_IN addr; //Address that we will bind our listening socket to
	int addrlen = sizeof(addr);
	SOCKET sListen;
};

static Server * serverptr; //Serverptr is necessary so the static ClientHandler method can access the server instance/functions.
