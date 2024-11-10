#pragma once
#include "Camera.h"

class Pickup {
public:
	Plane pickup;
	bool taken = false;
	int type;
	/// <summary>
	/// Default Constructor
	/// </summary>
	Pickup();
	/// <summary>
	/// Constructor with Position and type
	/// </summary>
	/// <param name="_type">Pickup Type</param>
	/// <param name="X">Position X</param>
	/// <param name="Y">Position Y</param>
	Pickup(int _type, int X, int Y);
	/// <summary>
	/// Sets the width and height
	/// </summary>
	/// <param name="WH">Vec2 holding width and height</param>
	void setImageWidthAndHeight(Vec2 WH);
	/// <summary>
	/// Saves the bullet
	/// </summary>
	/// <returns>File ouput</returns>
	std::string SaveBullet();
	/// <summary>
	/// Check if in camera frame
	/// </summary>
	/// <param name="cam">Camera</param>
	/// <returns>ture if inside</returns>
	bool inCameraFrame(Camera& cam);
	/// <summary>
	/// Draws Pickup to canvas
	/// </summary>
	/// <param name="canvas">canvas to draw to</param>
	/// <param name="cam">Camera</param>
	void draw(GamesEngineeringBase::Window& canvas, Camera& cam);

};