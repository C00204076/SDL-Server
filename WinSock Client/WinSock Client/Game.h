//
// C00204076
// Brandon Seah-Dempsey
// Started at
// Finished at
// Time taken:
// Known bugs:

#include "Player.h"
#include "Other.h"

#include <stdio.h>
#include <iostream>

#include <SDL.h>

class Player;
class Other;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

	Player * m_player;
	Other * m_other;
};
