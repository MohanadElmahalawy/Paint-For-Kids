#include "..\ApplicationManager.h"
#include "..\Actions\SelectOneFigureAction.h"
#include "..\Actions\DeleteFigureAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}

void DeleteFigureAction::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("You have selected the 'Delete Figure' Action ");
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}


void DeleteFigureAction::Execute()
{
	ReadActionParameters();
	CFigure* pFig = pManager->GetSelectedFig();
	pManager->DeleteFigure(pFig);
	pManager->UpdateInterface();

	
}