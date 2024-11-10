#pragma once
#include "Plane.h"
#include "Vec2.h"
#include "GamesEngineeringBase.h"

#include <fstream>

class Gallery {
public:
	GamesEngineeringBase::Image images[58];

	/// <summary>
	/// Default Constructor
	/// </summary>
	Gallery();

	/// <summary>
	/// Loads all the images from an input fule
	/// </summary>
	/// <param name="filename">File to load from</param>
	void loadImages(std::string filename);

	/// <summary>
	/// Sets the width and height
	/// </summary>
	/// <param name="WH">Vec2 holding width and height</param>
	Vec2 getImageWidthAndHeight(ImageIndex imageindex);

	/// <summary>
	/// Draws a plane to the canvas
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="imageindex">Index of image to draw</param>
	/// <param name="offset">offset to draw</param>
	/// <param name="plane">Plane to draw</param>
	void draw(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, Plane& plane);
	/// <summary>
	/// Draws a plane backwards
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="imageindex">Index of image to draw</param>
	/// <param name="offset">offset to draw</param>
	/// <param name="plane">Plane to draw</param>
	void backDraw(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, Plane& plane);
	/// <summary>
	/// Draws an image at a specified X and Y
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="imageindex">Index of image to draw</param>
	/// <param name="offset">offset to draw</param>
	/// <param name="X"></param>
	/// <param name="Y"></param>
	void backDrawAt(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, int X, int Y);
	/// <summary>
	/// Draws an image at a specified X and Y backwards
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="imageindex">Index of image to draw</param>
	/// <param name="offset">offset to draw</param>
	/// <param name="X"></param>
	/// <param name="Y"></param>
	void drawAt(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, int X, int Y);
};