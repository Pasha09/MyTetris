#include "loopRender.h"
 
loopRender* loopRender::pointerForTR = nullptr; 

loopRender::loopRender() : mTimer(NULL), mTimerQueue(NULL){
	mTimerQueue = CreateTimerQueue();
	pointerForTR = this; 
}

VOID CALLBACK loopRender::TimerRoutine(PVOID lpParam, BOOL TimerOrWaitFired){
	pointerForTR->UpdateF(); 
}
 
void loopRender::run(){
	CreateTimerQueueTimer(&mTimer, mTimerQueue, (WAITORTIMERCALLBACK)&loopRender::TimerRoutine, 0, 0, 1000, 0);
	while(1){
		if (_kbhit()){
			KeyPressed(_getch());
			if (!FlushConsoleInputBuffer(consoleIO::mConsoleInp))std::cout << "FlushConsoleInputBuffer failed";
		}
		Sleep(1);
		render(); 
	}
}

loopRender::~loopRender(){
	DeleteTimerQueueTimer(mTimerQueue, mTimer, NULL);
	DeleteTimerQueue(mTimerQueue);
}
