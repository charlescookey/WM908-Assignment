#pragma once
#include "Camera.h"

class Bullet {
public:
	Plane bullet;
	float directionX = 0.f;
	float directionY = 0.f;

	float speed = 200.f;
	bool fired = false;

	int damage = 5;
	/// <summary>
	/// Constructor
	/// </summary>
	Bullet();
	/// <summary>
	/// Sets the width and height
	/// </summary>
	/// <param name="WH">Vec2 holding width and height</param>
	void setImageWidthAndHeight(Vec2 WH);
	/// <summary>
	/// Saves the Bullet Output
	/// </summary>
	/// <returns>string output</returns>
	std::string SaveBullet();
	/// <summary>
	/// Sets the properties of the bullet
	/// </summary>
	/// <param name="dirX">Direction X</param>
	/// <param name="dirY">Direction X</param>
	/// <param name="X">Position X</param>
	/// <param name="Y">Position Y</param>
	void setProperties(float dirX, float dirY, int X, int Y);
	/// <summary>
	/// Gets the direction to travel to from origin to destination
	/// </summary>
	/// <param name="pp">Origin Character</param>
	/// <param name="cam">Camera</param>
	/// <param name="target">Destination Character</param>
	void getDirection(Character& pp, Camera& cam, Character& target);
	/// <summary>
	/// Gets the direction to travel to from origin to Position XY
	/// </summary>
	/// <param name="pp">Origin Character</param>
	/// <param name="cam">Camera</param>
	/// <param name="TargetX">Position X</param>
	/// <param name="TargetY">Position Y</param>
	void getDirection(Character& pp, Camera& cam, int TargetX, int TargetY);
	/// <summary>
	/// Gets the direction to travel to from origin to Position XY
	/// </summary>
	/// <param name="pp">Origin Character</param>
	/// <param name="TargetX">Position X</param>
	/// <param name="TargetY">Position Y</param>
	void getDirection(Character& pp, int TargetX, int TargetY);
	/// <summary>
	/// Returns the nearest round number, if positive rounds up, if negative rounds down
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	int nearestRoundInt(float f);
	/// <summary>
	/// Updates the bullets X and Y, also checks if still in frame
	/// </summary>
	/// <param name="cam">Camara</param>
	void update(Camera& cam, float dt);
	/// <summary>
	/// Stops the bullet
	/// </summary>
	void stop();
	/// <summary>
	/// Draws the bullet to canvas
	/// </summary>
	/// <param name="canvas">Canavs to draw to</param>
	/// <param name="cam">Camera</param>
	void draw(GamesEngineeringBase::Window& canvas, Camera& cam);
};