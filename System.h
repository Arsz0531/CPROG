#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>

namespace CPROG {
	class System
	{
	public:
		System();
		~System();
		SDL_Renderer* getRen() const;
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
	};

	extern System sys;
}//CPROG

#endif
