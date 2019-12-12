#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
using namespace std;
#define FPS 60

namespace CPROG {
	GameEngine::GameEngine()
	{
	}

	void GameEngine::add(Sprite* s) 
	{
		added.push_back(s);
	}
	void GameEngine::remove(Sprite* s) 
	{
		removed.push_back(s);
	}
	
	bool GameEngine::checkCollision(SDL_Rect a, SDL_Rect b)
	{
		//The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		//Calculate the sides of rect A
		leftA = a.x;
		rightA = a.x + a.w;
		topA = a.y;
		bottomA = a.y + a.h;

		//Calculate the sides of rect B
		leftB = b.x;
		rightB = b.x + b.w;
		topB = b.y;
		bottomB = b.y + b.h;

		//If any of the sides from A are outside of B
		if (bottomA <= topB)
			return false;
		
		if (topA >= bottomB)
			return false;
	
		if (rightA <= leftB)
			return false;

		if (leftA >= rightB)
			return false;

		//If none of the sides from A are outside B
		return true;
	}

	void GameEngine::run() 
	{
		//gameloop
		const int tickInterval = 1000 / FPS;
		bool quit = false;

		while (!quit) 
		{
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;
			while (SDL_PollEvent(&event)) 
			{
				switch (event.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					for (Sprite* s : sprites)
						s->mouseDown(event);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Sprite* s : sprites)
						s->mouseUp(event);
					break;

				case SDL_KEYDOWN:
					for (Sprite* s : sprites)
						s->keyDown(event);
					break;

				case SDL_KEYUP:
					for (Sprite* s : sprites)
						s->keyUp(event);
					break;

				}//switch
			}//inner loop
			
			for (Sprite* s : added)
				sprites.push_back(s);
			added.clear();

			for (Sprite* s : removed) 
			{
				for (vector<Sprite*>::iterator i = sprites.begin();
					i != sprites.end();)
					if (*i == s) {
						i = sprites.erase(i);
						delete s;
					}//if
					else
						i++;
			}//outer for
			removed.clear();
			SDL_RenderClear(sys.getRen());
			
			for (Sprite* s : sprites) 
			{
				s->tick(this);
				s->draw();
			}

			SDL_RenderPresent(sys.getRen());
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);

		}//outer loop
	}//run
	GameEngine::~GameEngine()
	{
		for (Sprite* s : sprites)
			delete s;
	}
}//CPROG