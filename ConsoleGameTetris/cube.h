#pragma once
#include "Figure.h"

class cube : public Figure
{
private: 
	int x, y; //position for the first point 
public:
	cube();
	virtual void createFigure();
	virtual std::vector<int> conflictBorder(int direction);
	virtual std::vector<int> conflictBorderRotate(int side);
	virtual std::vector<int> getY(); 
	virtual void startFigure(); 
	virtual void rotate(); 
	~cube();
};

