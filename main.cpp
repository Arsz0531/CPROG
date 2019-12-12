//tillämpning
#include <SDL.h>
#include "MovableSprite.h"
#include "GameEngine.h"
#include "SelfMovingSprite.h"
using namespace std;
using namespace CPROG;

SelfMovingSprite* planetOne;
SelfMovingSprite* planetTwo;
SelfMovingSprite* planetThree;
SelfMovingSprite* planetFour;

class MyAlien : public SelfMovingSprite {
public:
	MyAlien() :SelfMovingSprite(0, 200, 100, 100, "assets/alien.png"){}
	void setMovement()
	{
		if (rect.x < 500)
			rect.x++;

		else
			rect.y++;
	}
	void tick(GameEngine* ge) 
	{
		setMovement();
		if ((rect.y + rect.h) > 600) 
		{
			ge->remove(this);
			SelfMovingSprite* newAlien = new MyAlien();
			ge->add(newAlien);
		}
		if (ge->checkCollision(rect, planetOne->getRect()))
			ge->remove(this);
		if (ge->checkCollision(rect, planetTwo->getRect()))
			ge->remove(this);
		if (ge->checkCollision(rect, planetFour->getRect()))
			ge->remove(this);

	}
};

class MyOtherAlien : public SelfMovingSprite {
public:
	MyOtherAlien() :SelfMovingSprite(300, 150, 100, 100, "assets/alien.png"){}
	void setMovement() {
		if (rect.y < 600)
			rect.y++;
	}
	void tick(GameEngine* ge) 
	{
		setMovement();
		if ((rect.y + rect.h) > 700) 
		{
			ge->remove(this);
		
		}
		if (ge->checkCollision(rect, planetOne->getRect()))
			ge->remove(this);
		if (ge->checkCollision(rect, planetTwo->getRect()))
			ge->remove(this);
		if (ge->checkCollision(rect, planetFour->getRect()))
			ge->remove(this);
	}
};

class MySpaceship : public MovableSprite {
public:
	MySpaceship() :MovableSprite(200, 230, 100, 100, "assets/spaceship.png")
	{
		
	}
	void HandleEventKeyDown(const SDL_Event& event) 
	{
		switch (event.key.keysym.sym) 
		{
		case SDLK_UP:
			rect.y -= 10; 
			if (rect.y < 0)
				rect.y += 10;
			break;
		case SDLK_DOWN:
			rect.y += 10;
			if ((rect.y + rect.h) > 600)
				rect.y -= 10;
			break;
		case SDLK_RIGHT: 
			rect.x += 10; 
			if ((rect.x + rect.w) > 800)
				rect.x -= 10;
			break;
		case SDLK_LEFT: 
			rect.x -= 10; 
			if (rect.x < 0)
				rect.x  += 10;
			break;
		}//switch
	}//HandleKeyDown

	void tick(GameEngine* ge) 
	{
		if (ge->checkCollision(rect, planetOne->getRect()))
			ge->remove(this);
		if(ge->checkCollision(rect, planetTwo->getRect()))
			ge->remove(this);
		if (ge->checkCollision(rect, planetFour->getRect()))
			ge->remove(this);
	}
};

int main(int argc, char** argv) 
{
	GameEngine ge;
	planetOne = SelfMovingSprite::getInstance(250, 0, 100, 100, "assets/planet.png");
	planetTwo = SelfMovingSprite::getInstance(350, 0, 100, 100, "assets/planet.png");
	planetFour = SelfMovingSprite::getInstance(450, 0, 100, 100, "assets/planet.png");
	SelfMovingSprite* alien = new MyAlien();
	MovableSprite* spaceship = new MySpaceship();
	SelfMovingSprite* anotherAlien = new MyOtherAlien();
	ge.add(anotherAlien);
	ge.add(alien);
	ge.add(spaceship);
	ge.add(planetOne);
	ge.add(planetTwo);
	ge.add(planetFour);
	ge.run();

	return 0;
}