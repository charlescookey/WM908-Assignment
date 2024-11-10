#pragma once
#include "Character.h"
#include "Camera.h"


class Hero :public Character {
	//GamesEngineeringBase::Image* slashAnimations[34];
	int animationFrames = 0;
	Plane slash;
	bool slashCheck = true;
	float slashCooldown = 1.0f;
	float timeElapsed = 0.f;
	int score = 0;

public:
	int getScore() {
		return score;
	}
	int  areaAttack = 100;
	int  areaAttackDamage = 5;
	int topNEnemy = 15;


	/// <summary>
	/// Constructor with specified position
	/// </summary>
	/// <param name="x">Position X</param>
	/// <param name="y">Position Y</param>
	Hero(int x, int y);
	/// <summary>
	/// Save Ouput
	/// </summary>
	/// <returns>string output to file</returns>
	std::string SaveHero();
	/// <summary>
	/// Checks if collidign with Terrain
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="ww">World</param>
	/// <param name="cam">Camera</param>
	/// <returns>true if colliding</returns>
	bool OldCollision(GamesEngineeringBase::Window& canvas, World& ww, Camera& cam);

	/// <summary>
	/// Draws debug points 
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="ww">World</param>
	/// <param name="cam">Camera</param>
	/// <param name="X">Terrain X</param>
	/// <param name="Y">Terrain Y</param>
	void drawCollisionWithTerrain(GamesEngineeringBase::Window& canvas, World& ww, Camera& cam, int X, int Y);


	/// <summary>
	/// Checks of colliding with Terrain Position
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="ww">World</param>
	/// <param name="cam">Camera</param>
	/// <param name="X">Terrain X</param>
	/// <param name="Y">Terrain Y</param>
	/// <returns>true if collision</returns>

	bool collisionWithTerrain(World& ww, Camera& cam, int X, int Y);

	/*
	void slashCoolDown(float dt) {
		timeElapsed += dt;

		if (timeElapsed > slashCooldown) {
			slashCheck = !slashCheck;
			int animationFrames = 0;
			timeElapsed = 0.f;

		}
	}

	void slashAnimation(GamesEngineeringBase::Window& canvas) {
		if (!slashCheck) {
			return;
		}

		if (right) {
			slash.drawAt(canvas, main.x + 64, main.y -10);
		}
		else
			slash.backDrawAt(canvas, main.x - 64, main.y-10);

		animationFrames++;
		slash.sprite = *slashAnimations[(animationFrames/2) % 34];
	};*/


	int cirleFrames = 0;
	bool drawArea = false;

	/// <summary>
	/// Draws the area of effect
	/// </summary>
	/// <param name="canvas">canavs to drawe to</param>
	void drawAreaofEffect(GamesEngineeringBase::Window& canvas);
	/// <summary>
	/// Takes a pickup
	/// </summary>
	/// <param name="type">Pickup Type</param>
	void takePickup(int type);
	/// <summary>
	/// Adds to score of Hero
	/// </summary>
	/// <param name="i">Score to add</param>
	void addToScore(int i);
};
