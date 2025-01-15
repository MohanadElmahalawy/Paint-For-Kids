
#pragma once
#include "CFigure.h"
	class CTriangle : public CFigure
	{
	private:
		Point Corner1;
		Point Corner2;
		Point Corner3;
		Output* pOut;
		color DrawColor, FillColor;
		string SDrawColor, SFillColor;
	public:

		CTriangle(Point Corner1, Point Corner2, Point Corner3, GfxInfo FigureGfxInfo);
		virtual void Draw(Output* pOut) const;
		virtual bool pointCheck(int x, int y);
		virtual void PrintInfo(Output* pOut);
		virtual void MoveFigure(int x, int y);
		void Load(ifstream& Infile);
		void Save(ofstream& OutFile, int i);
		CTriangle();
	};



