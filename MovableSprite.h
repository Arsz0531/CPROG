#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H
#include "Sprite.h"

namespace CPROG {
	class MovableSprite : public Sprite
	{
	public:
		static MovableSprite* getInstance(int x, int y, int w, int h, const std::string& filepath);
		void draw() const;
		void keyDown(const SDL_Event& event);
		void keyUp(const SDL_Event& event);
		void mouseDown(const SDL_Event& event);
		void mouseUp(const SDL_Event& event);
		virtual void HandleEventKeyDown(const SDL_Event& event){}
		virtual void HandleEventKeyUp(const SDL_Event& event) {}
		virtual void HandleEventMouseDown(const SDL_Event& event) {}
		virtual void HandleEventMouseUp(const SDL_Event& event) {}
		~MovableSprite();
	protected:
		MovableSprite(int x, int y, int w, int h, const std::string& filepath);
	};
}//CPROG
#endif

