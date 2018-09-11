#pragma once

#include "loopRender.h"


class gameLogic : public loopRender
{
public: 
	gameLogic();
	virtual void KeyPressed(int btnCode); 
	virtual void UpdateF(float deltaTime=0); 
	~gameLogic();
};

