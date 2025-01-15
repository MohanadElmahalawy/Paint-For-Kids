#include "..\ApplicationManager.h"

#include "..\Actions\ChangeFillColorAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ChangeFillColorAction::ChangeFillColorAction(ApplicationManager* pApp) :Action(pApp)
{

}

void ChangeFillColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You have selected the 'Change Fill Color' Action ");
	pIn->GetPointClicked(P1.x, P1.y);
	color = pIn->GetUserAction();
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}

void ChangeFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure* pFig = pManager->GetSelectedFig();
	if (pFig != NULL) 
	{
		if (GetColor(color) == 1)
		{
			pFig->ChngFillClr(color);
		}
		pOut->SetCrntFillColor(color);
	}
}
bool ChangeFillColorAction::GetColor(ActionType color)
{
	switch (color)
	{
	case DRAW_Black:
		figcolor = BLACK;
		return 1;
	case DRAW_Yellow:
		figcolor = YELLOW;
		return 1;
	case DRAW_Red:
		figcolor = RED;
		return 1;
	case DRAW_Orange:
		figcolor = ORANGE;
		return 1;
	case DRAW_Blue:
		figcolor = BLUE;
	case DRAW_Green:
		figcolor = GREEN;
		return 1;
	default :
		return 0;
	}
}