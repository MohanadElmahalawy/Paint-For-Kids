#ifndef SELECT_ONE_FIGURE_ACTION_H
#define SELECT_ONE_FIGURE_ACTION_H

#include "Action.h"


//Add Select One Figure Action class
class SelectOneFigureAction : public Action
{
private:
	Point P1;
	CFigure* CurrentSelected;
public:
	SelectOneFigureAction(ApplicationManager* pApp);

	//
	virtual void ReadActionParameters();

	//
	virtual void Execute();
	void Undo() {};
	void Redo() {};
	

};









#endif