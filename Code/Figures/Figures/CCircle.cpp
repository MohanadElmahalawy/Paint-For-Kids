#include "CCircle.h"

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