#include "CCircle.h"
#include <cmath>
#include <string>
#include <fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Circumf = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a circle on the screen	
	pOut->DrawCircle(Center, Circumf, FigGfxInfo, Selected);
}
float CCircle::Circrad(int x0, int y0, int x1, int y1) //calculates radius of the circle
{
	float xr = x1 - x0;
	float yr = y1 - y0;
	float radius = pow(xr,2) + pow(yr,2);
	return radius;
}
bool CCircle::pointCheck(int x, int y) //checks if the point is inside the circle
{
	float rad = Circrad(Center.x, Center.y, Circumf.x, Circumf.y);
	float radcheck = Circrad(Center.x, Center.y, x, y);
	if (radcheck <= rad) 
	{
		return true;
	}
	else
		return false;

}

void CCircle::MoveFigure(int x, int y) 
{
	int diffx = x - Center.x;
	int diffy = y - Center.y;
	Center.x = Center.x+diffx; Circumf.x = Circumf.x + diffx;
	Center.y = Center.y + diffy; Circumf.y = Circumf.y+diffy;

}
void CCircle::PrintInfo(Output* pOut)
{
	int ID = GetID();
	pOut->PrintMessage("Circle ID: " +to_string(ID)+" Center: "+to_string(Center.x)+","+to_string(Center.y) + " Radius: "+to_string((int)Circrad(Center.x, Center.y, Circumf.x, Circumf.y)));
}

void CCircle::Load(ifstream& Infile) {

	Infile >> ID >> Center.x >> Center.y >> Circumf.x >> Circumf.y >> SDrawColor >> SFillColor;
	DrawColor = pOut->StoC(SDrawColor, DrawColor);
	FillColor = pOut->StoC(SFillColor, FillColor);
	ChngFillClr(FillColor);
	ChngDrawClr(DrawColor);
	SetSelected(false);
	

}
void CCircle::Save(ofstream& OutFile, int i) {
	OutFile << "CIRCLE" << " " << i << " " << Center.x << " " << Center.y << " " << Circumf.x << " " << Circumf.y << " " << pOut->CtoS(FigGfxInfo.DrawClr, 1) << " " << pOut->CtoS(FigGfxInfo.FillClr, FigGfxInfo.isFilled) << "\n";

}
CCircle::CCircle() {
}
