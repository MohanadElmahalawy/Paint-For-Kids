#ifndef DELETE_FIGURE_ACTION_H
#define DELETE_FIGURE_ACTION_H

#include "Action.h"


//Add Delete Figure Action class
class DeleteFigureAction : public Action
{
private:
	Point P1;
public:
	DeleteFigureAction(ApplicationManager* pApp);

	//
	virtual void ReadActionParameters();

	//
	virtual void Execute();
	void Undo() {};
	void Redo() {};
};



#endif
