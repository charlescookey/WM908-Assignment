#pragma once
#include "Bullet.h"
#include "GameArray.h"

class BulletManager {
	float timeElapsed = 0.f;
	GameArray<Bullet*> bullets;
public:
	/// <summary>
	/// Constructor
	/// </summary>
	BulletManager();
	//Destructor
	~BulletManager();
	/// <summary>
	/// Add to manager
	/// </summary>
	/// <param name="b">Bullet to add</param>
	void add(Bullet* b);
	/// <summary>
	/// Save bullet Outptut
	/// </summary>
	/// <returns>string output</returns>
	std::string SaveBullet();
	/// <summary>
	/// Updates all bullets
	/// </summary>
	/// <param name="cam">Camera</param>
	void update(Camera& cam, float dt);
	/// <summary>
	/// Draws all bullets
	/// </summary>
	/// <param name="canvas">Canavs to draw to</param>
	/// <param name="cam">Camera</param>
	void draw(GamesEngineeringBase::Window& canvas, Camera& cam);

	/// <summary>
	/// Returs the bullet at a position
	/// </summary>
	/// <param name="index">index of bullet to get</param>
	/// <returns></returns>
	Bullet& operator[](unsigned int index);
	//returns used count of bullets
	int used();

};