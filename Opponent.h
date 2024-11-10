#pragma once

#include "Character.h"

class Opponent : public Character {
	//cause it to not close well, how cracy!!!!
public:
	int damage = 1;
	std::string idleAnimationName;
	std::string animationName;
	std::string debugname;
	ImageIndex imageindex;
	int type;

	/// <summary>
	/// Constructor with template passed in, and position
	/// </summary>
	/// <param name="temp">Template</param>
	/// <param name="x">Position X</param>
	/// <param name="y">Position Y</param>
	/// <param name="_debugname">Debug name</param>
	Opponent(Opponent& temp, int x, int y, std::string _debugname);
	/// <summary>
	/// Save Opponent
	/// </summary>
	/// <returns>string ouput</returns>
	std::string SaveOpponent();
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="x">Position X</param>
	/// <param name="y">Position Y</param>
	/// <param name="speed">Spped</param>
	/// <param name="_health">Health</param>
	/// <param name="_imageindex">Image index</param>
	/// <param name="_type">Opponent Type</param>
	Opponent(int speed, int _health, ImageIndex _imageindex, int _type);
	/// <summary>
	/// Returns the speed to follow in specified direction
	/// </summary>
	/// <param name="a">1d Coordinate of Oppponet</param>
	/// <param name="b">1d coordinate of Character to follow</param>
	/// <returns>Speed</returns>
	int followSpeed(int a, int b,float dt);
	/// <summary>
	/// Position to follow
	/// </summary>
	/// <param name="x">Position X</param>
	/// <param name="y">Position Y</param>
	void follow(int x, int y, float dt);
};