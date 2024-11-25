#ifndef _GAME
#define _GAME
#include "Game.h"
#endif
#ifndef _IOSTREAM
#define _IOSTREAM
#include <iostream>
#endif



void Game::checkUpdates(){
	
	this->mouse = GetMousePosition();		
	mouseWheel = GetMouseWheelMove();

	if(IsMouseButtonDown(0)){
			
		draw = !(valueSlider.checkSlider(&mouse, colorPalette) || saturationSlider.checkSlider(&mouse, colorPalette));
		//draw=saturationSlider.checkSlider(&mouse, colortPalette);
		//std::cout << "Painettu!" << std::endl;
	//	for(int i = 0; i < grid.getAmount();i++){	//NOTE: This code needs to be changed, as the drawing method has been completely changed
		//std::cout << "Draw: " << draw << std::endl;	//std::cout << "MORO" << std::endl;
		if(draw){
	//		std::cout << "TERE" << std::endl;
			//grid.getPixel(i)->setColor(raylib::Color(currentColor));
			//std::cout << "Pos X: "<< mouse.x << " , Pos Y: " << mouse.y << std::endl;	
			BeginTextureMode(*target);
			std::cout << "Moro Samuli!" << std::endl;
			DrawCircle(mouse.x, mouse.y, brushSize, currentColor);
			EndTextureMode();

		}
		
	}
	if(CheckCollisionPointRec(mouse, colorPalette->getSquare())){
		if(IsMouseButtonPressed(1)){
			currentColor = colorPalette->getColorFromPos(mouse);
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

}
void Game::drawGame(){
	BeginDrawing();
		
	DrawTextureRec(target->texture, (Rectangle){0, 0, (float)target->texture.width, (float) -target->texture.height}, (Vector2){0, 0}, WHITE);	
	DrawText(fontSizeText.c_str(), screenWidth * 0.7, screenHeight * 0.05, 20, BLACK);	//TODO: Change adding the number to the string, to where brush size is updated	
	colorPalette->drawPalette();												//Right now it's slow
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


void Game::runMainLoop(){
	while(!window.ShouldClose()){
		checkUpdates();
		drawGame();		
	}
}

