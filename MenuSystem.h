#pragma once
#include "DrawHelp.h"

class MenuSystem {
	Vec2 positions[4] = { Vec2(410,216) , Vec2(410,359) , Vec2(410,496) ,  Vec2(410,640) };
	int size = 4;
	Vec2 pos;
	int ButtonWidth = 240;
	int ButtonHeight = 80;
	Rect rect;

	int index = 0;
	bool stillPressing = false;
public:
	bool buttonPress = false;
	/// <summary>
	/// Returns the Current Index of the Menu
	/// </summary>
	/// <returnsIndex</returns>
	int getIndex();
	/// <summary>
	/// Constructor
	/// </summary>
	MenuSystem();
	/// <summary>
	/// Draws the whitr border around the MEnu Items
	/// </summary>
	/// <param name="canvas">canvas to draw to</param>
	void draw(GamesEngineeringBase::Window& canvas);
	/// <summary>
	/// Sets the new position of the rectangle
	/// </summary>
	void resetRect();

	/// <summary>
	/// Moves the rectangle down
	/// </summary>
	void moveDown();

	/// <summary>
	/// Moves the rectangle up
	/// </summary> 
	void moveUp();

};

