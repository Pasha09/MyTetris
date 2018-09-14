#pragma once
#include "Figure.h"

//mainDot is center stick which protrude
#define mainDotUp 0
#define mainDotRight 1
#define mainDotDown 2
#define mainDotLeft 3

class jStick : public Figure
{
private:
	int x, y; //position for the first point 
	char mPosition;
public:
	jStick();
	virtual void createFigure();
	virtual std::vector<int> conflictBorder(int direction);
	virtual std::vector<int> conflictBorderRotate();
	virtual void startFigure();
	virtual void rotate();
	~jStick();

	//for convenience read conflictBorder
	inline void plusX(std::vector<int>& informationAboutPoints, int i);
	inline void plusY(std::vector<int>& informationAboutPoints, int i);
	inline void minusX(std::vector<int>& informationAboutPoints, int i);
	inline void minusY(std::vector<int>& informationAboutPoints, int i);
};

