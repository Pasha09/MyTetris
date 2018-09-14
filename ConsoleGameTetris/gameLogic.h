#pragma once

#include "loopRender.h"
#include "visualElements.h"
#include "cube.h"
#include "stick.h"
#include "tStick.h"
#include "lStick.h"



class gameLogic : public loopRender, public visualElements
{
private:
	Figure* figureDef;
	Figure* tempFigure;

	//loop methods
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime = 0);

	bool guard(int direction); 
	bool guardRotate(); 
	void nextFigure(Figure** pointer); 
	void tempToFigure(); 
	void checkGameOver();
	
	//delete line
	void guardLine(); 
	void dropLine(int level, int size);
	inline int findLevelWhereDrop(int level, int size);

	inline int findMin(std::vector<int>valueY); 
	

public: 
	gameLogic();
	~gameLogic();
};

