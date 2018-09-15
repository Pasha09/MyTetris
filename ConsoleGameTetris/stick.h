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
	virtual std::vector<int> conflictBorderRotate();
	virtual void startFigure();
	virtual void rotate(); 
	~stick();

	//for convenience read conflictBorder
	inline void plusX(std::vector<int>& informationAboutPoints, int i);
	inline void plusY(std::vector<int>& informationAboutPoints, int i);
	inline void minusX(std::vector<int>& informationAboutPoints, int i);
	inline void minusY(std::vector<int>& informationAboutPoints, int i);
};

