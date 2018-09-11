#pragma once

#include "windows.h"
#include "iostream"
#include "string"
#include "stdio.h"


class consoleIO{
private: 
	const int xSize, ySize; 
	
	//stdout, stdin
	HANDLE mConsoleOut;
	HANDLE mConsoleInp;

	//array buffer console
	CHAR_INFO* mBufferConsole; 
	
	COORD windowBufSize; 
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;
	
	
	void offScroll(); 
	void hideCursor(); 
	void disableChangeSizeWindow(); 


public:
	consoleIO(int width, int height);
	
	void setChar(int x, int y, char symbol); 
	char getChar(int x, int y);
	void render(); 
	~consoleIO();
};

