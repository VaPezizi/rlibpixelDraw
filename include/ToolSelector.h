#ifndef _RLIB
#define _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"
#endif

class ToolSelector{
private:
	raylib::Vector2 position;

	raylib::Rectangle mainRectangle;
	raylib::Texture2D pencilTexture;
	raylib::Texture2D brushTexture;
	raylib::Texture2D rubberTexture;

public: 
	ToolSelector(const raylib::Vector2& position){
		this->position = position;
		this->mainRectangle = raylib::Rectangle(position, (Vector2) {30, 30});

	}
	void Draw();

};
