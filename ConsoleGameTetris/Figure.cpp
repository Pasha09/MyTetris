#include "Figure.h"


 

void Figure::down(){
	for (int i = 1; i < 8; i += 2)++mPositionXYPoints[i];
}

void Figure::left(){
	for (int i = 0; i < 8; i += 2)--mPositionXYPoints[i]; 
}

void Figure::right(){
	for (int i = 0; i < 8; i += 2)++mPositionXYPoints[i]; 
}



Figure::~Figure(){}
