#include "Horde.h"
#include "Circle.h"
#include <iostream>

///////Remoeve !!!
#include <vector>


Horde::Horde() {
}

Horde::~Horde() {
}

void Horde::update(float dt, Camera& cam, Hero& hero) {
	timeElapsed += dt;
	DamagetimeElapsed += dt;

	if (timeElapsed > frequency) {
		Opponent* p = createNewEnemy(cam, horde.used);
		if (p == nullptr) {
			std::cout << "Pointer doesnt exist, couldnt create new array!\n";
		}
		else {
			p->setImageWidthAndHeight(cam.gallery.getImageWidthAndHeight(p->main.imageindex));
			horde.add(p);

		}
		timeElapsed = 0.f;
		frequency = max(1.0f, frequency - 0.1);
		std::cout << frequency << "\n";
	}

	int posX = cam.WorldX + hero.main.x;
	int posY = cam.WorldY + hero.main.y;

	for (int i = 0; i < horde.used; i++)
		if (horde[i]->alive) {
			if (horde[i]->type == 4) {//make a macro for static type
				shoot(dt, *horde[i], hero, cam);
			}
			else {
				horde[i]->follow(posX, posY , dt);
			}
		}
		else {
			horde.remove(i);
		}
	NPCBullets.update(cam,dt);
};

std::string Horde::SaveHorde() {
	std::string result = "Horde: \n";
	for (int i = 0; i < horde.used; i++)
		if (horde[i] != nullptr) {
			result += horde[i]->SaveOpponent();
		}
	result += "DONE  \n\n";

	return result;
}

void Horde::draw(GamesEngineeringBase::Window& canvas, Camera& cam) {
	for (int i = 0; i < horde.used; i++)
		if (horde[i] != nullptr && horde[i]->isAlive()) {
			cam.drawInCamera(canvas, *horde[i]);
		}
	NPCBullets.draw(canvas, cam);
}

template <typename Func> // easier than declaring different types
void Horde::doArray(Func lambda) {
	for (unsigned int i = 0; i < horde.used; i++) {
		if (lambda(horde[i]))break;
	}
}

//use vec2 later
void Horde::closestToHero(Hero& hh, Camera& cc, int& TargetX, int& TargetY) {
	int max = INT_MAX;
	int temp = 0;
	for (int i = 0; i < horde.used; i++) {
		if (!horde[i]->isAlive())continue;
		temp = horde[i]->main.distance(hh.main.x + cc.WorldX, hh.main.y + cc.WorldY);
		if (temp < max) {
			max = temp;
			TargetX = horde[i]->main.x;
			TargetY = horde[i]->main.y;
		}
	}
}


//Should add cam here for accurate position
void Horde::collisionToHero(Hero& hero, Camera& cam) {
	int totalDamage = 0;
	int damagersCount = 0;
	int collisionX = hero.main.x + cam.WorldX;
	int collisionY = hero.main.y + cam.WorldY;
	for (int i = 0; i < horde.used; i++) {
		//check if Alive
		if (horde[i]->isAlive() && horde[i]->main.collision(collisionX, collisionY, hero.main.width, hero.main.height)) {
			totalDamage += horde[i]->damage;
			damagersCount++;
		}
	}
	if (totalDamage > 0 && DamagetimeElapsed > 0.5f) {
		hero.takeDamage(totalDamage);
		std::cout << "hero takes " << totalDamage << " from " << damagersCount << " enemies\n";
		DamagetimeElapsed = 0.f;
	}
}

void Horde::collisionToBullets(BulletManager& bullets, Hero& hero) {
	for (int i = 0; i < horde.used; i++) {
		for (int j = 0; j < bullets.used(); j++) {
			if (bullets[j].fired && horde[i]->main.collision(bullets[j].bullet)) {
				horde[i]->takeDamage(bullets[j].damage);
				bullets[j].stop();

				//here check if dead. t
				//then also you can display a number here that can be added to the score
				if (!horde[i]->isAlive()) {
					//issue this would keep adding until we remove the old ones
					//should call death from here, if death called earlirt this would be null
					hero.addToScore(horde[i]->maxHealth);
				}
			}
		}
	}
}

void Horde::collisionNPCBulletsToHero(Hero& hero, Camera& cam) {
	int collisionX = hero.main.x + cam.WorldX;
	int collisionY = hero.main.y + cam.WorldY;
	for (int j = 0; j < NPCBullets.used(); j++) {
		if (NPCBullets[j].fired && NPCBullets[j].bullet.collision(collisionX, collisionY, hero.main.width, hero.main.height)) {
			hero.takeDamage(NPCBullets[j].damage);
			NPCBullets[j].stop();
		}
	}
}

void Horde::shoot(float dt, Opponent& start, Hero& hero, Camera& cam) {

	ShootTime += dt;
	//tempElapsedtime = dt;

	if (ShootTime > 1.f) {

		int TargetX = hero.main.x + cam.WorldX;
		int TargetY = hero.main.y + cam.WorldY;

		Bullet* bull = new Bullet();
		bull->getDirection(start, TargetX, TargetY);
		bull->setImageWidthAndHeight(cam.gallery.getImageWidthAndHeight(bull->bullet.imageindex));
		NPCBullets.add(bull);
		bull = nullptr;

		ShootTime = 0.f;
	}
}


void Horde::AreaofEffect(Hero& hero, Camera& cam) {
	//add sprite width
	int centerX = hero.main.x + cam.WorldX + hero.main.width;
	int centerY = hero.main.y + cam.WorldY + hero.main.height;

	Vec2 center(centerX, centerY);

	minPriQueue qq(hero.topNEnemy);

	Circle areaofEffect(center, hero.areaAttack);


	//std::cout << "inside circle\n";
	for (int i = 0; i < horde.used; i++) {
		if (areaofEffect.inside(horde[i]->main.x, horde[i]->main.y)) {
			qq.add(horde[i]);
			//std::cout <<horde[i]->debugname<<" "<<horde[i]->currHealth << "\t";
		}
	}
	//std::cout << "\n";

	std::vector<Opponent*> test{};

	//std::cout << "Top N\n";
	for (int i = 0; i < qq.size; i++) {
		if (qq.arr[i] != nullptr) {
			//std::cout << qq.arr[i]->debugname<< " " << horde[i]->currHealth << "\t";
			test.push_back(qq.arr[i]);
			qq.arr[i]->takeDamage(hero.areaAttackDamage);
		}
	}
	//std::cout << "--------\n";
}

Opponent* Horde::createNewEnemy(Camera& cam, int i) {

	//just as a test			  cleric1.png
	Opponent Brazy(300, 5, ImageIndex::CharacterCleric, 0);
	Opponent Killer(200, 20, ImageIndex::CharacterWarrior, 1);
	Opponent Robot(150, 10, ImageIndex::CharcaterMinoutaur, 2);
	Opponent Shock(205, 15, ImageIndex::CharacterOrc, 3);
	Opponent Stagnant(2, 15, ImageIndex::CharacterOrc, 4);

	int index = rand() % 5;
	int Y = 0;
	if (index % 2 == 0)
		Y = max(0, cam.WorldY - 64);
	else
		Y = min(cam.WorldY + cam.ScreenSizeY + 64, cam.WorldSizeX);

	int X = cam.WorldX + rand() % cam.ScreenSizeX;

	//The static guy should be spawned in the frame
	if (index == 4) {
		Y = cam.WorldY + (rand() % cam.height);
		X = cam.WorldX + (rand() % cam.width);
	}

	std::string debugname = "Opponent" + std::to_string(i);

	switch (index) {
	case 0:
		return new Opponent(Brazy, X, Y, debugname);

	case 1:
		return new Opponent(Killer, X, Y, debugname);
	case 2:
		return new Opponent(Robot, X, Y, debugname);
	case 3:
		return new Opponent(Shock, X, Y, debugname);
	case 4:
		return new Opponent(Stagnant, X, Y, debugname);
	}
}


/// <summary>
/// Created an eneny that existed in a previous game
/// </summary>
/// <param name="index">Index</param>
/// <param name="X">Position X</param>
/// <param name="Y">Position Y</param>
/// <param name="debugname">Debug Name</param>
/// <returns>Opponent that existed</returns>
Opponent* Horde::createOldEnemy(int index, int X, int Y, std::string debugname) {

	//just as a test			  cleric1.png
	Opponent Brazy(300, 5, ImageIndex::CharacterCleric, 0);
	Opponent Killer(200, 20, ImageIndex::CharacterWarrior, 1);
	Opponent Robot(150, 10, ImageIndex::CharcaterMinoutaur, 2);
	Opponent Shock(205, 15, ImageIndex::CharacterOrc, 3);
	Opponent Stagnant(2, 15, ImageIndex::CharacterOrc, 4);

	switch (index) {
	case 0:
		return new Opponent(Brazy, X, Y, debugname);

	case 1:
		return new Opponent(Killer, X, Y, debugname);
	case 2:
		return new Opponent(Robot, X, Y, debugname);
	case 3:
		return new Opponent(Shock, X, Y, debugname);
	case 4:
		return new Opponent(Stagnant, X, Y, debugname);
	}
}