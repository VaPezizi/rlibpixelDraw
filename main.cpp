#include "./raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#include <iostream>
//(The pragma export line is just so cland stops whining about it)

const int PIXEL_AMOUNT = 50;		//This holds the multiplier that determines the amount of pixels

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

int main(){
	int screenWidth = 800;
	int screenHeight = 600;

	raylib::Vector2 mouse(GetMousePosition());

	raylib::Window window(screenWidth, screenHeight, "Raylib++ pixel draw!");
	SetTargetFPS(60);
	
	Grid grid(screenWidth, screenHeight);

	grid.printSome();		//Printing the positions of all elements

	while(!window.ShouldClose()){
	//	std::cout << "Mouse pos is: X: " << mouse.GetX() << " + Y: " << mouse.GetY() << std::endl;		
		mouse = GetMousePosition();
				
		
		//---( Drawing ) ---
		BeginDrawing();
		grid.drawGrid();

		if(IsMouseButtonDown(0)){
			std::cout << "Painettu!" << std::endl;
			for(int i = 0; i < grid.getAmount();i++){
				//std::cout << "MORO" << std::endl;
				if(CheckCollisionPointRec(mouse, grid.getPixel(i)->getRectangle())){
					std::cout << "TERE" << std::endl;
					grid.getPixel(i)->setColor(raylib::Color(RED));	
				}
			}
		}
		if(IsKeyPressed(KEY_ENTER)){
			for(int i = 0; i < grid.getAmount(); i++){
				grid.getPixel(i)->setColor(raylib::Color(RAYWHITE));
			}		
		}


		window.ClearBackground(RAYWHITE);
		//DrawText("Hello World!!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}
	grid.DestroyGrid();
	
	return 0;
}
