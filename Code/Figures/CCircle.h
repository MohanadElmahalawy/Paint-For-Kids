#pragma once
#include "CFigure.h"
class CCircle :
    public CFigure
{
private:
	Point Center;
	Point Circumf;
	Output* pOut;
	CFigure* LoadedFig;
	color DrawColor, FillColor;
	string SDrawColor, SFillColor;
	int ID;
public:

	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool pointCheck(int x, int y);
	virtual void PrintInfo(Output* pOut);
	float Circrad(int x0, int y0, int x1, int y1);//Calculates radius of the circle
	virtual void MoveFigure(int x, int y);
	void Load(ifstream& Infile);
	void Save(ofstream& OutFile, int i);
	CCircle();

};


