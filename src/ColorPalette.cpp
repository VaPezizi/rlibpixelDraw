#ifndef _RLIB
#define _RLIB 
#include "../raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#endif

#ifndef _COLORPALETTE
#define _COLORPALETTE
class ColorPalette{	//TODO: Fix a bug, that allows selecting a color outside the bound of the color palette
protected:
	//raylib::Color lineArray[360];
	raylib::Rectangle rectangle;
	raylib::Vector2 startPos;
	raylib::Vector2 size;
	float value;
	float saturation;
public:	
	ColorPalette(const raylib::Vector2& startPos, const raylib::Vector2& size){
		this->startPos = startPos;
		this->size = size;
		this->rectangle = raylib::Rectangle(startPos, (Vector2){size.x, size.y * 6/5});
		this->value = 1.0f;
		this->saturation = 1.0f;
		/*for(int i = 0; i < 360; i++){
			lineArray[i] = raylib::Color(raylib::Vector3(i , 99, 99));
		}*/
	}
	void drawPalette(){
		//DrawRectangleGradientV(startPos.x, startPos.y, size.x, size.y * 1/5, (Color) {168, 50, 50, 255}, (Color){255, 255, 3, 255});
		//DrawRectangleGradientV(startPos.x, startPos.y + size.y * 1/5,size.x, size.y * 1/5, (Color){255,255,3,255}, (Color){0, 255, 0, 255});
		//DrawRectangleGradientV(startPos.x, startPos.y + size.y * 2/5, size.x, size.y * 1/5, (Color) {0, 255, 0, 255}, (Color){0, 255, 255, 255});
		//DrawRectangleGradientV(startPos.x, startPos.y + size.y * 3/5,size.x, size.y * 1/5, (Color){0,255,255,255}, (Color){0, 0, 255, 255});
		//DrawRectangleGradientV(startPos.x, startPos.y + size.y * 4/5,size.x, size.y * 1/5, (Color){0, 0,255,255}, (Color){255, 0, 255, 255});	
		//DrawRectangleGradientV(startPos.x, startPos.y + size.y, size.x, size.y * 1/5, (Color){255, 0,255,255}, (Color){235, 52, 52, 255});
		for(int i = 0;i < 360;i++){
			DrawLine(startPos.x, startPos.y + i, startPos.x + 20, startPos.y + i, ColorFromHSV(i, saturation, value));
		}
		
		//for(int i = 0; i < 360;i++){
		//	lineArray[i].DrawLine((Vector2) {startPos.x, startPos.y + i * 2}, (Vector2){startPos.x + size.x, startPos.y + i * 2}, size.y);	//Drawing line with a thickness
		//}	
	}
	void drawColorRect(){
		rectangle.Draw(raylib::BLACK);
	}
	raylib::Rectangle getSquare(){
		return rectangle;
	}
	raylib::Color getColorFromPos(const Vector2& position){
		float posy = position.y - 10;
		return ColorFromHSV(posy, saturation, value);
	}
	void setSaturation(const float& saturation){
		if(saturation >= 0 && saturation <= 1){
			this->saturation = saturation;
		}
	}
	void setValue(const float& value){
		if(value <= 1 && value >= 0){
			this->value = value;
		}
	}
	float getValue(){
		return this->value;
	}
	float getSaturation(){
		return this->saturation;
	}
};
#endif
