#include "visualElements.h"


visualElements::visualElements(){
		//here I build border for Tetris.
	for (int j = 0; j < heightSize; ++j){
		//here i put # except 0, 5, 21 points.
		if (j != 0 && j != 5 && j != heightSize){
			for (int i = 1; i<borderRightofAreaForFallingFigure; ++i)setChar(i, j, '.'); //here I put '.'
			//paint border for AreaForFallingFigure
			setChar(0, j, '#'); setChar(borderRightofAreaForFallingFigure, j, '#');
			if (j > 0 && j < 5) { setChar(widthSize-1, j, '#');  for (int i = borderRightofAreaForFallingFigure+1; i < widthSize-1; ++i)setChar(i, j, '.'); }
		} else if (j == 5) { 
			setChar(0, j, '#'); 
			for (int i = 1; i <= widthSize; ++i) { i<borderRightofAreaForFallingFigure ? setChar(i, j, '.') : setChar(i, j, '#'); }
		} else {
			for (int i = 0; i < (j == heightSize ? 17 : widthSize); ++i)setChar(i, j, '#');
		}
	}
}

void visualElements::paint(){

}

void visualElements::erase(){

}

visualElements::~visualElements()
{
}
