#include "..\ApplicationManager.h"

#include "..\Actions\SelectOneFigureAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectOneFigureAction::SelectOneFigureAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectOneFigureAction:: ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You have selected the 'Select One Figure' Action ");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
void SelectOneFigureAction::Execute()
{
    ReadActionParameters();

	CFigure* pFig = pManager->GetFigure(P1.x,P1.y);

	if (pFig != NULL && pFig->IsSelected() == false) {
		pManager->DeSelectFigure();
		pFig->SetSelected(true);
		pManager->SetSelectedFig(pFig);
		pFig->PrintInfo(pManager->GetOutput());
	}
	else if (pFig != NULL && pFig->IsSelected() == true) {
		
		pFig->SetSelected(false);
		pManager->SetSelectedFig(NULL);
		return;
	}
}