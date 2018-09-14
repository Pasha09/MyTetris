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

void stick::rotate(){
	x = mPositionXYPoints[0];
	y = mPositionXYPoints[1];
	if (mPosition == vertical) { mPosition = horizontal; ++x; --y; }
	else { mPosition = vertical; --x; ++y; }
	createFigure();
}

std::vector<int> stick::conflictBorderRotate(){
	std::vector<int>informationAboutPoints;
	for (int side = 0; side < 2; ++side){
		if (side == front){
			switch (mPosition){
			case vertical: {
							   for (int i = 2; i < 8; i+=2){
								   informationAboutPoints.push_back(mPositionXYPoints[i]);
								   informationAboutPoints.push_back(mPositionXYPoints[i+1]);
								   ++informationAboutPoints[informationAboutPoints.size() - 1]; 
								   informationAboutPoints.push_back(mPositionXYPoints[i]);
								   informationAboutPoints.push_back(mPositionXYPoints[i + 1]);
								   informationAboutPoints[informationAboutPoints.size() - 1]+=2;
							   }
							   break;
 
			}
			case horizontal: {
								 for (int i = 2; i < 8; i += 2){
									 informationAboutPoints.push_back(mPositionXYPoints[i]);
									 --informationAboutPoints[informationAboutPoints.size() - 1];
									 informationAboutPoints.push_back(mPositionXYPoints[i+1]);
								 }
								 break;
			}
			}
		}
		else {
			switch (mPosition){
			case vertical: {
							   informationAboutPoints.push_back(mPositionXYPoints[2]);
							   informationAboutPoints.push_back(mPositionXYPoints[3]);
							   --informationAboutPoints[informationAboutPoints.size() - 1];
							   break; 
			}
			case horizontal: {
								 for (int i = 0; i < 4; i += 2){
									 informationAboutPoints.push_back(mPositionXYPoints[i]);
									 ++informationAboutPoints[informationAboutPoints.size() - 1];
									 informationAboutPoints.push_back(mPositionXYPoints[i+1]);
									 informationAboutPoints.push_back(mPositionXYPoints[i]);
									 informationAboutPoints[informationAboutPoints.size() - 1] += 2;
									 informationAboutPoints.push_back(mPositionXYPoints[i+1]);
								 }
								 break; 
			}
			}
		}
	}
	return informationAboutPoints; 
}

stick::~stick(){}