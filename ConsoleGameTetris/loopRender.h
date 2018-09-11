#pragma once

#include "consoleIO.h"
#include "conio.h"

class loopRender : public consoleIO
{
public:
	loopRender(int width, int height);
	virtual void KeyPressed(int btnCode)=0;
	virtual void UpdateF(float deltaTime=0)=0;
	void run();
	~loopRender();
};

