#pragma once

#include "consoleIO.h"
#include "conio.h"

class loopRender : virtual public consoleIO
{
private: 
	HANDLE mTimer;
	HANDLE mTimerQueue;
	static VOID CALLBACK TimerRoutine(PVOID lpParam, BOOL TimerOrWaitFired); 
	static loopRender* pointerForTR; 
public:
	loopRender();
	virtual void KeyPressed(int btnCode)=0;
	virtual void UpdateF(float deltaTime=0)=0;
	void run();
	~loopRender();
};

