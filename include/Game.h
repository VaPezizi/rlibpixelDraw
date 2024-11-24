#ifndef _RLIB
#define _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"	//IWYU pragma: export
#include <string>
#endif

#ifndef _SAVEBOX
#define _SAVEBOX
#include "SaveBox.h"
#endif

#ifndef _COLORPALETTE
#define _COLORPALETTE
#include "ColorPalette.h"
#endif

#ifndef _SLIDER
#define _SLIDER
#include "Slider.h"
#endif

#define _VALUE_SLIDER 1		//These mark the type of sliders
#define _SATURATION_SLIDER 0	
#define COLORS_AMOUNT 15	//If you add more colors, change this value
#define PIXEL_AMOUNT 10		//This holds the multiplier that determines the amount of pixels (Lower for less pixels)

class Game{
private:
	int screenWidth;
	int screenHeight;

	std::string bufferName;
	bool draw;
	bool savePromt;
	int brushSize;
	int mouseWheel;

	std::string fontSizeText;
	raylib::Vector2 mouse;
	raylib::Window window;
	
	raylib::RenderTexture2D * target;
	raylib::RenderTexture2D * renderBuffer;
	
	SaveBox saver;
	ColorPalette * colorPalette;

	Slider valueSlider;
	Slider saturationSlider;
	raylib::Color currentColor;
public:

	//Constructor and destructor
	
	Game(const int& screenWidth, const int& screenHeight, const int& FPS){
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
		SetTargetFPS(FPS);
		
		this->draw = 0;
		this->savePromt = 0;

		this->brushSize = 10;
		this->mouseWheel = 0;

		this->fontSizeText = "Current brush size: ";
		fontSizeText.append(std::to_string(brushSize));

		this->mouse = GetMousePosition();
		//this->window = raylib::Window(screenWidth, screenHeight, "Raylib++ pixel draw!");
		window.Init(screenWidth, screenHeight, "Raylib++ pixel draw!");

		this->target = new raylib::RenderTexture2D();
		*target = LoadRenderTexture(screenWidth, screenHeight);
		this->renderBuffer = new raylib::RenderTexture2D(LoadRenderTexture(screenWidth, screenHeight));
		*renderBuffer = LoadRenderTexture(screenWidth, screenHeight);

		this->saver = SaveBox((Vector2){screenWidth / 2.0f - screenWidth / 10.0f, screenHeight / 2.0f - screenHeight / 10.0f}, (Vector2){screenWidth / 5.0f, screenHeight / 5.0f}, target);
		
		BeginTextureMode(*target);		//Making the texture just a white background
		ClearBackground(raylib::Color(RAYWHITE));
		EndTextureMode();

		this->colorPalette = new ColorPalette(raylib::Vector2(10, 10), raylib::Vector2(50, 360));

		this->valueSlider = Slider((Vector2){5, 100}, (Vector2){10, 400}, _VALUE_SLIDER);		//Size, Position
		this->saturationSlider = Slider((Vector2){5, 100}, (Vector2){30, 400}, _SATURATION_SLIDER);

		this->currentColor = raylib::Color(RED);
	}
	
	~Game(){
		target->Unload();
		renderBuffer->Unload();
		delete(colorPalette);
		delete(target);
		delete(renderBuffer);
		window.Close();

	}

//	GETTERS:		//I know most of these are probably useless, but whatever
	const int& getScreenWidth();
	const int& getScreenHeight();
	/*const std::string& getBufferName();
	const bool& getDrawState();
	const bool& getSavePromtState();
	const int& getBrushSize();
	const std::string& getFontSizeText();
	const raylib::Vector2& getMouse();
	const raylib::Window * getWindowPointer();
	const raylib::RenderTexture * getTarget();
	const raylib::RenderTexture2D * getRenderBuffer();
	const SaveBox& getSaver();
	const ColorPalette * getColorPalette();
	const Slider& getValueSlider();
	const Slider& getSaturationSlider;*/

//	SETTERS:
	void setBufferName(const std::string& bufferName);
	
//	GAME FUNCTIONS ( MAIN LOOP ETC )
	void runMainLoop();
	void checkUpdates();
	void drawGame();
};

