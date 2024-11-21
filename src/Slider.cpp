#ifndef _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#include <raylib.h>
#define _RLIB
#endif

#ifndef _COLORPALETTE
#define _COLORPALETTE
#include "ColorPalette.h"
#endif

#ifndef _SLIDER
#define _SLIDER
#include "Slider.h"
/*class Slider{
protected:
	bool type;
	raylib::Vector2 size;
	raylib::Vector2 position;
	float value;
	raylib::Rectangle hitbox;
	raylib::Rectangle slider;
	raylib::Rectangle movingPart;

public:
	Slider(const raylib::Vector2& size, const raylib::Vector2& position, const bool& type){	//
		this->type = type;
		this->size = size;
		this->position = position;
		this->value = 0.5;
		this->slider = raylib::Rectangle(position, size);
		this->movingPart = raylib::Rectangle((Vector2){position.x - size.x, position.y + size.y / 2}, (Vector2){size.x * 3, size.y / 20});
		this->hitbox = raylib::Rectangle((Vector2){position.x - size.x * 1.1f, position.y}, (Vector2){size.x * 3.3f, size.y});
	}
	void drawSlider(){
		this->slider.Draw(raylib::BLACK);
		this->movingPart.Draw(raylib::LIGHTGRAY);
	}
	void updateSlider(raylib::Vector2& mousepos){
		float temp = getSliderPos();
		//if(CheckCollisionPointRec(mousepos, this->movingPart) && this->movingPart.GetY() >= this->slider.GetY()){
		if(temp > 0 && temp < 1){
			this->movingPart.SetY(mousepos.y - movingPart.GetHeight() / 2);
		}else if(temp < 0)this->fixMovingPartPos(0.0001);
		else this->fixMovingPartPos(0.9999);	
	}

	//Takes a number between 0 and 1 and fixes the sliders position based on that
	void fixMovingPartPos(const float& pos){
		this->movingPart.SetY(pos * size.y + position.y);

	}
	float getSliderPos(){		//(DONE):	Return a value between 0.0 - 1.0f based on the position of the slidin part
		return - (position.y - this->movingPart.y) / size.y;
	}
	raylib::Rectangle& getMovingPartPos(){
		return this->movingPart;
	}
	raylib::Rectangle& getHitbox(){
		return this->hitbox;
	}
	bool checkSlider(raylib::Vector2 * mousepos, ColorPalette * colortPalette){
		if(CheckCollisionPointRec(*mousepos, this->getHitbox())){
			       	this->updateSlider(*mousepos);
				if(this->type)colortPalette->setValue(this->getSliderPos());	//1 = _VALUE
				else colortPalette->setSaturation(this->getSliderPos());
				return 1;
		}else{
			return 0;
		}
	}

	//For testing
	void drawHitbox(){
		this->hitbox.Draw(RED);
	}
};
*/

Slider::Slider(const raylib::Vector2& size, const raylib::Vector2& position, const bool& type){	//
	this->type = type;
	this->size = size;
	this->position = position;
	this->value = 0.5;
	this->slider = raylib::Rectangle(position, size);
	this->movingPart = raylib::Rectangle((Vector2){position.x - size.x, position.y + size.y / 2}, (Vector2){size.x * 3, size.y / 20});
	this->hitbox = raylib::Rectangle((Vector2){position.x - size.x * 1.1f, position.y}, (Vector2){size.x * 3.3f, size.y});
}
void Slider::drawSlider(){
	this->slider.Draw(raylib::BLACK);
	this->movingPart.Draw(raylib::LIGHTGRAY);
}
void Slider::updateSlider(raylib::Vector2& mousepos){
	float temp = getSliderPos();
	//if(CheckCollisionPointRec(mousepos, this->movingPart) && this->movingPart.GetY() >= this->slider.GetY()){
	if(temp > 0 && temp < 1){
		this->movingPart.SetY(mousepos.y - movingPart.GetHeight() / 2);
	}else if(temp < 0)this->fixMovingPartPos(0.0001);
	else this->fixMovingPartPos(0.9999);	
}

//Takes a number between 0 and 1 and fixes the sliders position based on that
void Slider::fixMovingPartPos(const float& pos){
	this->movingPart.SetY(pos * size.y + position.y);

}
float Slider::getSliderPos(){		//(DONE):	Return a value between 0.0 - 1.0f based on the position of the slidin part
	return - (position.y - this->movingPart.y) / size.y;
}
raylib::Rectangle& Slider::getMovingPartPos(){
	return this->movingPart;
}
raylib::Rectangle& Slider::getHitbox(){
	return this->hitbox;
}
bool Slider::checkSlider(raylib::Vector2 * mousepos, ColorPalette * colortPalette){
	if(CheckCollisionPointRec(*mousepos, this->getHitbox())){
			this->updateSlider(*mousepos);
			if(this->type)colortPalette->setValue(this->getSliderPos());	//1 = _VALUE
			else colortPalette->setSaturation(this->getSliderPos());
			return 1;
	}else{
		return 0;
	}
}

//For testing
void Slider::drawHitbox(){
	this->hitbox.Draw(RED);
}

#endif
