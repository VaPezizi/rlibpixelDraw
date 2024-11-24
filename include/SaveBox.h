#ifndef _RLIB
#define _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"
#include <string>
#endif

class SaveBox{
private: 
	raylib::RenderTexture2D * target;
	raylib::Rectangle background;
	std::string text;
	std::string textBuffer;
public:
       	SaveBox();	
	SaveBox(const raylib::Vector2& position, const raylib::Vector2& size, raylib::RenderTexture2D * target);
	int DrawBox();
	int saveImage();

};
