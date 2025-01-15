#pragma once
#include "Action.h"
class UndoAction : public Action
{
private:
	int count=0;

	ApplicationManager* pApp;
public:
	UndoAction(ApplicationManager* pApp);
	
	//

	void ReadActionParameters() {};
	//
	 void Execute();
	 void Undo() {};
	 void Redo() {};
};