#pragma once

#include "consoleIO.h"

#define widthSize 23
#define heightSize 22
#define borderRightofAreaForFallingFigure 15


class visualElements : virtual public consoleIO
{
public:
	visualElements();
	void paint(Figure *obj); 
	void erase(Figure *obj);
	void clearField(); 
	void deleteLine(int level); 
    void copyPasta(int level, int &levelDrop);
	~visualElements();
};

