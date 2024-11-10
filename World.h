#pragma once
#include <fstream>
#include <string>
#include <sstream>

#include "Tile.h"

class World {
	Tile** background{ nullptr };
public:
	int rows = 100;
	int cols = 100;

	/// <summary>
	/// Default Constructor
	/// </summary>
	World() {
	}

	int** arr;
	/// <summary>
	/// Default destructor
	/// </summary>
	~World();
	/// <summary>
	/// Loads a file to draw entire world
	/// </summary>
	/// <param name="filename">Input filename</param>
	void load(std::string filename);

	/// <summary>
	/// checks if the tile at a position can be traversed
	/// </summary>
	/// <param name="x">Position X</param>
	/// <param name="y">Position Y</param>
	/// <returns>true if can be traversed</returns>
	bool passable(int x, int y);
	/// <summary>
	/// returns the tile at a soecified position
	/// </summary>
	/// <param name="X">Position X</param>
	/// <param name="Y">Position Y</param>
	/// <returns>if can be traversed</returns>
	Tile& at(unsigned int  X, unsigned int Y);

};