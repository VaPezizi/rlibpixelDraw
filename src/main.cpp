#ifndef _RLIB
#define _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#endif
#include "../raylib-cpp/include/RenderTexture.hpp"
#include <iostream>
#include <string>

#ifndef _SAVEBOX
#define _SAVEBOX 
#include "SaveBox.h"
#endif
#ifndef _COLORPALETTE
#include "ColorPalette.h"
#define _COLORPALETTE
#endif 
#ifndef _SLIDER
#define _SLIDER 
#include "Slider.h"
#endif
//(The pragma export line is just so cland stops whining about it)

#define _VALUE 1
#define _SATURATION 0
#define COLORS_AMOUNT 15	//If you add more colors, change this value
#define PIXEL_AMOUNT 10		//This holds the multiplier that determines the amount of pixels (Lower for less pixels)

int main(){
	const int screenWidth = 800;
	const int screenHeight = 600;
	//const int screenWidth = 1280;
	//const int screenHeight = 1024;

	std::string bufferName = "";

	bool draw = 0;
	bool savePromt = 0;

	int brushSize = 10;
	int mouseWheel = 0;

	std::string fontSizeText =  "Current brush size: ";
	fontSizeText.append(std::to_string(brushSize));

	raylib::Vector2 mouse(GetMousePosition());

	raylib::Window window(screenWidth, screenHeight, "Raylib++ pixel draw!");
	SetTargetFPS(240);

	raylib::RenderTexture2D * target = new raylib::RenderTexture2D();	//Allocating memory for the texture
	*target = LoadRenderTexture(screenWidth, screenHeight);
	
	raylib::RenderTexture2D * renderBuffer = new raylib::RenderTexture2D();
	*renderBuffer = LoadRenderTexture(screenWidth, screenHeight);

	//Making the saver box here:
	SaveBox saver((Vector2){screenWidth / 2.0f - screenWidth / 10.0f, screenHeight / 2.0f - screenHeight / 10.0f}, (Vector2){screenWidth / 5.0f, screenHeight / 5.0f}, target);

	//Clearing texture
	BeginTextureMode(*target);
	ClearBackground(raylib::Color(RAYWHITE));
	EndTextureMode();


	//Just setting up some objects required for the program
	ColorPalette * colortPalette = new ColorPalette(raylib::Vector2(10, 10), raylib::Vector2(50, 360));
	Slider valueSlider = Slider((Vector2){5, 100}, (Vector2){10, 400}, _VALUE);		//Size, Position
	Slider saturationSlider = Slider((Vector2){5, 100}, (Vector2){30, 400}, _SATURATION);
	
	//Grid grid(screenWidth, screenHeight, target);
	raylib::Color currentColor = raylib::Color(RED);

	//grid.printSome();		//Printing the positions of all elements
//	Vector3 testiHSV = ColorToHSV(RED);
//	std::cout << "Hue: " << testiHSV.x, " saturation: " << testiHSV.y << " value: ";

	while(!window.ShouldClose()){
	//	std::cout << "Mouse pos is: X: " << mouse.GetX() << " + Y: " << mouse.GetY() << std::endl;		
		
		//---( Updates )---
		mouse = GetMousePosition();		
		mouseWheel = GetMouseWheelMove();

		if(IsMouseButtonPressed(0)){
			//*renderBuffer = *target;
			std::cout << "MORO" << std::endl;
		}

		if(IsMouseButtonDown(0)){
				
			draw = !(valueSlider.checkSlider(&mouse, colortPalette) || saturationSlider.checkSlider(&mouse, colortPalette));
			//draw=saturationSlider.checkSlider(&mouse, colortPalette);
			//std::cout << "Painettu!" << std::endl;
		//	for(int i = 0; i < grid.getAmount();i++){	//NOTE: This code needs to be changed, as the drawing method has been completely changed
			//std::cout << "Draw: " << draw << std::endl;	//std::cout << "MORO" << std::endl;
			if(draw){
		//		std::cout << "TERE" << std::endl;
				//grid.getPixel(i)->setColor(raylib::Color(currentColor));
				//std::cout << "Pos X: "<< mouse.x << " , Pos Y: " << mouse.y << std::endl;	
				BeginTextureMode(*target);
				DrawCircle(mouse.x, mouse.y, brushSize, currentColor);
				EndTextureMode();

			}
			
		}
		if(CheckCollisionPointRec(mouse, colortPalette->getSquare())){
			if(IsMouseButtonPressed(1)){
				currentColor = colortPalette->getColorFromPos(mouse);
				std::cout << "Mouse X: " << mouse.x << " Mouse Y: " << mouse.y << " Current color: "<< currentColor << std::endl;
			}				
		}
		
		if(mouseWheel != 0){
			if(!(brushSize == 1 && mouseWheel == -1)){
				brushSize = brushSize + mouseWheel;	
				fontSizeText = "Current brush size: ";
				fontSizeText.append(std::to_string(brushSize));
			}
		}
			
		if((IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) && IsKeyDown(KEY_S)){		//This makes the save promt appear
			savePromt = 1;	
		}
		/*if(IsKeyPressed(KEY_Z)){		//TODO: Make this work
			*target = RenderTexture(*renderBuffer);	
			//target->texture = renderBuffer->texture;
			std::cout << "MORO2" << std::endl;
		}*/

		//Place for some testing prints, that need to run every frame:
		//std::cout << "Slider position function: " << valueSlider.getSliderPos() << std::endl;

		//---( Drawing ) ---
		BeginDrawing();
		
		DrawTextureRec(target->texture, (Rectangle){0, 0, (float)target->texture.width, (float) -target->texture.height}, (Vector2){0, 0}, WHITE);	
		DrawText(fontSizeText.c_str(), screenWidth * 0.7, screenHeight * 0.05, 20, BLACK);	//TODO: Change adding the number to the string, to where brush size is updated	
		colortPalette->drawPalette();												//Right now it's slow
		valueSlider.drawSlider();
		saturationSlider.drawSlider();
		//slider.drawHitbox();
		if(savePromt){
			savePromt = saver.DrawBox();
		}
		window.ClearBackground(RAYWHITE);
		//DrawText("Hello World!!", 190, 200, 20, LIGHTGRAY);
		DrawFPS(10, 10);
		EndDrawing();
	}
	target->Unload();
	renderBuffer->Unload();
	//target = NULL;
	delete(colortPalette);
	delete(target);
	delete(renderBuffer);
	window.Close();
//	grid.DestroyGrid();
	
	return 0;
}
