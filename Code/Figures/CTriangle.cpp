#include "CTriangle.h"
#include <string>
#include <fstream>

CTriangle :: CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

float CFigure::TriArea(int x0, int x1, int x2, int y0, int y1, int y2) //function that calculates area of triangle using its corner points
{
	float Areaoftriangle;
	Areaoftriangle = 0.5 * (x0 * (y1 - y2) +x1 * (y2 - y0) + x2 * (y0 - y1));
	if (Areaoftriangle < 0)
		Areaoftriangle = Areaoftriangle * -1;
	return Areaoftriangle;
}

bool CTriangle::pointCheck(int x, int y) 
{
	
	float A = TriArea(Corner1.x, Corner2.x, Corner3.x, Corner1.y, Corner2.y, Corner3.y);//Calculates Area of triangle using corner points
	float A0 = TriArea(x, Corner2.x, Corner3.x, y, Corner2.y, Corner3.y);// Calculates Area of first sub triangle in the triangle using the clicked points
	float A1 = TriArea(Corner1.x, x, Corner3.x, Corner1.y, y, Corner3.y);// Calculates Area of second sub triangle in the triangle using the clicked points
	float A2 = TriArea(Corner1.x, Corner2.x, x, Corner1.y, Corner2.y, y);// Calculates Area of third sub triangle in the triangle using the clicked points
	if (A == A0 + A1 + A2) //if the area of the triangle is equal to all the areas of the sub triangles then the point clicked is within the boundries of the shape
	{
		return true;
	}
	else
		return false;

}
void CTriangle::MoveFigure(int x, int y) 
{
	float Centeroftrix = ((Corner1.x + Corner2.x + Corner3.x) / 3.0);
	float Centeroftriy = ((Corner1.y + Corner2.y + Corner3.y) / 3.0);
	float differnecex = x - Centeroftrix;
	float differencey = y - Centeroftriy;
	Corner1.x = Corner1.x + differnecex; Corner1.y = Corner1.y + differencey;
	Corner2.x = Corner2.x + differnecex; Corner2.y = Corner2.y + differencey;
	Corner3.x = Corner3.x + differnecex; Corner3.y = Corner3.y + differencey;
	
}
void CTriangle::PrintInfo(Output* pOut)
{
	int ID = GetID();
	pOut->PrintMessage("Triangle ID: " + to_string(ID)+" Corner 1: "+to_string(Corner1.x)+","+to_string(Corner1.y)+" Corner 2: "+to_string(Corner3.x) + "," + to_string(Corner2.y) + " Corner 3: " + to_string(Corner3.x) + "," + to_string(Corner3.y));
}
CTriangle::CTriangle() {

}

void CTriangle::Load(ifstream& Infile) {

	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> SDrawColor >> SFillColor;
	DrawColor = pOut->StoC(SDrawColor, DrawColor);
	FillColor = pOut->StoC(SFillColor, FillColor);
	ChngFillClr(FillColor);
	ChngDrawClr(DrawColor);
	SetSelected(false);
}

void CTriangle::Save(ofstream& OutFile, int i) {
	OutFile << "TRIANGLE" << " " << i << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " " << pOut->CtoS(FigGfxInfo.DrawClr, 1) << " " << pOut->CtoS(FigGfxInfo.FillClr, FigGfxInfo.isFilled) << "\n";
}