#pragma once

#include "consoleIO.h"

#define widthSize 24
#define heightSize 22
#define borderRightofAreaForFallingFigure 16


class visualElements : virtual public consoleIO
{
public:
	visualElements();
	void paint(Figure *obj); 
	void erase(Figure *obj);
	~visualElements();
};

