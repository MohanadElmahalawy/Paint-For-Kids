#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Output* pOut;
	color DrawColor, FillColor;
	string SDrawColor, SFillColor;
public:
	
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool pointCheck(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void MoveFigure(int x, int y);
	void Save(ofstream& savedest, int i);
	void Load(ifstream& Infile);
	CRectangle();
};

#endif