#pragma once
#include "Figure.h"

#define vertical 0
#define horizontal 1

class stick : public Figure
{
private:
	int x, y; //position for the first point 
	char mPosition; 
public:
	stick();
	virtual void createFigure();
	virtual std::vector<int> conflictBorder(int direction);
	virtual std::vector<int> conflictBorderRotate(int side);
	virtual std::vector<int> getY();
	virtual void startFigure();
	virtual void rotate(); 
	~stick();
};

