#ifndef _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"
#define _RLIB
#endif

#ifndef _COLORPALETTE
#include "ColorPalette.h"
#define _COLORPALETTE
#endif

class Slider{
protected: 
	bool type;
	raylib::Vector2 size;
	raylib::Vector2 position;
	float value;
	raylib::Rectangle hitbox;
	raylib::Rectangle slider;
	raylib::Rectangle movingPart;
public:
	Slider(const raylib::Vector2& size, const raylib::Vector2& position, const bool& type);
	void drawSlider();
	void updateSlider(raylib::Vector2& mousepos);
	void fixMovingPartPos(const float& pos);
	float getSliderPos();
	raylib::Rectangle& getMovingPartPos();
	raylib::Rectangle& getHitbox();
	bool checkSlider(raylib::Vector2 * mousepos, ColorPalette * colorPalette);
	void drawHitbox();

};
