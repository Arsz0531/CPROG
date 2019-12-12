#ifndef SelfMovingSprite_H
#define SelfMovingSprite_H
#include "Sprite.h"
#include "GameEngine.h"
//ToDo animate if time 
namespace CPROG {
	class SelfMovingSprite : public Sprite
	{
	public:
		static SelfMovingSprite* getInstance(int x, int y, int w, int h, const std::string& filepath);
		void draw() const;
		virtual void setMovement();
		virtual void tick(GameEngine* ge);
		~SelfMovingSprite();
	protected:
		SelfMovingSprite(int x, int y, int w, int h, const std::string& filepath);
	private:
	};
}//CPROG
#endif

