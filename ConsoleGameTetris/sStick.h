#pragma once
#include "Figure.h"

#define horizontal 0
#define vertical 1

class sStick : public Figure
{
protected:
	int x, y; //position for the first point 
	char mPosition;
public:
	sStick();
	virtual void createFigure();
	virtual void startFigure();
	virtual std::vector<int> conflictBorder(int direction);
	virtual std::vector<int> conflictBorderRotate();
	void rotate();
	~sStick();

	//for convenience read conflictBorder
	inline void plusX(std::vector<int>& informationAboutPoints, int i);
	inline void plusY(std::vector<int>& informationAboutPoints, int i);
	inline void minusX(std::vector<int>& informationAboutPoints, int i);
	inline void minusY(std::vector<int>& informationAboutPoints, int i);
};

