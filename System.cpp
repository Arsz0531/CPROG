#include "System.h"
#include <SDL.h>
#include <iostream>
using namespace std;

namespace CPROG {

	System::System()
	{
		if (SDL_Init(SDL_INIT_VIDEO) == -1) {
			cerr << "SDL_Init-fel:" << SDL_GetError() << endl;
			exit(-1);
		}
		win = SDL_CreateWindow("CPROG", 100, 100, 800, 600, 0);
		if (win == nullptr) {
			cerr << "Error: " << SDL_GetError() << endl;
			SDL_Quit();
			exit(-1);
		}
		ren = SDL_CreateRenderer(win, -1, 0);
		if (ren == nullptr) {
			cerr << "Fel: " << SDL_GetError() << endl;
			SDL_DestroyWindow(win);
			SDL_Quit();
			exit(-1);
		}
	
	}//constructor

	SDL_Renderer* System::getRen() const
	{
		return ren;	
	}

	System::~System()
	{
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	System sys;
}//CPROG
