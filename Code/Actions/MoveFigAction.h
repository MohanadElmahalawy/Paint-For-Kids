#pragma once
#ifndef MOVE_FIG_ACTION_H
#define MOVE_FIG_ACTION_H

#include "Action.h"


//Add Select One Figure Action class
class MoveFigAction : public Action
{
private:
	Point P1;
	Point P2;
	CFigure* CurrentSelected;
public:
	MoveFigAction(ApplicationManager* pApp);

	//
	virtual void ReadActionParameters();

	//
	virtual void Execute();

	void Undo() {};
	void Redo() {};

};









#endif