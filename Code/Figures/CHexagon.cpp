#include "CHexagon.h"
#include <cmath>
#include <string>
#include <fstream>

CHexagon::CHexagon(Point P0, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P0;
}
void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a hexagon on the screen	
	pOut->DrawHexagon(Center.x,Center.y, FigGfxInfo, Selected);
}
bool CHexagon::pointCheck(int x, int y)
{
	Output* Pout=NULL;
	int arrx[6];
	int arry[6];
	int n = 100;
	Pout->CalcHexagon(Center.x, Center.y, arrx, arry, n);
	float B1 = TriArea(Center.x, arrx[5], arrx[4], Center.y, arry[5], arry[4]);
	float B2 = TriArea(Center.x, arrx[4], arrx[3], Center.y, arry[4], arry[3]);
	float B3 = TriArea(Center.x, arrx[3], arrx[2], Center.y, arry[3], arry[2]);
	float B4 = TriArea(Center.x, arrx[2], arrx[1], Center.y, arry[2], arry[1]);
	float B5 = TriArea(Center.x, arrx[1], arrx[0], Center.y, arry[1], arry[0]);
	float B6 = TriArea(Center.x, arrx[0], arrx[5], Center.y, arry[0], arry[5]);
	float AreaHex = B1 + B2 + B3 + B4 + B5 + B6;
	float A1 = TriArea(x, arrx[5], arrx[4], y, arry[5], arry[4]);
	float A2 = TriArea(x, arrx[4], arrx[3], y, arry[4], arry[3]);
	float A3 = TriArea(x, arrx[3], arrx[2], y, arry[3], arry[2]);
	float A4 = TriArea(x, arrx[2], arrx[1], y, arry[2], arry[1]);
	float A5 = TriArea(x, arrx[1], arrx[0], y, arry[1], arry[0]);
    float A6 = TriArea(x, arrx[0], arrx[5], y, arry[0], arry[5]);
	float TotalArea = A1 + A2 + A3 + A4 + A5 + A6;
	if (AreaHex == TotalArea) 
	{
		return true;
	}
	else
		return false;


}

void CHexagon::MoveFigure(int x, int y)
{
	float diffx = x - Center.x;
	float diffy = y - Center.y;
	Center.x = Center.x + diffx;
	Center.y = Center.y + diffy;
}
void CHexagon::PrintInfo(Output* pOut)
{
	int ID = GetID();
	pOut->PrintMessage("Hexagon ID: " + to_string(ID) + " Center: " + to_string(Center.x) + "," + to_string(Center.y));
}

void CHexagon::Load(ifstream& Infile) {

	Infile >> ID >> Center.x >> Center.y >> SDrawColor >> SFillColor;
	DrawColor = pOut->StoC(SDrawColor, DrawColor);
	FillColor = pOut->StoC(SFillColor, FillColor);
	ChngFillClr(FillColor);
	ChngDrawClr(DrawColor);
	SetSelected(false);
}
CHexagon::CHexagon() {


}
void CHexagon::Save(ofstream& OutFile, int i) {

	OutFile << "HEXAGON" << " " << i << " " << Center.x << " " << Center.y << " " << pOut->CtoS(FigGfxInfo.DrawClr, 1) << " " << pOut->CtoS(FigGfxInfo.FillClr, FigGfxInfo.isFilled) << "\n";
}