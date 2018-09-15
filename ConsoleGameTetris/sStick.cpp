#include "sStick.h"


sStick::sStick(){
	mPosition = rand() % 1 + 0;
	if (mPosition == horizontal){ x = 17; y = 2; }
	else { x = 19; y = 1; }
	createFigure();
}

void sStick::startFigure(){
	if (mPosition == horizontal) { x = 6; y = 1; }
	else { x = 8; y = 1; }
	createFigure();
}

void sStick::createFigure(){
	for (int i = 0; i < 8; i += 2) {
		mPositionXYPoints[i] = x; mPositionXYPoints[i + 1] = y;
		if (mPosition == 0) { if (i == 2) { ++y; } else ++x; }
		if (mPosition == 1) { if (i == 2) { --x; } else ++y; }
	}
}

std::vector<int> sStick::conflictBorder(int direction){
	std::vector<int>informationAboutPoints;
		switch (direction){
			case downMove: {
							   if (mPosition == horizontal){
								   for (int i = 0; i < 8; ++i){
									   if (i == 2)i = 4;
									   plusY(informationAboutPoints, i);
								   }
							   }
							   else {
								   for (int i = 2; i < 8; ++i){
									   if (i == 4)i = 6;
									   plusY(informationAboutPoints, i);
								   }
							   }
							   break;
			}
			case leftMove: {
							   if (mPosition == horizontal){
								   for (int i = 0; i < 6; ++i){
									   if (i == 2)i = 4;
									   minusX(informationAboutPoints, i);
								   }
							   }
							   else {
								   for (int i = 0; i < 8; ++i){
									   if (i == 2)i = 4;
									   minusX(informationAboutPoints, i);
								   }
							   }
							   break; 
			}
			case rightMove: {
								if (mPosition == horizontal){
									for (int i = 2; i < 8; ++i){
										if (i == 4)i = 6;
										plusX(informationAboutPoints, i);
									}
								}
								else {
									for (int i = 0; i < 8; ++i){
										if (i == 4)i = 6;
										plusX(informationAboutPoints, i);
									}
								}
								break;
			}
		}
	return informationAboutPoints; 
}

std::vector<int> sStick::conflictBorderRotate(){
	std::vector<int>informationAboutPoints;
	switch (mPosition){
		case horizontal: {
							 for (int i = 0; i < 4; ++i){
								 minusY(informationAboutPoints, i);
							 }
							 plusY(informationAboutPoints, 0);
							 plusY(informationAboutPoints, 1);
							 break;
		}
		case vertical: {
						   for (int i = 0; i < 4; ++i){
							   plusX(informationAboutPoints, i);
						   }
						   plusX(informationAboutPoints, 6);
						   plusX(informationAboutPoints, 7);
						   informationAboutPoints.push_back(mPositionXYPoints[6]);
						   informationAboutPoints[informationAboutPoints.size() - 1] += 2; 
						   plusX(informationAboutPoints, 7);
						   minusY(informationAboutPoints, 4);
						   minusY(informationAboutPoints, 5);
						   break; 
		}
	}
	return informationAboutPoints;
}

void sStick::rotate(){
	if (mPosition == horizontal) { x = mPositionXYPoints[0] + 1; y = mPositionXYPoints[1] - 1; mPosition++; }
	else { x = mPositionXYPoints[0] - 1; y = mPositionXYPoints[1] + 1; mPosition--; }
	createFigure();
}

sStick::~sStick(){}

//add inline
inline void sStick::plusX(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if (!(i % 2)){ ++informationAboutPoints[informationAboutPoints.size() - 1]; }
}

inline void sStick::plusY(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if ((i % 2)){ ++informationAboutPoints[informationAboutPoints.size() - 1]; }
}
inline void sStick::minusX(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if (!(i % 2)){ --informationAboutPoints[informationAboutPoints.size() - 1]; }
}

inline void sStick::minusY(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if ((i % 2)){ --informationAboutPoints[informationAboutPoints.size() - 1]; }
}