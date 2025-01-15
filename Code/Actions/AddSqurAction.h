#pragma once
#ifndef ADD_SQUR_ACTION_H
#define ADD_SQUR_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSqurAction : public Action
{
private:
	Point P1; //Square Center Point
	GfxInfo SqurGfxInfo;
public:
	AddSqurAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Adds square to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif