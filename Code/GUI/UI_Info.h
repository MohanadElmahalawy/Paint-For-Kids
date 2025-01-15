#ifndef UI_INFO_H
#define UI_INFO_H
#include <cmath>
#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_Circ,
	ITM_Tri,
	ITM_Sq,
	ITM_Hex,
	ITM_Select,
	ITM_Delete,
	ITM_DrawColor,
	ITM_FillColor,
	ITM_Black,
	ITM_Yellow,
	ITM_Orange,
	ITM_Red,
	ITM_Green,
	ITM_Blue,
	ITM_Move,
	ITM_Undo,
	ITM_Redo,
	ITM_ClearAll,
	ITM_StartRec,
	ITM_StopRec,
	ITM_PlayRec,
	ITM_SaveGraph,
	ITM_LoadGraph,
	ITM_PlayMode,
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_PH,
	ITM_ByType,
	ITM_ByBoth,
	ITM_ByFill,
	ITM_DrawMode,
	ITM_EXIT2,

	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};






__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool MakeFilled;         //

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif