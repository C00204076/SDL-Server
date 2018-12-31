//
// C00204076
// Brandon Seah-Dempsey
// Started at
// Finished at
// Time taken:
// Known bugs:

#include "Player.h"
//
Player::Player(int w, int h, int x, int y, int r, int g, int b, int a) :
	_w(w),
	_h(h),
	_x(x),
	_y(y),
	_r(r),
	_g(g),
	_b(b),
	_a(a)
{

}

//
void Player::pollEvents()
{
	SDL_Event _event;

	if (SDL_PollEvent(&_event))
	{
		if (_event.type == SDL_KEYDOWN)
		{
			switch (_event.key.keysym.sym)
			{
			case SDLK_LEFT:
				_x -= 10;
				break;
			case SDLK_RIGHT:
				_x += 10;
				break;
			case SDLK_UP:
				_y -= 10;
				break;
			case SDLK_DOWN:
				_y += 10;
				break;
			}
		}
	}
}

//
void Player::draw(SDL_Renderer *renderer)
{
	SDL_Rect rect;

	rect.w = _w;
	rect.h = _h;
	rect.x = _x;
	rect.y = _y;

	SDL_SetRenderDrawColor(renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(renderer, &rect);
}

//
void Player::intersectsWith(Other other)
{
	if (_x + _w < other->getX() ||
		_y + _h < other->getY() ||
		_x > other->getX() + other->getWidth() ||
		_y > other->getY() + other->getHeight())
	{
		_r = 255;
		_b = 0;
	}

	else
	{
		_r = 0;
		_b = 255;
	}
}

//
int Player::getWidth()
{
	return _w;
}

//
int Player::getHeight()
{
	return _h;
}

//
int Player::getX()
{
	return _x;
}

//
int Player::getY() 
{
	return _y;
}