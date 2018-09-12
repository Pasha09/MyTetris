#pragma once

#include "loopRender.h"
#include "visualElements.h"
#include "cube.h"


#define _AFXDLL 100


class gameLogic : public loopRender, public visualElements
{
private:
	Figure* figureDef;
	Figure* tempFigure;

	//loop methods
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime = 0);

	void nextFigure(Figure** pointer); 
	void tempToFigure(); 

public: 
	gameLogic();
	~gameLogic();
};

