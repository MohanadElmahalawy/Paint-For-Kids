#include "CRectangle.h"
#include <string>
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::pointCheck(int x, int y)//checks if the point clicked is within boundries if the first corner is bottom left the checks if it is within boundries if the first corner is bottom right
{
	if (x<Corner1.x && x>Corner2.x && y<Corner1.y && y>Corner2.y || x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y)
	{
		return true;
	}
	else
		return false;
}

void CRectangle::MoveFigure(int x, int y)
{
	float Centerx = ((Corner1.x + Corner2.x) / 2.0);
	float Centery = ((Corner1.y + Corner2.y) / 2.0);
	float differencex = x-Centerx;
	float differnecey = y-Centery;
	Corner1.x = Corner1.x + differencex; Corner2.x = Corner2.x + differencex;
	Corner1.y = Corner1.y + differnecey; Corner2.y = Corner2.y + differnecey;

}
void CRectangle::PrintInfo(Output* pOut)
{
	int ID = GetID();
	pOut->PrintMessage("Rectangle ID: " +to_string(ID)+" First Corner: "+to_string(Corner1.x)+","+to_string(Corner1.y)+" Second Corner: " + to_string(Corner2.x) + "," + to_string(Corner2.y));
}
CRectangle::CRectangle() {


}
void CRectangle::Load(ifstream& Infile) {
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> SDrawColor >> SFillColor;
	DrawColor = pOut->StoC(SDrawColor, DrawColor);
	FillColor = pOut->StoC(SFillColor, FillColor);
	ChngFillClr(FillColor);
	ChngDrawClr(DrawColor);
	SetSelected(false);
}
void CRectangle::Save(ofstream& OutFile, int i) {
	OutFile << "RECTANGLE" << " " << i << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << pOut->CtoS(FigGfxInfo.DrawClr, 1) << " " << pOut->CtoS(FigGfxInfo.FillClr, FigGfxInfo.isFilled) << "\n";
}
