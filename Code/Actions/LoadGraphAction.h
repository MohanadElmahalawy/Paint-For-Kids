#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include <fstream>
class LoadGraphAction :public Action
{

private:
	ifstream inFile;
	int countfigs;
	CFigure* myFig;
	string type, fileName, SDrawColor, SFillColor;
	color DrawColor, FillColor;
	Output* pOut;
	Input* pIn;

public:
	LoadGraphAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	void Undo() {};
	void Redo() {};
};

