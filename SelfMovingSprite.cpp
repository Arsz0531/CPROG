#include "SelfMovingSprite.h"
#include "System.h"
#include "GameEngine.h"
using namespace std;

namespace CPROG {

	SelfMovingSprite::SelfMovingSprite(int x, int y, int w, int h, const string& filepath):Sprite(x,y,w,h,filepath)
	{
	}
	void SelfMovingSprite::draw() const
	{
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
	}
	
	SelfMovingSprite* SelfMovingSprite::getInstance(int x, int y, int w, int h, const string& filepath)
	{
		return new SelfMovingSprite(x, y, w, h, filepath);
	}
	
	void SelfMovingSprite::setMovement()
	{
	//default movement
		if (rect.y < 600)
			rect.y++;
	}
	void SelfMovingSprite::tick(GameEngine* ge)
	{
		//default tick
		setMovement();
		if ((rect.y + rect.h) > 700)
			ge->remove(this);
	}
	SelfMovingSprite::~SelfMovingSprite()
	{
	}
}//CPROG