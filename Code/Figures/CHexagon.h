#pragma once
#include "CFigure.h"
class CHexagon :
    public CFigure
{
private:
	Point Center;
	Output* pOut;
	color DrawColor, FillColor;
	string SDrawColor, SFillColor;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool pointCheck(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void MoveFigure(int x, int y);
	void Load(ifstream& Infile);
	void Save(ofstream& OutFile, int i);
	CHexagon();
};

