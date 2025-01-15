#pragma once
#include "Action.h"
class RedoAction : public Action
{
private:
	int count = 0;
	Action* LastAction;
	ApplicationManager* pApp;
public:
	RedoAction(ApplicationManager* pApp);
	virtual void Execute();
	void ReadActionParameters() {};
	//

	void Undo() {};
	void Redo() {};
};

