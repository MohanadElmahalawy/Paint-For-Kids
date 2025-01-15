#include "..\ApplicationManager.h"

#include "..\Actions\MoveFigAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveFigAction::MoveFigAction(ApplicationManager* pApp) :Action(pApp)
{}


void MoveFigAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMessage("You have selected the 'Move Figure' Action ");
    pOut->ClearStatusBar();
    pOut->PrintMessage("Click on the location you want to draw the figure in");
    pIn->GetPointClicked(P2.x, P2.y);
    pOut->ClearStatusBar();
    pOut->ClearDrawArea();
    
}

void MoveFigAction::Execute()
{
    ReadActionParameters();
    CFigure* pFig = pManager->GetSelectedFig();
    pManager->GetMoveFigure(pFig);
    if (pFig != NULL && pFig->IsSelected() == true)
    {
        pFig->MoveFigure(P2.x, P2.y);

    }
}
