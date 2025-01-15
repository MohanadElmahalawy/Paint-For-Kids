#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read first corner of triangle and store in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read second corner of triangle and store in P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read third corner of triangle and store in P3
	pIn->GetPointClicked(P3.x, P3.y);

	//An altercation should be made to check whether the shape drawn is filled or not
	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Creating a triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1,P2,P3, TriGfxInfo);

	//Adding the triangle to the list of figures
	pManager->AddFigure(T);
}
void AddTriAction::Undo()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Triangle Deleted!");
}
void AddTriAction::Redo() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Triangle Added!");

}