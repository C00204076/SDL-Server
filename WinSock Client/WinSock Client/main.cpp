//
// C00204076
// Brandon Seah-Dempsey
// Started at
// Finished at
// Time taken:
// Known bugs:

#include "Client.h"
#include "Game.h"

Game *game = nullptr;

int main(int argc, const char * argv[])
{
	game = new Game();

	game->init("SDL Server", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

	Client myClient("127.0.0.1", 1111); //Create client to localhost ("127.0.0.1") on port 1111

	if (!myClient.Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
		system("pause");
		return 1;
	}


	std::string userinput; //holds the user's chat message
	while (true)
	{
		std::getline(std::cin, userinput); //Get line if user presses enter and fill the buffer

		while (game->running())
		{
			game->handleEvents();
			game->update();
			game->render();
		}


		if (!myClient.SendString(userinput)) //Send string: userinput, If string fails to send... (Connection issue)
			break; //If send string failed (if connection was closed), leave this loop since we have lost connection to the server
		Sleep(10);
	}



	system("pause");
	game->clean();

	return 0;
}