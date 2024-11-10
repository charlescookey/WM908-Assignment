#pragma once
#include "Gallery.h"

class Character {
public:
	Plane main;
	bool right = true;
	int frames = 0;
	int movespeed = 0;
	int maxHealth = 0;
	int currHealth = 0;
	bool alive = true;
	int imageOffset = 0;

	/// <summary>
	/// Called when Charater Dies
	/// </summary>
	void Death();
	/// <summary>
	/// to check if character is alive
	/// </summary>
	/// <returns>true if alive</returns>
	bool isAlive();
	/// <summary>
	/// Sets the width and height
	/// </summary>
	/// <param name="WH">Vec2 holding width and height</param>
	void setImageWidthAndHeight(Vec2 WH);

	/// <summary>
	/// Reduced the healkth by specified damage
	/// </summary>
	/// <param name="damage">Damage to reduce by</param>
	void takeDamage(int damage);
}
	}
	/// <summary>
	/// Updates position by X and Y
	/// </summary>
	/// <param name="x">X increment</param>
	/// <param name="y">Y increment</param>
	void update(int x, int y);
	/// <summary>
	/// Draw the Character to Canavs
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="gallery">Gallety to get Image from</param>
	void draw(GamesEngineeringBase::Window& canvas, Gallery& gallery);
	
	/// <summary>
	/// Draws the character at a specified position
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="gallery">Gallety to get Image from</param>
	/// <param name="x">Position X</param>
	/// <param name="y">Position Y</param>
	void drawAt(GamesEngineeringBase::Window& canvas, Gallery& gallery, int x, int y);
	/// <summary>
	/// Draws the Health Bat
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="X">Position X</param>
	/// <param name="Y">Position Y</param>
	void drawHealth(GamesEngineeringBase::Window& canvas, int X, int Y);