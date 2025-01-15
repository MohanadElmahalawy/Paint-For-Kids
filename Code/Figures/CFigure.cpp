#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
void CFigure::SetID(int Id) 
{
	ID = Id;
}
int CFigure::GetID()
{
	return ID;
}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
float TriArea(int x0, int x1, int x2, int y0, int y1, int y2) 
{
	float Areaoftriangle;
	Areaoftriangle = 0.5 * (x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1));
	return Areaoftriangle;
}
CFigure::CFigure() {

}