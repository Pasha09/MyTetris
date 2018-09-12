#pragma once

#include "consoleIO.h"

#define widthSize 24
#define heightSize 22
#define borderRightofAreaForFallingFigure 16


class visualElements : virtual public consoleIO
{
public:
	visualElements();
	void paint(); 
	void erase(); 
	~visualElements();
};

