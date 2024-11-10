#pragma once
#include "Pickup.h"
#include "GameArray.h"
#include "Hero.h"

class PickupManager {
	float timeElapsed = 0.f;
	GameArray<Pickup*> pickups;
public:
	/// <summary>
	/// Constructor
	/// </summary>
	PickupManager();
	//Destructor
	~PickupManager();
	/// <summary>
	/// Add to Manager
	/// </summary>
	/// <param name="b">Pickup</param>
	void add(Pickup* b);
	/// <summary>
	/// Save to Output
	/// </summary>
	/// <returns>string output</returns>
	std::string SavePickups();
	/// <summary>
	/// Draw all pickups
	/// </summary>
	/// <param name="canvas">Canvas to draw to</param>
	/// <param name="cam">Camera</param>
	void draw(GamesEngineeringBase::Window& canvas, Camera& cam);
	/// <summary>
	/// Returns the pickup at an index
	/// </summary>
	/// <param name="index">Index to return</param>
	/// <returns><Pickup/returns>
	Pickup& operator[](unsigned int index);
	/// <summary>
	/// returns used count of pickups
	/// </summary>
	/// <returns>count</returns>
	int used();

	/// <summary>
	/// Checks pickups to see if it's colliding with hero
	/// </summary>
	/// <param name="hero">Hero</param>
	/// <param name="cam">Camera</param>
	void collisionToHero(Hero& hero, Camera& cam);
};