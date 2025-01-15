#include "Input.h"
#include "Output.h"
#include <cmath>

Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
	
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_Circ: return DRAW_Circ;
			case ITM_Tri: return DRAW_Tri;
			case ITM_Sq: return DRAW_Sq;
			case ITM_Hex: return DRAW_Hex;
			case ITM_Select: return DRAW_Select;
			case ITM_Delete: return DRAW_Delete;
			case ITM_DrawColor: return DRAW_DrawColor;
			case ITM_FillColor: return DRAW_FillColor;
			case ITM_Black: return DRAW_Black;
			case ITM_Yellow: return DRAW_Yellow;
			case ITM_Orange: return DRAW_Orange;
			case ITM_Red: return DRAW_Red;
			case ITM_Green: return DRAW_Green;
			case ITM_Blue: return DRAW_Blue;
			case ITM_Move: return DRAW_Move;
			case ITM_Undo: return DRAW_Undo;
			case ITM_Redo: return DRAW_Redo;
			case ITM_ClearAll: return DRAW_ClearAll;
			case ITM_StartRec: return DRAW_StartRec;
			case ITM_StopRec: return DRAW_StopRec;
			case ITM_PlayRec: return DRAW_PlayRec;
			case ITM_SaveGraph: return DRAW_SaveGraph;
			case ITM_LoadGraph: return DRAW_LoadGraph;
			case ITM_PlayMode: return DRAW_PlayMode;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_PH: return PLAY_PH;
			case ITM_ByType: return PLAY_ByType;
			case ITM_ByBoth: return PLAY_ByBoth;
			case ITM_ByFill: return PLAY_ByFill;
			case ITM_DrawMode: return PLAY_DrawMode;
			case ITM_EXIT2: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
			///TODO:
			//perform checks similar to Draw mode checks above
			//and return the correspoding action
			return DRAW_PlayMode;	//just for now. This should be updated
		}
	}

	//[2] User clicks on the drawing area
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
}
/////////////////////////////////
	
Input::~Input()
{
}
