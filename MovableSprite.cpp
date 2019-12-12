#include "MovableSprite.h"
#include "System.h"
using namespace std;

namespace CPROG {
	MovableSprite::MovableSprite(int x, int y, int w, int h, const string& filepath):Sprite(x,y,w,h,filepath)
	{
	}

	void MovableSprite::draw() const {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
	}

	MovableSprite* MovableSprite::getInstance(int x, int y, int w, int h, const string& filepath) {
		return new MovableSprite(x, y, w, h, filepath);
	}

	void MovableSprite::keyDown(const SDL_Event& event) 
	{
		HandleEventKeyDown(event);
	}
	void MovableSprite::keyUp(const SDL_Event& event) 
	{
		HandleEventKeyUp(event);
	}
	void MovableSprite::mouseDown(const SDL_Event& event) 
	{
		HandleEventMouseDown(event);
	}
	void MovableSprite::mouseUp(const SDL_Event& event) 
	{
		HandleEventMouseUp(event);
	}
MovableSprite::~MovableSprite()
	{
	}
}//CPROG


