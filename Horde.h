#pragma once

#include "Queue.h"
#include "BulletManager.h"
#include "PickupManager.h"

class Horde {
	//for deubgging sakw
	float timeElapsed = 0.f;
	float DamagetimeElapsed = 0.f;
	float frequency = 5.f;

public:
	GameArray<Opponent*> horde;

	// i could also just create an array
	BulletManager NPCBullets;

	/// <summary>
	/// Constructor
	/// </summary>
	Horde();

	/// <summary>
	/// Destructor
	/// </summary>
	~Horde();

	/// <summary>
	/// Updates all opponents
	/// </summary>
	/// <param name="dt">Times since last call</param>
	/// <param name="cam">Camera</param>
	/// <param name="hero">Hero to follow</param>
	void update(float dt, Camera& cam, Hero& hero);

	/// <summary>
	/// Saves all Opponents
	/// </summary>
	/// <returns>string output</returns>
	std::string SaveHorde();
	/// <summary>
	/// Draws all Opponents
	/// </summary>
	/// <param name="canvas">Canavs to draw to</param>
	/// <param name="cam">Camera</param>
	void draw(GamesEngineeringBase::Window& canvas, Camera& cam);
	/// <summary>
	/// Do array, does a function to the horde array
	/// </summary>
	/// <typeparam name="Func">Fucntion to be applied</typeparam>
	/// <param name="lambda">Function</param>
	template <typename Func> // easier than declaring different types
	void doArray(Func lambda);

	/// <summary>
	/// Finds the closest to the Hero
	/// </summary>
	/// <param name="hh">Hero</param>
	/// <param name="cc">Cmaera</param>
	/// <param name="TargetX">Output Position X</param>
	/// <param name="TargetY">Output Position Y</param>
	void closestToHero(Hero& hh, Camera& cc, int& TargetX, int& TargetY);


	/// <summary>
	/// Checks if Opponents in Horde Array Collides with Hero
	/// </summary>
	/// <param name="hero">Hero</param>
	/// <param name="cam">Camera</param>
	void collisionToHero(Hero& hero, Camera& cam);
	/// <summary>
	/// Checks if opponents are colliding with Bullets shot by Hero
	/// </summary>
	/// <param name="bullets">Bullet array</param>
	/// <param name="hero">Hero</param>
	void collisionToBullets(BulletManager& bullets, Hero& hero);

	/// <summary>
	/// Checks if hero collides with Bullets shot by NPC
	/// </summary>
	/// <param name="hero"></param>
	/// <param name="cam"></param>
	void collisionNPCBulletsToHero(Hero& hero, Camera& cam);


	float ShootTime = 0.f;

	/// <summary>
	/// Shoots at the hero
	/// </summary>
	/// <param name="dt">time since last call</param>
	/// <param name="start">Shooting opponent location</param>
	/// <param name="hero">Hero</param>
	/// <param name="cam">Camera</param>
	void shoot(float dt, Opponent& start, Hero& hero, Camera& cam);;

	/// <summary>
	/// This creates the area of effect which is a special attack the player has, and finds the top N enemies and applies damage
	/// </summary>
	/// <param name="hero">Hero</param>
	/// <param name="cam">Camera</param>
	void AreaofEffect(Hero& hero, Camera& cam);
	/// <summary>
	/// Creates New Enemy
	/// </summary>
	/// <param name="cam">Camera</param>
	/// <param name="i">Index</param>
	/// <returns>A newly created Opponent</returns>
	Opponent* createNewEnemy(Camera& cam, int i);


	/// <summary>
	/// Created an eneny that existed in a previous game
	/// </summary>
	/// <param name="index">Index</param>
	/// <param name="X">Position X</param>
	/// <param name="Y">Position Y</param>
	/// <param name="debugname">Debug Name</param>
	/// <returns>Opponent that existed</returns>
	Opponent* createOldEnemy(int index, int X, int Y, std::string debugname);
};

