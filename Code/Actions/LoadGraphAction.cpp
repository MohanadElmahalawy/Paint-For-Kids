#include "LoadGraphAction.h"
#include <fstream>
#include <string>
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "ClearAllAction.h"



LoadGraphAction::LoadGraphAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadGraphAction::ReadActionParameters() {
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	fileName = pIn->GetSrting(pOut);

}


void LoadGraphAction::Execute() {
	ReadActionParameters();
	pManager->ClearAll();
	ifstream inFile;
	inFile.open(fileName + ".txt", ios::in);
	if (inFile.is_open()) {
		inFile >> SDrawColor >> SFillColor >> countfigs;
		DrawColor = pOut->StoC(SDrawColor, DrawColor);
		FillColor = pOut->StoC(SFillColor, FillColor);
		pOut->SetCrntFillColor(FillColor);
		pOut->setCrntDrawColor(DrawColor);
		for (int i = 0;i < countfigs;i++) {
			{
				inFile >> type;
				if (type == "RECTANGLE")
					myFig = new CRectangle;
				else if (type == "SQUARE")
					myFig = new CSquare;
				else if (type == "HEXAGON")
					myFig = new CHexagon;
				else if (type == "TRIANGLE")
					myFig = new CTriangle;
				else if (type == "CIRCLE")
					myFig = new CCircle;

				myFig->Load(inFile);
				pManager->AddFigure(myFig);
			}
		}
	}
	else
		pOut->PrintMessage("File was not found");
	inFile.close();

}
