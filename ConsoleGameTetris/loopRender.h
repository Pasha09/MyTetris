#pragma once

#include "consoleIO.h"
#include "conio.h"

class loopRender : virtual public consoleIO
{
public:
	loopRender();
	virtual void KeyPressed(int btnCode)=0;
	virtual void UpdateF(float deltaTime=0)=0;
	void run();
	~loopRender();
};

