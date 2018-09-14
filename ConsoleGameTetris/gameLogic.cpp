#include "gameLogic.h"


gameLogic::gameLogic() : consoleIO(widthSize, heightSize), //here set sizeWindow. widht and height
figureDef(nullptr), tempFigure(nullptr){      
	nextFigure(&figureDef);
	figureDef->startFigure(); 
	paint(figureDef);
	nextFigure(&tempFigure);
	paint(tempFigure);
	
}

void gameLogic::KeyPressed(int btnCode){
	erase(figureDef);
	if (btnCode == 80){ if (guard(1))figureDef->down(); else { paint(figureDef); tempToFigure(); return; } }
	else if (btnCode == 75){ if (guard(2))figureDef->left(); }
	else if (btnCode == 77){ if (guard(3))figureDef->right(); }
	else if (btnCode == 32){ if (guardRotate())figureDef->rotate(); }
	paint(figureDef); 
}

void gameLogic::UpdateF(float deltaTime){
	if (guard(1)){
		erase(figureDef);
		figureDef->down();
		paint(figureDef);
	}
	else {
		tempToFigure();
	}
}

void gameLogic::nextFigure(Figure** pointer){
	int randnumber = rand() % 2 + 0;
	switch (randnumber){
		case 0: {*pointer = new cube; break; }
		case 1: {*pointer = new stick; break; }
	}
}

void gameLogic::tempToFigure(){
	guardLine();
	if (figureDef != nullptr){
		delete figureDef; 
	}
	figureDef = tempFigure; 
	erase(tempFigure);
	figureDef->startFigure(); 
	checkGameOver(); 
	paint(figureDef);
	nextFigure(&tempFigure);
	paint(tempFigure); 
}

bool gameLogic::guard(int direction){
	std::vector<int> informationAboutPoints = figureDef->conflictBorder(direction); 
	for (int i = 0; i < informationAboutPoints.size(); i+=2){
		if (getChar(informationAboutPoints[i], informationAboutPoints[i + 1]) == '*' || getChar(informationAboutPoints[i], informationAboutPoints[i + 1]) == '#')return false; 
		//setChar(informationAboutPoints[i], informationAboutPoints[i + 1], '!');
	}
	return true; 
}

bool gameLogic::guardRotate(){
        std::vector<int> informationAboutPoints; 
		informationAboutPoints = figureDef->conflictBorderRotate();
		int size = informationAboutPoints.size() - 1;
		for (int i = 0; i <size; i += 2){
			if (informationAboutPoints[i]){
				if (getChar(informationAboutPoints[i], informationAboutPoints[i + 1]) == '*' || getChar(informationAboutPoints[i], informationAboutPoints[i + 1]) == '#')return false;
			}
			//setChar(informationAboutPoints[i], informationAboutPoints[i + 1], '!'); 
		}
	return true; 
}

void gameLogic::checkGameOver(){
	const int* positionXYPoints = figureDef->getPositionXYPoints(); 
	for (int i = 0; i < 8; i+=2){
		if (getChar(positionXYPoints[i], positionXYPoints[i + 1]) == '*'){
			clearField();
			return; 
		}
	}
}

void gameLogic::guardLine(){
	std::vector<int> valueY=figureDef->getY();
	int min = valueY[0];
	bool deleteLineBool=true; 
	bool checkDelete = true; 
	for (int i = 0; i < valueY.size(); ++i){
		deleteLineBool = true;
		checkDelete = true;
		if (min>valueY[i])min = valueY[i]; 
		for (int j = 1; j < borderRightofAreaForFallingFigure; ++j){
			if (getChar(j, valueY[i]) != '*'){
				deleteLineBool = false;
				checkDelete = false;
				break;
			}
		}
		if (deleteLineBool){ deleteLine(valueY[i]); }
	}
	if (checkDelete)dropLine(min, valueY.size()); //check later 
}

void gameLogic::dropLine(int level, int size){
	//find level when to drop
	int levelForDrop=findLevelWhereDrop(level,size); 
	//find line for copy
	for (int i = levelForDrop; i >= 1; --i){
		//checkLine
		for (int j = 1; j < borderRightofAreaForFallingFigure; ++j){
			if (getChar(j, i) == '*'){
				copyPasta(i, levelForDrop); 
				break; 
			}
		}
	}
}


int gameLogic::findLevelWhereDrop(int level, int size){
	int fLevel, startFind = level + size - 1;
	bool check = true; 
	for (int i = startFind; i>=level; --i){
		for (int j = 1; j < borderRightofAreaForFallingFigure; ++j){
			if (getChar(j, i) == '*'){
				check = false;
				break; 
			}
		}
		if (check){fLevel = i; break; }
		check = true; 
	}

	return fLevel; 
}

 
gameLogic::~gameLogic(){

}
