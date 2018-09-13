#include "cube.h"


cube::cube(){
	x = 18; y = 2;
	createFigure();
}

void cube::startFigure(){
	x = 7; y = 1;
	createFigure();
}

void cube::createFigure(){
	for (int i = 0; i < 8; i += 2) {
		mPositionXYPoints[i] = x; mPositionXYPoints[i + 1] = y;
		if (i == 2) { ++y; --x; }
		else ++x;
	}
}

std::vector<int> cube::conflictBorder(int direction){
	std::vector<int>informationAboutPoints;
	informationAboutPoints.reserve(6);
	switch (direction){
		case downMove: {
						   for (int i = 4; i < 8; i += 2){
							   informationAboutPoints.push_back(mPositionXYPoints[i]); 
							   informationAboutPoints.push_back(mPositionXYPoints[i + 1]); 
							   ++informationAboutPoints[informationAboutPoints.size() - 1]; 
						   }
						   return informationAboutPoints; 
		}
		case leftMove: {
						   for (int i = 0; i < 8; i += 4){
							   informationAboutPoints.push_back(mPositionXYPoints[i]); 
							   informationAboutPoints.push_back(mPositionXYPoints[i + 1]); 
							   --informationAboutPoints[informationAboutPoints.size() - 2]; 
						   }
						   return informationAboutPoints; 
		}
		case rightMove: {
							for (int i = 2; i < 8; i+=4){
								informationAboutPoints.push_back(mPositionXYPoints[i]);
								informationAboutPoints.push_back(mPositionXYPoints[i + 1]);
								++informationAboutPoints[informationAboutPoints.size() - 2];
							}
							return informationAboutPoints;
		}
	}
	exit(1); //here is mistake 
}

std::vector<int> cube::getY(){
	std::vector<int> valueY;
	bool addValue; 
	for (int i = 1; i < 8; i += 2){
		addValue = true; 
		for (int j = 0; j < valueY.size(); ++j){
			if (valueY[j] == mPositionXYPoints[i]){
				addValue = false; break; 
			}
		}
		if(addValue)valueY.push_back(mPositionXYPoints[i]); 
	}
	return valueY; 
}

cube::~cube(){}
