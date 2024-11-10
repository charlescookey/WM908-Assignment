#pragma once
#include "Camera.h"

class TimeDisplay {
	float _seconds = 0.f;
	int seconds = 0;
	int minutes = 0;
	int scale = 2;

	int X = 0;
	int Y = 0;
public:

	/// <summary>
	/// COnstructor
	/// </summary>
	TimeDisplay();
	/// <summary>
	/// Constructor that takes XY position and Scale
	/// </summary>
	/// <param name="_x">Position X</param>
	/// <param name="_y">Position Y</param>
	/// <param name="_scale">Scale</param>
	TimeDisplay(int _x, int _y, int _scale);

	/// <summary>
	/// Update the seconds
	/// </summary>
	/// <param name="dt">Time since last update</param>
	void update(float dt);
	/// <summary>
	/// Draws the Timer to the Canvas, add the Camera X
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="cam">Camera</param>
	void draw(GamesEngineeringBase::Window& canvas, Camera& cam);
	/// <summary>
	/// Draws the Timer to the Canvas
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	void draw(GamesEngineeringBase::Window& canvas);

};


