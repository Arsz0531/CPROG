#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"

namespace CPROG {
	class GameEngine
	{
	public:
		GameEngine();
		bool checkCollision(SDL_Rect a, SDL_Rect b);
		void add(Sprite*);
		void remove(Sprite*);
		void run();
		~GameEngine();
	private:
		std::vector<Sprite*> sprites;
		std::vector<Sprite*> added, removed;
	
	};
}//CPROG
#endif

