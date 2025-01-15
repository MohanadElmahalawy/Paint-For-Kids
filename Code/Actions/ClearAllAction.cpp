#include "ClearAllAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAllAction::ReadActionParameters() {
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}
void ClearAllAction::Execute() {

	ReadActionParameters();
	pManager->ClearAll();

}