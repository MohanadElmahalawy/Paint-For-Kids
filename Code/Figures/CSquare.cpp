#include "CSquare.h"
#include <string>
#include <fstream>
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}
void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
bool CSquare::pointCheck(int x, int y)
{
	if ((x<Center.x - 75 || x>Center.x + 75) || (y<Center.y-75 || y>Center.y+75))
	{
		return false;
	}else
		return true;

}

void CSquare::MoveFigure(int x, int y)
{
	int diffx = x - Center.x;
	int diffy = y - Center.y;
	Center.x = Center.x + diffx;
	Center.y = Center.y + diffy;
}
void CSquare::PrintInfo(Output* pOut)
{
	int ID = GetID();
	pOut->PrintMessage("Square ID: " +to_string(ID)+" Center: "+to_string(Center.x)+","+to_string(Center.y));
}
CSquare::CSquare() {

}

void CSquare::Load(ifstream& Infile) {

	Infile >> ID >> Center.x >> Center.y >> SDrawColor >> SFillColor;
	DrawColor = pOut->StoC(SDrawColor, DrawColor);
	FillColor = pOut->StoC(SFillColor, FillColor);
	ChngFillClr(FillColor);
	ChngDrawClr(DrawColor);
	SetSelected(false);
}
void CSquare::Save(ofstream& OutFile, int i) {
	OutFile << "SQUARE" << " " << i << " " << Center.x << " " << Center.y << " " << pOut->CtoS(FigGfxInfo.DrawClr, 1) << " " << pOut->CtoS(FigGfxInfo.FillClr, FigGfxInfo.isFilled) << "\n";
}