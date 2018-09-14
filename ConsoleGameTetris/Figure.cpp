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

const int* Figure::getPositionXYPoints(){
	return mPositionXYPoints; 
}

std::vector<int> Figure::getY(){
	std::vector<int> valueY;
	bool addValue;
	for (int i = 1; i < 8; i += 2){
		addValue = true;
		for (int j = 0; j < valueY.size(); ++j){
			if (valueY[j] == mPositionXYPoints[i]){
				addValue = false; break;
			}
		}
		if (addValue)valueY.push_back(mPositionXYPoints[i]);
	}
	return valueY;
}

Figure::~Figure(){}
