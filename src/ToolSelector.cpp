#ifndef _TOOLSELECTOR
#include "ToolSelector.h"
#define _TOOLSELECTOR
#endif


#include <raylib.h>

#ifndef _RLIB
#define _RLIB

#include "../raylib-cpp/include/raylib-cpp.hpp"
#endif

void ToolSelector::Draw(){
	this->mainRectangle.DrawRounded(0.5f, 1, raylib::BLACK);
	//DrawRectangleRoundedLinesEx(this->mainRectangle, 0.5f, 50, 1, raylib::BLACK);	
}

