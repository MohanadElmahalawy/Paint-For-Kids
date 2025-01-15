#include "BlackAction.h"
#include "..\ApplicationManager.h"

#include "..\Actions\BlackAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BlackAction::BlackAction(ApplicationManager* pApp) :Action(pApp)
{

}

void BlackAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You have selected the 'Change Draw Color' Action ");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}


void BlackAction::Execute()
{

}