#include "SaveGraph.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <string>
#include <fstream>
#include "..\GUI\UI_Info.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


SaveGraph::SaveGraph(ApplicationManager* pApp) :Action(pApp)
{}

void SaveGraph::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	fileName = pIn->GetSrting(pOut);
	pOut->PrintMessage("Graph Saved!");
}


void SaveGraph::Execute() {
	ReadActionParameters();
	ofstream outFile;
	outFile.open(fileName + ".txt", ios::out);
	outFile << pLoad->CtoS(pLoad->getCrntDrawColor(), 1) << " " << pLoad->CtoS(pLoad->getCrntFillColor(), 1) << "\n";
	pManager->SaveAll(outFile);

}