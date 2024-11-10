#pragma once

#include "ImageIndex.h"
#include "Vec2.h"

class Tile {
public:
	//GamesEngineeringBase::Image sprite;
	ImageIndex imageindex;
	int x, y;
	int width;
	int height;
	bool canPass = true;

	/// <summary>
	/// Constructor with specified position and imageIndex and if Terrain Passable
	/// </summary>
	/// <param name="_x">Position X</param>
	/// <param name="_y">Position Y</param>
	/// <param name="_imageindex">Image index</param>
	/// <param name="_canPass">if can pass</param>
	Tile(int _x, int _y, ImageIndex _imageindex, bool _canPass);
	/// <summary>
	/// Default constructor
	/// </summary>
	Tile();
	/// <summary>
	/// Sets the width and height
	/// </summary>
	/// <param name="WH">Vec2 holding width and height</param>
	void setWidthAndHeight(Vec2 WH);
	/// <summary>
	/// Returns if Terrain is Traversable
	/// </summary>
	/// <returns>true if player can travers</returns>
	bool ifCanPass();
};
