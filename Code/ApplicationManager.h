#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	int actioncount;
	Action* actionlist[5];
	Action* LastAction;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	//Selected Figure Related Functions
	void SetSelectedFig(CFigure* SelectedFig);//Selected Figure setter
	CFigure *GetSelectedFig();//Selected Figure Getter
    void DeSelectFigure();// De-selects the selected figure
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it

	// -- Figures Management Functions
	void SaveAll(ofstream& fileName);
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteFigure(CFigure* pFig);//Deletes Selected figure
	CFigure* GetMoveFigure(CFigure* pFig);//moves figure to the specified location by the user
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void ClearAll();
	void addLastAction(Action* x);
	Action* getLastAction();
	void undoAction(int &actioncount);
	void redoAction(int& actioncount);
	void GetFigureAction(Action* x);
	int getActioncount();
	void setActioncount(int count);
};

#endif