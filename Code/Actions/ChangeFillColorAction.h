#ifndef CHANGE_FILL_COLOR_ACTION_H
#define CHANGE_FILL_COLOR_ACTION_H


#include "Action.h"

//Add Change Figure Color Action class
class ChangeFillColorAction : public Action
{
private:
	color figcolor;
	ActionType color;
	Point P1;
public:
	ChangeFillColorAction(ApplicationManager* pApp);
	//
	virtual void ReadActionParameters();

	//
	virtual void Execute();

	bool GetColor(ActionType color);
	//
	void Undo() {};
	void Redo() {};
};

#endif