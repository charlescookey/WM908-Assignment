#pragma once

#include <string>
#include "GamesEngineeringBase.h"

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
	/// <summary>
	/// A string containing the pixel representation of number shown above
	/// </summary>
	std::string numbers[11] = { "01110100011000110001100011000101110" , "00100011000010000100001000010001110" ,
		"01110100010000100010001000100011111" ,  "01110100010000101110000011000101110",  "00110010101001011111000100001000010",  "11111100001111000001000011000101110",
		"01110100011000011110100011000101110", "11111000010001000100001000010000100", "01110100011000101110100011000101110",  "01110100011000101111000011000101110" ,
		 "00000000000010000000001000000000000"
	};

	int height = 7;
	int width = 5;

	/// <summary>
	/// Helps check the string array if the specified row and col value contains a 1
	/// </summary>
	/// <param name="num"></param>
	/// <param name="row"></param>
	/// <param name="col"></param>
	/// <returns>Returns true is row,col is 1</returns>
	bool numPixelAt(int num, int row, int col) {
		//helps find the position of the 2d position in teh 1d array
		int index = (row * width) + col;
		return numbers[num][index] == '1';
	}

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
	void drawNumber(int number, GamesEngineeringBase::Window& canvas, int X, int Y, int R, int G, int  B) {
		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				if (numPixelAt(number, j, i))
					canvas.draw(X + i, Y + j, R, G, B);
			}
		}
	}
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
	void drawNumberScaled(int scale, int number, GamesEngineeringBase::Window& canvas, int X, int Y, int R, int G, int  B) {
		for (unsigned int i = 0; i < width; i++) {
			for (int si = 0; si < scale; si++)
				for (unsigned int j = 0; j < height; j++) {
					for (int sj = 0; sj < scale; sj++)
						if (numPixelAt(number, j, i))
							canvas.draw(X + (i * scale) + si, Y + (j * scale) + sj, R, G, B);
				}
		}
	}
}