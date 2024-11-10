#pragma once
#include <string>
#include "Vec2.h"
#include "GamesEngineeringBase.h"
/// <summary>
/// This hold index to load images from a text file
/// </summary>
enum ImageIndex { BASE = 0, INCREMENT = 1, Background = 2, CharacterCleric = 15, CharacterOrc = 25, CharacterWarrior = 35, CharcaterMinoutaur = 45, ObjectPickup = 55, ObjectBullet = 56 };


class Plane {
public:
	ImageIndex imageindex;
	std::string filename;
	int x, y;
	int width;
	int height;
	/// <summary>
	/// Constructor with specified position and imageIndex 
	/// </summary>
	/// <param name="_x">Position X</param>
	/// <param name="_y">Position Y</param>
	/// <param name="_imageindex">Image index</param>
	Plane(int _x, int _y, ImageIndex _imageindex);
	/// <summary>
	/// Default constructor
	/// </summary>
	Plane();
	/// <summary>
	/// Sets the width and height
	/// </summary>
	/// <param name="WH">Vec2 holding width and height</param>
	void setWidthAndHeight(Vec2 WH);
	/// <summary>
	/// Saves the plane output
	/// </summary>
	/// <returns>String output</returns>
	std::string SavePlane();

	/// <summary>
	/// Updates the position
	/// </summary>
	/// <param name="_x">X increment</param>
	/// <param name="_y">Y increment</param>
	void update(int _x, int _y);

	/// <summary>
	/// Updates the position but ensure it doesnt go outside the canvas
	/// </summary>
	/// <param name="canvas">Canavs bounds</param>
	/// <param name="_x">X increment</param>
	/// <param name="_y">Y increment</param>
	void update(GamesEngineeringBase::Window& canvas, int _x, int _y);

	/// <summary>
	/// Checks if collided with another plane
	/// </summary>
	/// <param name="other">Other plane to check</param>
	/// <returns>true if coliision occurs</returns>
	bool collision(Plane& other);
	/// <summary>
	/// Checks if collided with another plane but with X,Y and width and height 
	/// </summary>
	/// <param name="X">Other position X</param>
	/// <param name="Y">Other [position Y</param>
	/// <param name="OtherWidth">Other width</param>
	/// <param name="OtherHeight">Other height</param>
	/// <returns></returns>
	bool collision(int X, int Y, int OtherWidth, int OtherHeight);
	/// <summary>
	/// Returns distance between two Planes
	/// </summary>
	/// <param name="other">Other plane</param>
	/// <returns>distance</returns>
	float distance(Plane& other);
	/// <summary>
	/// Retursn distance from an XY position
	/// </summary>
	/// <param name="X">Other X</param>
	/// <param name="Y">Other Y</param>
	/// <returns>Distance</returns>
	float distance(int X, int Y);


};
