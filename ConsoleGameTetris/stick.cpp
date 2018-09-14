#include "stick.h"


stick::stick(){
	mPosition = rand() % 2 + 0;
	if (mPosition == vertical) {y = 2; x = 17;}
	else  { y = 1; x = 18; }
	createFigure();
}

void stick::startFigure(){
	if (mPosition == vertical) { x = 7; y = 2; }
	else { x = 8; y = 1; }
	createFigure();
}

void stick::createFigure(){
	for (int i = 0; i < 8; i += 2) {
		mPositionXYPoints[i] = x; mPositionXYPoints[i + 1] = y;
		if (mPosition == vertical)++x; else ++y;
	}
}

std::vector<int> stick::conflictBorder(int direction){
	std::vector<int>informationAboutPoints;
	switch (direction){
	case downMove: {
					   if (mPosition == vertical){
						   for (int i = 0; i < 8; ++i){
							   informationAboutPoints.push_back(mPositionXYPoints[i]);
							   if ((i % 2))++informationAboutPoints[informationAboutPoints.size()-1];
						   }
					   }
					   else {
						   informationAboutPoints.push_back(mPositionXYPoints[6]);
						   informationAboutPoints.push_back(mPositionXYPoints[7]);
						   ++informationAboutPoints[informationAboutPoints.size()-1];
					   } 
					   return informationAboutPoints;
	}
	case leftMove: {
					   if (mPosition == vertical){
						   informationAboutPoints.push_back(mPositionXYPoints[0]);
						   --informationAboutPoints[informationAboutPoints.size() - 1];
						   informationAboutPoints.push_back(mPositionXYPoints[1]);
					   }
					   else {
						   for (int i = 0; i < 8; ++i){
							   informationAboutPoints.push_back(mPositionXYPoints[i]);
							   if (!(i % 2))--informationAboutPoints[informationAboutPoints.size() - 1];
						   }
					   }
					   return informationAboutPoints;
	}
	case rightMove: {
						if (mPosition == vertical){
							informationAboutPoints.push_back(mPositionXYPoints[6]);
							++informationAboutPoints[informationAboutPoints.size() - 1];
							informationAboutPoints.push_back(mPositionXYPoints[7]);
						}
						else {
							for (int i = 0; i < 8; ++i){
								informationAboutPoints.push_back(mPositionXYPoints[i]);
								if (!(i % 2))++informationAboutPoints[informationAboutPoints.size() - 1];
							}
						}
						return informationAboutPoints;
	}
	}
	exit(1); //here is mistake 
}

std::vector<int> stick::getY(){
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

void stick::rotate(){
	x = mPositionXYPoints[0];
	y = mPositionXYPoints[1];
	if (mPosition == vertical) { mPosition = horizontal; ++x; --y; }
	else { mPosition = vertical; --x; ++y; }
	createFigure();
}

std::vector<int> stick::conflictBorderRotate(int side){
	std::vector<int>informationAboutPoints;
	if (side == front){
		switch (mPosition){
			case vertical: {
							   for (int i = 2; i < 8; ++i){
								   informationAboutPoints.push_back(mPositionXYPoints[i]);
								   if ((i % 2))informationAboutPoints[informationAboutPoints.size() - 1] += 2;
							   }
							   return informationAboutPoints; 
			}
			case horizontal: {
								 for (int i = 2; i < 8; ++i){
									 informationAboutPoints.push_back(mPositionXYPoints[i]);
									 if (!(i % 2))informationAboutPoints[informationAboutPoints.size() - 1] -= 2;
								 }
								 return informationAboutPoints;
			}
		}
	}
	else {
		switch (mPosition){
		case vertical: {
						  
						   return informationAboutPoints;
		}
		case horizontal: {
							 
						   return informationAboutPoints;
		}
		}
	}
	return informationAboutPoints; 
}

stick::~stick(){}