#ifndef CHANGE_DRAW_COLOR_ACTION_H
#define CHANGE_DRAW_COLOR_ACTION_H


#include "Action.h"

class ChangeDrawColorAction : public Action
{
private:
	Point P1;
public:
	ChangeDrawColorAction(ApplicationManager* pApp);
	//
	virtual void ReadActionParameters();

	//
	virtual void Execute();
	void Undo() {};
	void Redo() {};

};

#endif