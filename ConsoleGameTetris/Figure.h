#pragma once
#include "vector"


#define downMove 1
#define leftMove 2
#define rightMove 3


class Figure
{
protected: 
	int mPositionXYPoints[8];
public:
	friend class visualElements;

	virtual void createFigure() = 0; 
	virtual void startFigure() = 0;
	virtual std::vector<int> conflictBorder(int direction) = 0;  
	virtual std::vector<int> getY()=0; 
	virtual ~Figure();

	void down(); 
	void left(); 
	void right(); 
	const int* getPositionXYPoints();
};

