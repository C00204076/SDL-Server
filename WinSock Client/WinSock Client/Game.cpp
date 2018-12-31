//
// C00204076
// Brandon Seah-Dempsey
// Started at
// Finished at
// Time taken:
// Known bugs:

#include "Game.h"

//
Game::Game()
{
	m_player = new Player(15, 15, 20, 300, 0, 0, 255, 255);
}

//
Game::~Game()
{

}

//
void Game::init(const char* title, int xpos, int ypos, int width, int height)
{
	int flags = 0;

	//
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}

	//
	else
	{
		isRunning = false;
	}
}

//
void Game::handleEvents()
{
	SDL_Event event_;
	SDL_PollEvent(&event_);
	switch (event_.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

//
void Game::update()
{
	m_player->pollEvents();
}

//
void Game::render()
{
	SDL_RenderClear(renderer);

	// Drawing occurs here
	m_player->draw(renderer);

	//

	SDL_RenderPresent(renderer);
}

//
void Game::clean()
{
	SDL_DestroyWindow(window);
	//SDL_DestoryRenderer(renderer);
	SDL_Quit();
	std::cout << "Game clened!" << std::endl;
}