#pragma once

#include "loopRender.h"
#include "visualElements.h"




class gameLogic : public loopRender, public visualElements
{
 

public: 
	gameLogic();
	virtual void KeyPressed(int btnCode); 
	virtual void UpdateF(float deltaTime=0); 
	~gameLogic();
};

