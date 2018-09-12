#pragma once


class Figure
{
protected: 
	int mPositionXYPoints[8];
public:
	friend class visualElements;
	virtual void createFigure() = 0; 
	virtual void startFigure() = 0;
	virtual ~Figure();
	void down(); 
	void left(); 
	void right(); 
};

