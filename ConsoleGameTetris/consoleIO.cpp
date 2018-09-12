#include "consoleIO.h"

consoleIO::consoleIO() : xSize(0), ySize(0){}

consoleIO::consoleIO(int width, int height) : xSize(width), ySize(height), mDwBufferCoord({ 0, 0 }){
	
	SetConsoleTitle("Tetris");

	SMALL_RECT windowSize = { 0, 0, xSize - 1, ySize -1}; //coord.
	windowBufSize = { xSize, ySize }; 
	
	offScroll();
	
	mConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	mConsoleInp = GetStdHandle(STD_INPUT_HANDLE);

	hideCursor(); 
	disableChangeSizeWindow(); 

	if (!SetConsoleScreenBufferSize(mConsoleOut, windowBufSize)){
 
	}
	if (!SetConsoleWindowInfo(mConsoleOut, TRUE, &windowSize)){
		
	}

	mBufferConsole = new CHAR_INFO[xSize*ySize]; 
	mLpWriteRegion = windowSize;

	for (int i = 0; i < xSize; ++i)
		for (int j = 0; j < ySize; ++j){
			setChar(i, j, ' ');
			mBufferConsole[i+xSize*j].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED; 
		}
		render(); 
}

void consoleIO::offScroll(){
	std::string commandForSystem = "mode con cols=  lines= ";
	char str[9], str2[9];
	sprintf_s(str, "%i", xSize);
	sprintf_s(str2, "%i", ySize);
	commandForSystem.insert(14, std::string((const char *)str));
	commandForSystem.insert(commandForSystem.length() - 1, std::string((const char *)str2));
	system((const char*)commandForSystem.c_str());
}

void consoleIO::hideCursor(){
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsoleOut, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(mConsoleOut, &cursorInfo);
}

void consoleIO::disableChangeSizeWindow(){
	HWND hWnd;
	HMENU hm;
	if ((hWnd = GetConsoleWindow()) == NULL){
		printf("No console window!?\n");
		return;
	}
	hm = GetSystemMenu(hWnd, FALSE);
	RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
	RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
	DrawMenuBar(hWnd);
}

void consoleIO::setChar(int x, int y, char symbol){
	mBufferConsole[x + xSize*y].Char.AsciiChar = symbol;
}

char consoleIO::getChar(int x, int y){
	return mBufferConsole[x + xSize*y].Char.AsciiChar;
}

void consoleIO::render(){
	WriteConsoleOutputA(mConsoleOut, mBufferConsole, windowBufSize, mDwBufferCoord, &mLpWriteRegion);
}

consoleIO::~consoleIO(){
	delete mBufferConsole; 
}
