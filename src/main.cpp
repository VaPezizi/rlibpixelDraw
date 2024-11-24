#ifndef _RLIB
#define _RLIB
#include "../raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
//#include "./raylib-cpp/include/raylib-cpp.hpp"	// IWYU pragma: export
#endif

#ifndef _GAME
#define _GAME
#include "Game.h"
#endif

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

int main(){
	Game game = Game(800, 600, 240);
	game.runMainLoop();
	
	return 0;
}
