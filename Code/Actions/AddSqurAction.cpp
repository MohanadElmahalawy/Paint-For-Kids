#include "AddSqurAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqurAction::AddSqurAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqurAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at centre point");

	//Read centre point of square and store in P1
	pIn->GetPointClicked(P1.x, P1.y);
	

	//An altercation should be made to check whether the shape drawn is filled or not
	SqurGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqurGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqurGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqurAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Creating a square with the parameters read from the user
	CSquare* Sq = new CSquare(P1, SqurGfxInfo);

	//Adding the square to the list of figures
	pManager->AddFigure(Sq);
}
void AddSqurAction::Undo()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Square Deleted!");
}

void AddSqurAction::Redo() {

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Square Added!");
}