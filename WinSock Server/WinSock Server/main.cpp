//
// C00204076
// Brandon Seah-Dempsey
// Started at 13:06 13 December 2018
// Finished at
// Time taken:
// Known bugs:

#include "Server.h"

int main()
{
	Server MyServer(1111); //Create server on port 100
	for (int i = 0; i < 100; i++) //Up to 100 times...
	{
		MyServer.ListenForNewConnection(); //Accept new connection (if someones trying to connect)
	}
	system("pause");
	return 0;
}