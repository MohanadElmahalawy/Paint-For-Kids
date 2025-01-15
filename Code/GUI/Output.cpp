#include "Output.h"
#include <cmath>


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1350;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearDrawArea();
	UI.StatusBarColor = TURQUOISE;
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;
	UI.MsgColor = RED;
	pWind->DrawRectangle(0, 0, UI.width, UI.height);
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_Circ] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_Tri] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_Sq] = "images\\MenuItems\\Menu_Sq.jpg";
	MenuItemImages[ITM_Hex] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_Select] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_Delete] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_DrawColor] = "images\\MenuItems\\Menu_DrawColor.jpg";
	MenuItemImages[ITM_FillColor] = "images\\MenuItems\\Menu_FillColor.jpg";
	MenuItemImages[ITM_Black] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_Yellow] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_Orange] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_Red] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_Green] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_Blue] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_Move] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_Undo] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_Redo] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_ClearAll] = "images\\MenuItems\\Menu_ClearAll.jpg";
	MenuItemImages[ITM_StartRec] = "images\\MenuItems\\Menu_StartRec.jpg";
	MenuItemImages[ITM_StopRec] = "images\\MenuItems\\Menu_StopRec.jpg";
	MenuItemImages[ITM_PlayRec] = "images\\MenuItems\\Menu_PlayRec.jpg";
	MenuItemImages[ITM_SaveGraph] = "images\\MenuItems\\Menu_SaveGraph.jpg";
	MenuItemImages[ITM_LoadGraph] = "images\\MenuItems\\Menu_LoadGraph.jpg";
	MenuItemImages[ITM_PlayMode] = "images\\MenuItems\\Menu_PlayMode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.StatusBarColor = LIMEGREEN;
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;
	UI.MsgColor = RED;
	ClearDrawArea();
	pWind->DrawRectangle(0, 0, UI.width, UI.height);
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PH] = "images\\MenuItems\\Menu_PH.jpg";
	MenuItemImages[ITM_ByType] = "images\\MenuItems\\Menu_ByType.jpg";
	MenuItemImages[ITM_ByBoth] = "images\\MenuItems\\Menu_ByBoth.jpg";
	MenuItemImages[ITM_ByFill] = "images\\MenuItems\\Menu_ByFill.jpg";
	MenuItemImages[ITM_DrawMode] = "images\\MenuItems\\Menu_DrawMode.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}

void Output::PrintNext(string msg,int x) const	//Prints a second message without deleting first
{
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10+x, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
void Output::setCrntDrawColor(color x) {
	UI.DrawColor = x;
}

//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
void SetCrntFillColor(color newcolor)   //set new filling color for all the preceding shapes
{
	UI.FillColor = newcolor;
	
}
void SetFilled(bool setnew)
{
	UI.MakeFilled = setnew;
}
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	RectGfxInfo.isFilled = UI.MakeFilled;
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
 
void Output::DrawSquare(Point P1, GfxInfo Squaregfxinfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = Squaregfxinfo.DrawClr;
	Squaregfxinfo.isFilled = UI.MakeFilled;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (Squaregfxinfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(Squaregfxinfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(P1.x - 75, P1.y - 75, P1.x + 75, P1.y + 75, style);
}
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrigGfxInfo.DrawClr;
	TrigGfxInfo.isFilled = UI.MakeFilled;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TrigGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrigGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawCircle(Point P1,Point P2,GfxInfo RectGfxInfo,bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;
	RectGfxInfo.isFilled = UI.MakeFilled;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int r;
	r = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

	pWind->DrawCircle(P1.x, P1.y, r, style);
	

}

string Output::CtoS(color x, bool IsFilled) {
	if (IsFilled)
	{
		if (x == RED)
			return "RED";
		else if (x == GREEN)
			return "GREEN";
		else if (x == YELLOW)
			return "YELLOW";
		else if (x == BLACK)
			return "BLACK";
		else if (x == ORANGE)
			return "ORANGE";
		else if (x == BLUE)
			return "BLUE";
	}
	else return "NO_FILL";
}


color Output::StoC(string x, color& clr) {
	if (x == "RED")
		return RED;
	else if (x == "GREEN")
		return GREEN;
	else if (x == "YELLOW")
		return YELLOW;
	else if (x == "BLACK")
		return BLACK;
	else if (x == "ORANGE")
		return ORANGE;
	else if (x == "BLUE")
		return BLUE;
	else if (x == "NO_FILL")
		return BLUE;

}

 void  Output::CalcHexagon(int x, int y,int* arrx, int* arry, int n) const
{
	
	arrx[0] = x - n;
	arrx[1] = x - (n / 2);
	arrx[2] = x + (n / 2);
	arrx[3] = x + n;
	arrx[4] = arrx[2];
	arrx[5] = arrx[1];


	arry[0] = y;
	arry[1] = y - 0.7 * n;
	arry[2] = arry[1];
	arry[3] = arry[0];
	arry[4] = y + 0.7 * n;
	arry[5] = arry[4];

}

void Output::DrawHexagon(int x,int y,GfxInfo RectGfxInfo, bool selected)  {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;
	RectGfxInfo.isFilled = UI.MakeFilled;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	
	int n = 100;
	int arrx[6];
	int arry[6];
	for (int i = 0; i < 6; i++) 
	{
		arrx[i] = 0;
		arry[i] = 0;
	}
	
	CalcHexagon(x, y, arrx, arry, n);
	pWind->DrawPolygon(arrx, arry, 6, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

