#include "lStick.h"


lStick::lStick(){
	mPosition = rand() % 3 + 0;
	x = 18; y = 3;
	if (mPosition != mainDotUp)y = 2;
	createFigure();
}

void lStick::startFigure(){
	if (mPosition == mainDotDown){ x = 8; y = 1; }
	else { x = 8; y = 2; }
	createFigure();
}



void lStick::createFigure() {
	for (int volatile i = 0; i < 8; i += 2) {
		mPositionXYPoints[i] = x; mPositionXYPoints[i + 1] = y;
		if (mPosition == mainDotUp) { if (i == 0)++x; else if (i == 2)x -= 2; else --y; }
		else if (mPosition == mainDotRight) { if (i == 0)++y; else if (i == 2)y -= 2; else ++x; }
		else if (mPosition == mainDotDown) { if (i == 0)--x; else if (i == 2)x += 2; else ++y; }
		else if (mPosition == mainDotLeft) { if (i == 0)--y; else if (i == 2)y += 2; else --x; }

	}
}

std::vector<int> lStick::conflictBorder(int direction){
	std::vector<int>informationAboutPoints;
	switch (direction){
			case downMove: {
							   if (mPosition == mainDotUp){
								   for (int i = 0; i < 6; ++i){
									   plusY(informationAboutPoints, i);
								   }
							   }
							   else if (mPosition == mainDotRight){
								   for (int i = 2; i < 8; ++i){
									   if (i == 4)i = 6;
									   plusY(informationAboutPoints, i);
								   }
							   }
							   else if (mPosition == mainDotDown){
								   for (int i = 0; i < 8; ++i){
									   if (i == 4)i = 6;
									   plusY(informationAboutPoints, i);
								   }
							   }
							   else if (mPosition == mainDotLeft){
								   for (int i = 4; i < 8; ++i){
									   plusY(informationAboutPoints, i);
								   }
							   }
							   return informationAboutPoints; 
			}
			case leftMove: {
							   if (mPosition == mainDotUp){
								   for (int i = 4; i < 8; ++i){
									   minusX(informationAboutPoints, i);
								   }  
							   }
							   else if (mPosition == mainDotRight){
								   for (int i = 0; i < 6; ++i){
									   minusX(informationAboutPoints, i);
								   }
							   }
							   else if (mPosition == mainDotDown){
								   for (int i = 2; i < 8; ++i){
									   if (i == 4)i = 6;
									   minusX(informationAboutPoints, i);
								   }
							   }
							   else if (mPosition == mainDotLeft){
								   for (int i = 0; i < 8; ++i){
									   if (i == 4)i = 6; 
									   minusX(informationAboutPoints, i);
								   }
							   }
							   return informationAboutPoints;
			}
			case rightMove: {
								if (mPosition == mainDotUp){
									for (int i = 2; i < 8; ++i){
										if (i == 4)i = 6; 
										plusX(informationAboutPoints, i);
									}
								}
								else if (mPosition == mainDotRight){
									for (int i = 0; i < 8; ++i){
										plusX(informationAboutPoints, i);
									}
								}
								else if (mPosition == mainDotDown){
									for (int i = 4; i < 8; ++i){
										plusX(informationAboutPoints, i);
									}
								}
								else if (mPosition == mainDotLeft){
									for (int i = 0; i < 6; ++i){
										plusX(informationAboutPoints, i);
									}
								}
					return informationAboutPoints;
			}
	}
	exit(1); 
}

std::vector<int> lStick::conflictBorderRotate(){
	std::vector<int>informationAboutPoints;
	for (int side = 0; side < 2; ++side){
		if (side == front){
			switch (mPosition){
				case mainDotUp: {
									for (int i = 0; i < 4; i += 2){
										informationAboutPoints.push_back(mPositionXYPoints[i]);
										minusY(informationAboutPoints, i+1); 
									}
									break;
				}
				case mainDotRight:{
									  plusX(informationAboutPoints, 0);
									  informationAboutPoints.push_back(mPositionXYPoints[1]);
									  break;
				}
				case mainDotDown:{
									 for (int i = 0; i < 4; i+=2){
										 informationAboutPoints.push_back(mPositionXYPoints[i]);
										 plusY(informationAboutPoints, i+1);
									 }
									 break;
				}
				case mainDotLeft: {
									  for (int i = 0; i < 4; i += 2){
										  minusX(informationAboutPoints, i);
										  informationAboutPoints.push_back(mPositionXYPoints[i + 1]);
									  }
									  break;
				}
			}
		}
		else {
			switch (mPosition){
				case mainDotUp: {
									for (int i = 0; i < 4; i += 2){
										informationAboutPoints.push_back(mPositionXYPoints[i]);
										plusY(informationAboutPoints, i + 1);
									}
									break;
				}
				case mainDotRight:{
									  for (int i = 0; i < 4; i+=2){
										  minusX(informationAboutPoints, i);
										  informationAboutPoints.push_back(mPositionXYPoints[i+1]);
									  }
									  break;
				}
				case mainDotDown:{
									 for (int i = 0; i < 4; i += 2){
										 informationAboutPoints.push_back(mPositionXYPoints[i]);
										 minusY(informationAboutPoints, i + 1);
									 }
									 break;
				}
				case mainDotLeft: {
									  for (int i = 0; i < 4; i += 2){
										  plusX(informationAboutPoints, i);
										  informationAboutPoints.push_back(mPositionXYPoints[i + 1]);
									  }
									  break;
				}
			}
		}
	}
	return informationAboutPoints; 
}

void lStick::rotate(){
	if (mPosition == mainDotLeft)mPosition = mainDotUp; else { mPosition++; }
	x = mPositionXYPoints[0]; y = mPositionXYPoints[1];
	createFigure();
}

lStick::~lStick(){}

//add inline
inline void lStick::plusX(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if (!(i % 2)){ ++informationAboutPoints[informationAboutPoints.size() - 1]; }
}

inline void lStick::plusY(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if ((i % 2)){ ++informationAboutPoints[informationAboutPoints.size() - 1]; }
}
inline void lStick::minusX(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if (!(i % 2)){ --informationAboutPoints[informationAboutPoints.size() - 1]; }
}

inline void lStick::minusY(std::vector<int>& informationAboutPoints, int i){
	informationAboutPoints.push_back(mPositionXYPoints[i]);
	if ((i % 2)){ --informationAboutPoints[informationAboutPoints.size() - 1]; }
}