#ifndef _RLIB
#define _RLIB
#include "./raylib-cpp/include/raylib-cpp.hpp"
#include <string>
#endif

#ifndef _SAVEBOX
#define _SAVEBOX
class SaveBox{
private: 
	const raylib::RenderTexture2D * target;
	raylib::Rectangle background;
	std::string text;
	std::string textBuffer;
public: 
	SaveBox(const raylib::Vector2& position, const raylib::Vector2& size, const RenderTexture2D * target);
	int DrawBox();
	int saveImage();

};
#endif
