#include "..\ApplicationManager.h"

#include "..\Actions\ChangeDrawColorAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager* pApp) :Action(pApp)
{

}

void ChangeDrawColorAction::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You have selected the 'Change Draw Color' Action ");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}


void ChangeDrawColorAction::Execute()
{
	ReadActionParameters();
	CFigure* pFig = pManager->GetSelectedFig();
}


