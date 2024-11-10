#include "NumberDraw.h"


namespace NumberDraw {
	/// <summary>
	/// A string containing the pixel representation of number shown in NumberDraw.h
	/// </summary>
	std::string numbers[11] = { "01110100011000110001100011000101110" , "00100011000010000100001000010001110" ,
		"01110100010000100010001000100011111" ,  "01110100010000101110000011000101110",  "00110010101001011111000100001000010",  "11111100001111000001000011000101110",
		"01110100011000011110100011000101110", "11111000010001000100001000010000100", "01110100011000101110100011000101110",  "01110100011000101111000011000101110" ,
		 "00000000000010000000001000000000000"
	};

	int height = 7;
	int width = 5;

	bool numPixelAt(int num, int row, int col) {
		//helps find the position of the 2d position in teh 1d array
		int index = (row * width) + col;
		return numbers[num][index] == '1';
	}

	void drawNumber(int number, GamesEngineeringBase::Window& canvas, int X, int Y, int R, int G, int  B) {
		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				if (numPixelAt(number, j, i))
					canvas.draw(X + i, Y + j, R, G, B);
			}
		}
	}

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

	int getwidth() {
		return width;
	};

}