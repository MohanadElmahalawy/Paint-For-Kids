#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}
void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a hexagon on the screen	
	pOut->DrawHexagon(Center.x,Center.y, FigGfxInfo, Selected);
}