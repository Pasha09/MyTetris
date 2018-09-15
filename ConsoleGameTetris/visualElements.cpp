#include "visualElements.h"


visualElements::visualElements(){
		//here I build border for Tetris.
	for (int j = 0; j < heightSize; ++j){
		//here i put # except 0, 5, 21 points.
		if (j != 0 && j != 5 && j != heightSize-1){
			for (int i = 1; i<borderRightofAreaForFallingFigure; ++i)setChar(i, j, '.'); //here I put '.'
			//paint border for AreaForFallingFigure
			setChar(0, j, '#'); setChar(borderRightofAreaForFallingFigure, j, '#');
			if (j > 0 && j < 5) { setChar(widthSize-1, j, '#');  for (int i = borderRightofAreaForFallingFigure+1; i < widthSize-1; ++i)setChar(i, j, '.'); }
		} else if (j == 5) { 
			setChar(0, j, '#'); 
			for (int i = 1; i <= widthSize; ++i) { i<borderRightofAreaForFallingFigure ? setChar(i, j, '.') : setChar(i, j, '#'); }
		} else {
			for (int i = 0; i < (j == heightSize - 1 ? borderRightofAreaForFallingFigure+1 : widthSize); ++i)setChar(i, j, '#');
		}
	}
	//instruction
	char text[][6] = {
		{ "ctrl:" },
		{ "arrow" },
		{ "space" }};
	for (int i = 17; i < 22; ++i){
		setChar(i, 8, text[0][i-17]);
		setChar(i, 9, text[1][i - 17]);
		setChar(i, 10, text[2][i - 17]);
	}
	
	
}

void visualElements::paint(Figure *obj){
	int* const mPosXYPoints=obj->mPositionXYPoints; 
	for (int i = 0; i < 8; i += 2){
		setChar(mPosXYPoints[i], mPosXYPoints[i + 1], '*');
	} 
}

void visualElements::erase(Figure *obj){
	int* const mPosXYPoints = obj->mPositionXYPoints;
	for (int i = 0; i < 8; i += 2){
		setChar(mPosXYPoints[i], mPosXYPoints[i + 1], '.');
	}
}

void visualElements::clearField(){
	for (int i = 1; i < borderRightofAreaForFallingFigure; ++i)
		for (int j = 1; j < heightSize-1; ++j){
			setChar(i, j, '.');
		}
}

void visualElements::deleteLine(int level){
	for (int i = 1; i < borderRightofAreaForFallingFigure; ++i){
		setChar(i, level, '.'); 
	}
}

void visualElements::copyPasta(int level, int &levelDrop){
	for (int i = 1; i < borderRightofAreaForFallingFigure; ++i){
		setChar(i, levelDrop, getChar(i, level)); 
	}
	--levelDrop;
	deleteLine(level); 
}

visualElements::~visualElements(){}
