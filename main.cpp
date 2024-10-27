#include "./raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#include <iostream>
//(The pragma export line is just so cland stops whining about it)

const int PIXEL_AMOUNT = 50;		//This holds the multiplier that determines the amount of pixels

class Grid{
protected:
	raylib::Vector2 size;
	raylib::Vector2 XY;
	raylib::Vector2 * tiles;
	int Amount;
public:
	Grid(int sizeX, int sizeY){
		size = (Vector2) {(float) sizeX,(float) sizeY};
		int X = size.GetX() / PIXEL_AMOUNT;	//Amount of pixels per row
		int Y = size.GetY() / PIXEL_AMOUNT;	//Amount of rows

		XY = raylib::Vector2(X, Y);

		Amount = X * Y;			//Amount of pixels
		tiles = new raylib::Vector2[Amount];

		for(int i = 0;i < Y;i++){	//For all rows
			for(int j = 0;j < X;j++){	//For pixels in row
				tiles[(i * X) + j].SetX((float)j * sizeX / X);	//I * amount of pixels per row + position in current row
				tiles[(i * X) + j].SetY((float)i * sizeY / Y);

			}
		}
	}
	void drawGrid(){
		for(int i = 0;i < Amount; i++){
			DrawRectangleLines((int)tiles[i].GetX(), (int) tiles[i].GetY(), size.x / XY.x, size.y / XY.y, GRAY);
		}
	}
	void DestroyGrid(){
		delete[] tiles;
	}
	int getAmount(){
		return Amount;
	}

	//For debugging !!
	void printSome(){
		for(int i = 0; i < Amount;i++){
			std::cout << "Index: " << i << " X: " << tiles[i].GetX() << " Y: " << tiles[i].GetY() << std::endl;
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

		window.ClearBackground(RAYWHITE);

		//DrawText("Hello World!!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}
	grid.DestroyGrid();
	
	return 0;
}
