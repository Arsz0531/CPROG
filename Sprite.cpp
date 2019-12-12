#include "Sprite.h"
#include "SDL_image.h"
#include "System.h"

using namespace std;
namespace CPROG {

	Sprite::Sprite(int x, int y, int w, int h,const string& filepath): rect{x,y,w,h}
	{
		makeTexture(filepath);
	}

	void Sprite::makeTexture(const string& filepath) 
	{
	
		SDL_Surface* surf = IMG_Load(filepath.c_str());
		if (surf == nullptr) {
			throw std::runtime_error("Failed to create Surface!");
		}
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		if (texture == nullptr) {
			throw std::runtime_error("Failed to create Texture!");
		}
		SDL_FreeSurface(surf);
	}
}//CPROG