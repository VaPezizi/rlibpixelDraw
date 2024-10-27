#include "./raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#include <iostream>
//(The pragma export line is just so cland stops whining about it)

class Grid{
protected:
	raylib::Vector2 size;
	raylib::Vector2 * tiles;
	int Amount;
public:
	Grid(int sizeX, int sizeY){
		size = (Vector2) {(float) sizeX,(float) sizeY};
		int X = size.GetX() / 10;
		int Y = size.GetY() / 10;

		Amount = sizeX / 10 * sizeY / 10;
		tiles = new raylib::Vector2[Amount];

		for(int i = 0;i < X;i++){
			for(int j = 0;j < Y;j++){
				tiles[(j * Y)+j].SetX(X * i);
				tiles[(j * Y)+j].SetY(Y*j);

			}
		}
	}
	void drawGrid(){
		for(int i = 0;i < Amount; i++){
			DrawRectangleLines((int)tiles[i].GetX(), (int) tiles[i].GetY(), 10, 10, GRAY);
		}
	}
	void DestroyGrid(){
		delete[] tiles;
	}
	int getAmount(){
		return Amount;
	}
	
};

int main(){
	int screenWidth = 800;
	int screenHeight = 600;

	raylib::Vector2 mouse(GetMousePosition());

	raylib::Window window(screenWidth, screenHeight, "Raylib++ pixel draw!");
	SetTargetFPS(60);
	
	Grid grid(screenWidth, screenHeight);

	while(!window.ShouldClose()){
		std::cout << "Mouse pos is: X: " << mouse.GetX() << " + Y: " << mouse.GetY() << std::endl;		
		mouse = GetMousePosition();
				
		
		//---( Drawing ) ---
		BeginDrawing();
		grid.drawGrid();

		window.ClearBackground(RAYWHITE);

		DrawText("Hello World!!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}
	grid.DestroyGrid();
	
	return 0;
}
