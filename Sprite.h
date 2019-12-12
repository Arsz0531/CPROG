#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <string>

namespace CPROG {
	class GameEngine;
	class Sprite
	{
	public:
		virtual void mouseDown(const SDL_Event& event){}
		virtual void mouseUp(const SDL_Event& event) {}
		virtual void keyDown(const SDL_Event& event) {}
		virtual void keyUp(const SDL_Event& event) {}
		virtual void tick(GameEngine* ge){}
		virtual SDL_Rect getRect() const { return rect; }
		virtual ~Sprite() { SDL_DestroyTexture(texture); }
		virtual void draw() const = 0;
		void makeTexture(const std::string& filepath);
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;

	protected:
		Sprite(int x, int y, int w, int h,const std::string& filepath);
		SDL_Texture* getTexture() const { return texture; }
		SDL_Rect rect;
	private:
		SDL_Texture* texture = nullptr;
		
	};
}//CPROG
#endif

