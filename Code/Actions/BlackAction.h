#ifndef CHANGE_DRAW_COLOR_ACTION_H
#define CHANGE_DRAW_COLOR_ACTION_H
#pragma once
#include "Action.h"

class BlackAction :public Action
{
private:
	Point P1;
public:
	BlackAction(ApplicationManager* pApp);
		//
	virtual void ReadActionParameters();

		//
	virtual void Execute();
	


};
#endif
