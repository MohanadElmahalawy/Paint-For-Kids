
#pragma once
#include "CFigure.h"
	class CTriangle : public CFigure
	{
	private:
		Point Corner1;
		Point Corner2;
		Point Corner3;
	public:

		CTriangle(Point Corner1, Point Corner2, Point Corner3, GfxInfo FigureGfxInfo);
		virtual void Draw(Output* pOut) const;
	};




