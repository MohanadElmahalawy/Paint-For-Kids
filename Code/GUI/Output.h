#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include <cmath>

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSquare(Point P1, GfxInfo Squaregfxinfo, bool selected) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected) const;
	void DrawHexagon(int x,int y, GfxInfo RectGfxInfo, bool selected) ;
	void CalcHexagon(int x, int y, int* arrx, int* arry,int n) const;//calculates hexagon points
	void DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;//Print a message on Status bar
	void PrintNext(string msg, int x) const;	// to print another message without deleting previous

	color getCrntDrawColor() const;	//get current drwawing color
	void setCrntDrawColor(color x);
	color getCrntFillColor() const;	//get current filling color
	void SetCrntFillColor(color newcolor){};
	int getCrntPenWidth() const;		//get current pen width
	void SetFilled(bool setnew);
	color StoC(string x, color& clr);
	string CtoS(color x, bool IsFilled);

	
	~Output();
};

#endif