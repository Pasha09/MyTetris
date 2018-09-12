#pragma once


class Figure
{
protected: 
	int mPositionXYPoints[8];
public:
	friend class gameLogic;
	virtual void createFigure() = 0; 
	virtual void startFigure() = 0;
	virtual ~Figure();
};

