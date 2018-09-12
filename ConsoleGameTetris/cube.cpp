#include "cube.h"


cube::cube(){
	x = 7; y = 1;
	createFigure();
}

void cube::startFigure(){
	x = 19; y = 2;
	createFigure();
}

void cube::createFigure(){
	for (int i = 0; i < 8; i += 2) {
		mPositionXYPoints[i] = x; mPositionXYPoints[i + 1] = y;
		if (i == 2) { ++y; --x; }
		else ++x;
	}
}



cube::~cube(){}
