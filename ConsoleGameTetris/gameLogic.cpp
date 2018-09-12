#include "gameLogic.h"


gameLogic::gameLogic() : consoleIO(widthSize, heightSize), //here set sizeWindow. widht and height
figureDef(nullptr), tempFigure(nullptr){      
	
	nextFigure(&figureDef);
	figureDef->startFigure(); 
	nextFigure(&tempFigure);
	paint(tempFigure);
	paint(figureDef); 

}

void gameLogic::KeyPressed(int btnCode){
	erase(figureDef);
	if (btnCode == 80){ figureDef->down();  }
	else if (btnCode == 75){ figureDef->left();}
	else if (btnCode == 77){ figureDef->right();}
	else if (btnCode == 32){}
	paint(figureDef); 
}

void gameLogic::UpdateF(float deltaTime){
	erase(figureDef);
	figureDef->down();
	paint(figureDef);
}

void gameLogic::nextFigure(Figure** pointer){
	int randnumber = 0;//= rand() % 6 + 0;
	switch (randnumber){
		case 0: {*pointer = new cube; break; }
	}
}

void gameLogic::tempToFigure(){
	if (figureDef != nullptr){
		delete figureDef; 
	}
	figureDef = tempFigure; 
//	nextFigure(); 
}

gameLogic::~gameLogic(){

}
