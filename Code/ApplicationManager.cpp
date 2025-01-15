#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddSqurAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\ChangeDrawColorAction.h"
#include "Actions\ChangeFillColorAction.h"
#include "Actions\SelectOneFigureAction.h"
#include "Actions\DeleteFigureAction.h"
#include "Actions\SaveGraph.h"
#include "Actions\LoadGraphAction.h"
#include "Actions\MoveFigAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\Action.h"
#include "Actions\UndoAction.h"
#include "Actions\RedoAction.h"




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
	for (int i = 0;i < 5;i++)
		actionlist[i] = NULL;

	LastAction = NULL;
	actioncount = 0;
}
//=================================================================================//
//							Selected Figures Related Functions				       //
//=================================================================================//
void ApplicationManager::SetSelectedFig(CFigure* pSelectedFig)
{
	SelectedFig=pSelectedFig;

} //Sets the selected figure with the figure selected from the user

CFigure *ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}//Gets the selected figure 


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_Circ:
			pAct = new AddCircAction(this);
			break;

		case DRAW_Tri:
			pAct = new AddTriAction(this);
			break;

		case DRAW_Sq:
			pAct = new AddSqurAction(this);
			break;

		case DRAW_Hex:
			pAct = new AddHexAction(this);
			break;

		case DRAW_Select:
			pAct = new SelectOneFigureAction(this);
			break;
		case DRAW_DrawColor:
			pAct = new ChangeDrawColorAction(this);
			break;
		case DRAW_FillColor:
			pAct = new ChangeFillColorAction(this);
			break;
		case DRAW_Black:

			break;
		case DRAW_Yellow:

			break;
		case DRAW_Orange:

			break;
		case DRAW_Red:

			break;
		case DRAW_Green:

			break;
		case DRAW_Blue:

			break;
		case DRAW_Move:
			pAct = new MoveFigAction(this);
		

			break;
		case DRAW_Delete:
			pAct = new DeleteFigureAction(this);

			break;
		case DRAW_Undo:
			pAct = new UndoAction(this);
			
			pAct->Execute();
			pAct = NULL;
			break;
		case DRAW_Redo:
			pAct = new RedoAction(this);
			pAct->Execute();
			pAct = NULL;
			break;
		case DRAW_ClearAll:
			pAct = new ClearAllAction(this);
			break;
		case DRAW_StartRec:

			break;
		case DRAW_StopRec:

			break;
		case DRAW_PlayRec:

			break;
		case DRAW_SaveGraph:
			pAct = new SaveGraph(this);
			break;
		case DRAW_LoadGraph:
			pAct = new LoadGraphAction(this);
			break;
		case DRAW_PlayMode:
			pOut->CreatePlayToolBar();
			break;

		case PLAY_PH:

			break;
		case PLAY_ByType:

			break;
		case PLAY_ByBoth:

			break;
		case PLAY_ByFill:

			break;
		case PLAY_DrawMode:
			pOut->CreateDrawToolBar();
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		
		pAct->Execute();//Execute
		LastAction = pAct;	//You may need to change this line depending to your implementation
		addLastAction(pAct);
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//


void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount++] = pFig;
		pFig->SetID(FigCount);
	}
}
void ApplicationManager::DeleteFigure(CFigure* pFig) 
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]==pFig) {
			delete FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
			
		}		
	}
}
void ApplicationManager::SaveAll(ofstream& outFile) {
	outFile << FigCount << " \n";
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(outFile, i);
}
//CFigure* ApplicationManager::ChangeFigColor(CFigure*pFig)
//{
	//for (int i = 0; i < FigCount; i++)
	//{
		//if (FigList[i] == pFig)
		//{
			//FigList[i]->ChngDrawClr();
			//FigList[i]->ChngFillClr();
		//}

	//}
//};

void ApplicationManager::addLastAction(Action* x) {
	if (actioncount == 5) {
		for (int i = 0;i < 4;i++) {
			actionlist[i] = actionlist[i + 1];
		}
		actionlist[4] = x;
		
	}
	if ((actioncount < 5)) {
		actionlist[actioncount] = x;
		actioncount++;
	}
}

Action* ApplicationManager::getLastAction() {
	return LastAction;
}
void ApplicationManager::redoAction(int& actioncount) {
	if (actionlist[actioncount]!=NULL)
	actionlist[actioncount]->Redo();
}
void ApplicationManager::undoAction(int &actioncount) {
	if (actionlist[actioncount-1] != NULL)
		actionlist[actioncount-1]->Undo();
		
}

int ApplicationManager::getActioncount() {
	return actioncount;
}
void ApplicationManager::setActioncount(int count) {
	actioncount = count;
}

CFigure* ApplicationManager::GetMoveFigure(CFigure* pFig)
{
	for (int i = 0; i < FigCount; i++) 
	{
		if (FigList[i] == pFig) 
		{
			return FigList[i];
		}
	}
}



////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->pointCheck(x, y) == true)
			return FigList[i];
	}
	return NULL;
}

	void ApplicationManager::DeSelectFigure()
	{
		for (int i = FigCount - 1; i >= 0; i--) 
		{
			FigList[i]->SetSelected(false);

		}
	}
	
	

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
void ApplicationManager::ClearAll()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
		FigCount = 0;
	}
	pOut->ClearDrawArea();

}
