#ifndef _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#define _RLIB
#endif
#include "SaveBox.h"
/*
class SaveBox{
private:
	const RenderTexture2D * target;
	raylib::Rectangle background;
	std::string text;
	std::string textBuffer;
public: 
	SaveBox(const raylib::Vector2& position, const raylib::Vector2& size, const RenderTexture2D * target){
		this->background = raylib::Rectangle(position, size);
		this->text = "Enter filename: ";
		this->textBuffer = "";
		this->target = target;
	}
	int DrawBox(){
		
		//DrawRectangle(screenWidth / 2 - screenWidth / 10, screenHeight / 2, 250, 60, RAYWHITE);
		background.Draw(RAYWHITE);
		background.DrawLines(BLACK);
		//DrawRectangleLines(screenWidth / 2 - screenWidth / 10, screenHeight / 2, 250, 60, BLACK);
		raylib::Vector2 pos = background.GetPosition();
		raylib::Vector2 size = background.GetSize();
		DrawText(text.c_str(), pos.GetX() + 2, pos.GetY() + size.y / 10, 10, BLACK);//screenWidth / 2 - screenWidth / 10 + 5, screenHeight / 2, 10, BLACK);
		DrawText(textBuffer.c_str(), pos.GetX() + 2, pos.GetY() + size.y / 5, 10, BLACK);
		
		char key = GetCharPressed();
		if(IsKeyPressed(KEY_BACKSPACE))textBuffer.pop_back();
		
		//std::cout << key << std::endl;
		if((key >= 32))textBuffer += key;	
		
		if(IsKeyPressed(KEY_ENTER)){
			return this->saveImage();
		}
		return 1;
	}
	int saveImage(){	
		Image image = LoadImageFromTexture(target->texture);
		ImageFlipVertical(&image);
		textBuffer.append(".png");
		ExportImage(image, textBuffer.c_str());
		this->textBuffer = "";	
		return 0;	
	}

};
*/
SaveBox::SaveBox(){}

SaveBox::SaveBox(const raylib::Vector2& position, const raylib::Vector2& size, raylib::RenderTexture2D * target){
	this->background = raylib::Rectangle(position, size);
	this->text = "Enter filename: ";
	this->textBuffer = "";
	this->target = target;
}
int SaveBox::DrawBox(){
	
	//DrawRectangle(screenWidth / 2 - screenWidth / 10, screenHeight / 2, 250, 60, RAYWHITE);
	background.Draw(RAYWHITE);
	background.DrawLines(BLACK);
	//DrawRectangleLines(screenWidth / 2 - screenWidth / 10, screenHeight / 2, 250, 60, BLACK);
	raylib::Vector2 pos = background.GetPosition();
	raylib::Vector2 size = background.GetSize();
	DrawText(text.c_str(), pos.GetX() + 2, pos.GetY() + size.y / 10, 10, BLACK);//screenWidth / 2 - screenWidth / 10 + 5, screenHeight / 2, 10, BLACK);
	DrawText(textBuffer.c_str(), pos.GetX() + 2, pos.GetY() + size.y / 5, 10, BLACK);
	
	char key = GetCharPressed();
	if(IsKeyPressed(KEY_BACKSPACE))textBuffer.pop_back();
	
	//std::cout << key << std::endl;
	if((key >= 32))textBuffer += key;	
	
	if(IsKeyPressed(KEY_ENTER)){
		return this->saveImage();
	}
	return 1;
}
int SaveBox::saveImage(){	
	Image image = LoadImageFromTexture(target->texture);
	ImageFlipVertical(&image);
	textBuffer.append(".png");
	ExportImage(image, textBuffer.c_str());
	this->textBuffer = "";	
	return 0;	
}

