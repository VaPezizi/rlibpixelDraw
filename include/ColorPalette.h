#ifndef _RLIB
#define _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"
#endif
class ColorPalette{
protected:
	raylib::Rectangle rectangle;
	raylib::Vector2 startPos;
	raylib::Vector2 size;
	float value;
	float saturation;
public:
	ColorPalette(const raylib::Vector2& startPos, const raylib::Vector2& size);
	void drawPalette();
	void drawColorRect();
	raylib::Rectangle getSquare();
	raylib::Color getColorFromPos(const Vector2& position);
	void setSaturation(const float& saturation);
	void setValue(const float& value);
	float getValue();
	float getSaturation();

};

