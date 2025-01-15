#pragma once
#include "CFigure.h"
class CSquare :  public CFigure
{
private:
	Point Center;
	Output* pOut;
	color DrawColor, FillColor;
	string SDrawColor, SFillColor;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool pointCheck(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void MoveFigure(int x, int y);
	CSquare();
	void Load(ifstream& Infile);
	void Save(ofstream& OutFile, int i);
};


