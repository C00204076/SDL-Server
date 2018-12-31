//
// C00204076
// Brandon Seah-Dempsey
// Started at
// Finished at
// Time taken:
// Known bugs:

#include "Player.h"

#include <SDL.h>

class Game;

class Other
{
public:
	Other(int w, int h, int x, int y, int r, int g, int b, int a);

	void draw(SDL_Renderer *renderer);
	void pollEvents();
	void intersectsWith(Player other);

	int getWidth();
	int getHeight();
	int getX();
	int getY();

private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
};

#include "Game.h"