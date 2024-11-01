#include "./raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#include <iostream>
//(The pragma export line is just so cland stops whining about it)

#define COLORS_AMOUNT 15	//If you add more colors, change this value
#define PIXEL_AMOUNT 10		//This holds the multiplier that determines the amount of pixels (Lower for less pixels)

class Pixel{
protected:
	raylib::Vector2 size;
	raylib::Vector2 position;
	raylib::Color color;
	raylib::Rectangle rectangle;
public:
	Pixel(){
		size = raylib::Vector2(0, 0);
		position = raylib::Vector2(0, 0);
		color = RAYWHITE;
		rectangle = raylib::Rectangle(0, 0, 0, 0);
	}

	Pixel(int sizeX, int sizeY, int positionX, int positionY, raylib::Color color){
		size = raylib::Vector2((float) sizeX, (float) sizeY);	
		position = raylib::Vector2((float) positionX, (float) positionY);
		this->color = color;
		rectangle = raylib::Rectangle(positionX, positionY, sizeX, sizeY);
	}
	void setPos(raylib::Vector2 pos){
		position = pos;
	}
	void setSize(raylib::Vector2 size){
		this->size = size;
	}
	void setColor(raylib::Color color){
		this->color = color;
	}
	void setRectangle(raylib::Rectangle rectangle){			//int sizeX, int sizeY, int positionX, int positionY){
		this->rectangle = rectangle;
	}
	raylib::Vector2 getPos(){
		return this->position;
	}
	raylib::Vector2 getSize(){
		return this->size;
	}
	raylib::Color getColor(){
		return this->color;
	}
	raylib::Rectangle getRectangle(){
		return this->rectangle;
	}

};


class Grid{
protected:
	raylib::Vector2 size;		//Size just means window size
	raylib::Vector2 XY;		//XY has amount of pixels per row in X, and amount of rows on Y
	int Amount;
	Pixel * tiles;	//Position of tiles
public:
	Grid(int sizeX, int sizeY){
		size = (Vector2) {(float) sizeX,(float) sizeY};
		int X = size.GetX() / PIXEL_AMOUNT;	//Amount of pixels per row
		int Y = size.GetY() / PIXEL_AMOUNT;	//Amount of rows

		XY = raylib::Vector2(X, Y);
		Amount = X * Y;			//Amount of pixels
		
		tiles = new Pixel[Amount];

		for(int i = 0;i < Y;i++){	//For all rows
			for(int j = 0;j < X;j++){	//For pixels in row
				int index = (i * X) + j;
				tiles[index].setPos(raylib::Vector2((float) j * sizeX / X, (float) i * sizeY / Y));
				tiles[index].setSize(raylib::Vector2((float) size.x / XY.x, (float)size.y / XY.y));
				tiles[index].setRectangle(raylib::Rectangle(tiles[index].getPos().GetX(), tiles[index].getPos().GetY(),size.x/XY.x, size.y / XY.y));


				//tiles[index].SetX((float)j * sizeX / X);	//I * amount of pixels per row + position in current row
				//tiles[index].SetY((float)i * sizeY / Y);

			}
		}
	}

	
	void DestroyGrid(){
		delete[] tiles;
	}
	int getAmount(){
		return Amount;
	}
	Pixel * getPixel(int index){
		return &this->tiles[index];
	}
	//For debugging !!
	void printSome(){
		for(int i = 0; i < Amount;i++){
			std::cout << "Index: " << i << " X: " << tiles[i].getPos().GetX() << " Y: " << tiles[i].getPos().GetY() << std::endl;
		}

	}

	void drawGrid(){
		for(int i = 0;i < Amount; i++){
			//DrawRectangleLines((int)tiles[i].getPos().GetX(), (int) tiles[i].getPos().GetY(), size.x / XY.x, size.y / XY.y, LIGHTGRAY);
			DrawRectangle((int)tiles[i].getPos().GetX(),(int)tiles[i].getPos().GetY(),size.x / XY.x, size.y / XY.y, tiles[i].getColor());
		}
	}
};
/*
class Game{
protected:
	raylib::Window window;

public:
	Game(raylib::Window window){
		this->window = window;
	}
	
	raylib::Window getWindow(){
		return window;
	}
	void handleInputs(){
	
	}
};*/
class ColorPalette{
protected:
	//raylib::Color lineArray[360];
	raylib::Rectangle rectangle;
	raylib::Vector2 startPos;
	raylib::Vector2 size;
	float value;
	float saturation;
public:	
	ColorPalette(raylib::Vector2 startPos, raylib::Vector2 size){
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
	raylib::Color getColorFromPos(Vector2 position){
		float posy = position.y - 10;
		return ColorFromHSV(posy, saturation, value);
	}
	void setSaturation(float saturation){
		if(saturation >= 0 && saturation <= 1){
			this->saturation = saturation;
		}
	}
	void setValue(float value){
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
/*
class ColorLine{
protected:
	raylib::Vector2 startPos;
	raylib::Vector2 endPos;
	raylib::Color color;
public:
	ColorLine(raylib::Vector2 startPos, raylib::Vector2 endPos, raylib::Color color){
		this->startPos = startPos;
		this->endPos = endPos;
		this->color = color;
	}
	void drawLine(){
		color.DrawLine(startPos, endPos);
	}
};*/


int main(){
	int screenWidth = 800;
	int screenHeight = 600;

	raylib::Vector2 mouse(GetMousePosition());

	raylib::Window window(screenWidth, screenHeight, "Raylib++ pixel draw!");
	SetTargetFPS(240);

	ColorPalette * colortPalette = new ColorPalette(raylib::Vector2(10, 10), raylib::Vector2(50, 360));

	Grid grid(screenWidth, screenHeight);
	raylib::Color currentColor = raylib::Color(RED);

	grid.printSome();		//Printing the positions of all elements
//	Vector3 testiHSV = ColorToHSV(RED);
//	std::cout << "Hue: " << testiHSV.x, " saturation: " << testiHSV.y << " value: ";

	while(!window.ShouldClose()){
	//	std::cout << "Mouse pos is: X: " << mouse.GetX() << " + Y: " << mouse.GetY() << std::endl;		
		
		//---( Updates )---
		mouse = GetMousePosition();
					
		if(IsMouseButtonDown(0)){
			//std::cout << "Painettu!" << std::endl;
			for(int i = 0; i < grid.getAmount();i++){
				//std::cout << "MORO" << std::endl;
				if(CheckCollisionPointRec(mouse, grid.getPixel(i)->getRectangle())){
			//		std::cout << "TERE" << std::endl;
					grid.getPixel(i)->setColor(raylib::Color(currentColor));	
				}
			}
		}
		if(CheckCollisionPointRec(mouse, colortPalette->getSquare())){
			if(IsMouseButtonPressed(1)){
				currentColor = colortPalette->getColorFromPos(mouse);
				std::cout << "Mouse X: " << mouse.x << " Mouse Y: " << mouse.y << " Current color: "<< currentColor << std::endl;
			}				
		}


		if(IsKeyPressed(KEY_ENTER)){
			for(int i = 0; i < grid.getAmount(); i++){
				grid.getPixel(i)->setColor(raylib::Color(RAYWHITE));
			}		
		}
		if(IsKeyPressed(KEY_UP)){
			std::cout << colortPalette -> getSaturation() << std::endl;	
			colortPalette->setSaturation(colortPalette->getSaturation() + 0.1);	
		}
		if(IsKeyPressed(KEY_DOWN)){
			std::cout << colortPalette -> getSaturation() << std::endl;	
			colortPalette->setSaturation(colortPalette->getSaturation() - 0.1);		
		}
		if(IsKeyPressed(KEY_W)){
			colortPalette->setValue(colortPalette->getValue() + 0.1);
			std::cout << colortPalette->getValue() << std::endl;	
		}
		if(IsKeyPressed(KEY_S)){
			colortPalette->setValue(colortPalette->getValue() - 0.1);
			std::cout << colortPalette->getValue() << std::endl;
		}

		//---( Drawing ) ---
		BeginDrawing();

		grid.drawGrid();
		colortPalette->drawPalette();
		//colortPalette->drawColorRect();

		window.ClearBackground(RAYWHITE);
		//DrawText("Hello World!!", 190, 200, 20, LIGHTGRAY);
		DrawFPS(10, 10);
		EndDrawing();
	}
	delete(colortPalette);
	grid.DestroyGrid();
	
	return 0;
}
