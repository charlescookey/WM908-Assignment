#pragma once

#include "GamesEngineeringBase.h"
#include <string>

/*

int N0[7][5] = { {0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };
int N1[7][5] = { {0,0,1,0,0},{0,1,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,1,1,0} };
int N2[7][5] = { {0,1,1,1,0},{1,0,0,0,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,1,1,1,1} };
int N3[7][5] = { {0,1,1,1,0},{1,0,0,0,1},{0,0,0,0,1},{0,1,1,1,0},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };
int N4[7][5] = { {0,0,1,1,0},{0,1,0,1,0},{1,0,0,1,0},{1,1,1,1,1},{0,0,0,1,0},{0,0,0,1,0},{0,0,0,1,0} };
int N5[7][5] = { {1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,0},{0,0,0,0,1},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };
int N6[7][5] = { {0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };
int N7[7][5] = { {1,1,1,1,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0} };
int N8[7][5] = { {0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };
int N9[7][5] = { {0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,1},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };

int NColon[7][5] = { {0,0,0,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0} };


int NC[7][5] = { {1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1} };
int NE[7][5] = { {1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1} };
int NF[7][5] = { {1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0} };
int NO[7][5] = { {0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };
int NP[7][5] = { {1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0} };
int NR[7][5] = { {1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0},{1,0,1,0,0},{1,0,0,1,0},{1,0,0,0,1} };
int NS[7][5] = { {0,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{0,1,1,1,0},{0,0,0,0,1},{0,0,0,0,1},{1,1,1,1,0} };


*/

/*
0 = .***.  
	*...*	   
	*...*
	*...*
	*...*
	*...*
	.***.
//Complete this later
*/


namespace NumberDraw {

	int getwidth();

	/// <summary>
	/// Helps check the string array if the specified row and col value contains a 1
	/// </summary>
	/// <param name="num"></param>
	/// <param name="row"></param>
	/// <param name="col"></param>
	/// <returns>Returns true is row,col is 1</returns>
	bool numPixelAt(int num, int row, int col);

	/// <summary>
	/// Draws a number
	/// </summary>
	/// <param name="number">The number to draw</param>
	/// <param name="canvas">The canvas to draw to</param>
	/// <param name="X">The X position to draw to</param>
	/// <param name="Y">The Y postion to draw to</param>
	/// <param name="R">Red component</param>
	/// <param name="G">Green Component</param>
	/// <param name="B">Blue Component</param>
	void drawNumber(int number, GamesEngineeringBase::Window& canvas, int X, int Y, int R, int G, int  B);
	/// <summary>
	/// Draws a number at a specified scale
	/// </summary>
	/// <param name="scale">The scale to multiply by</param>
	/// <param name="number">The number to draw</param>
	/// <param name="canvas">The canvas to draw to</param>
	/// <param name="X">The X position to draw to</param>
	/// <param name="Y">The Y postion to draw to</param>
	/// <param name="R">Red component</param>
	/// <param name="G">Green Component</param>
	/// <param name="B">Blue Component</param>
	void drawNumberScaled(int scale, int number, GamesEngineeringBase::Window& canvas, int X, int Y, int R, int G, int  B);
}