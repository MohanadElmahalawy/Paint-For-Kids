#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected ; 	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetID(int ID);//Setter of ID
	int GetID();//Getter for ID


	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void MoveFigure(int x, int y)=0;  //moves figure to new location
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	virtual bool pointCheck(int x, int y) = 0;//Function that will be overriden in all figures to check if the passed points are in the figure or not
	float TriArea(int x0, int x1, int x2, int y0, int y1, int y2);//Calculates triangle area using three sub triangles
	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream& OutFile, int i) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file
	CFigure();
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif