#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at centre point");

	//Read centre point of hexagon and store in P1
	pIn->GetPointClicked(P1.x, P1.y);


	//An altercation should be made to check whether the shape drawn is filled or not
	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Creating a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1, HexGfxInfo);

	//Adding the hexagon to the list of figures
	pManager->AddFigure(H);
}
void AddHexAction::Undo()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Hexagon Deleted!");
}
void AddHexAction::Redo() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Hexagon Added!");

}