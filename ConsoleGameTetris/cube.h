#pragma once
#include "Figure.h"

class cube : public Figure
{
private: 
	int x, y; //position for the first point 
public:
	cube();
	virtual void createFigure();
	virtual void startFigure(); 
	~cube();
};

