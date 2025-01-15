#ifndef DEFS_H
#define DEFS_H
#include <cmath>
#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,
	DRAW_Circ,
	DRAW_Tri,
	DRAW_Sq,
	DRAW_Hex,
	DRAW_Select,
	DRAW_Delete,
	DRAW_DrawColor,
	DRAW_ChangeColor,
	DRAW_FillColor,
	DRAW_Black,
	DRAW_Yellow,
	DRAW_Orange,
	DRAW_Red,
	DRAW_Green,
	DRAW_Blue,
	DRAW_Move,
	DRAW_Undo,
	DRAW_Redo,
	DRAW_ClearAll,
	DRAW_StartRec,
	DRAW_StopRec,
	DRAW_PlayRec,
	DRAW_SaveGraph,
	DRAW_LoadGraph,
	DRAW_PlayMode,

	PLAY_PH,
	PLAY_ByType,
	PLAY_ByBoth,
	PLAY_ByFill,
	PLAY_DrawMode,
	//Draw Rectangle
	EXIT,			//Exit
	//Switch interface to Draw mode
	//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,
	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif