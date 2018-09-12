#include "loopRender.h"


loopRender::loopRender(){}

void loopRender::run(){
	while(1){
		if (_kbhit()){
			KeyPressed(_getch());
			if (!FlushConsoleInputBuffer(consoleIO::mConsoleInp))std::cout << "FlushConsoleInputBuffer failed";
		}
		UpdateF(); 
		Sleep(1000);
		render(); 
	}
}

loopRender::~loopRender(){}
