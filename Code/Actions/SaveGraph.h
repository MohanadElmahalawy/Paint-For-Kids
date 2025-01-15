#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include <fstream>

class SaveGraph : public Action
{
private:
	ofstream outFile;
	string type;
	CFigure* myFig;
	Output* pLoad;
	string fileName;
public:

SaveGraph(ApplicationManager* pApp);
 void ReadActionParameters();
 void Execute();
 void Undo() {};
 void Redo() {};
};

