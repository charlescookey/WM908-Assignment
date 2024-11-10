
//work on th collision,have a circle radisu around shape, and if dist between center is more than
//sum of both rad, we can say theyhave collided, also try like oval too
//would be neat
//
//
//also make two games, the plane one woth enemies, and the new one with shooting.


#include <fstream>
#include <sstream>
#include <iostream>

#include "Horde.h"

#include "NumberDraw.h"
#include "MenuSystem.h"
#include "TimeDisplay.h"

void testBullet(Hero& pp) {
	int TargetX = 0;
	int TargetY = 0;

	float dx = pp.main.x - TargetX;
	float dy = pp.main.y - TargetY;

	float lenght = std::sqrtf((dx * dx) + (dy * dy));

	float directionX = dx / lenght;
	float directionY = dy / lenght;

}


//baddddd idea;
float tempElapsedtime = 0;
float areaElapsedtime = 0;

void divine(Camera& cam, Hero& pp, Horde& hh, BulletManager& bullets, int moveX, int moveY, GamesEngineeringBase::Window& canvas, World& ww, float dt) {

	if (pp.collisionWithTerrain(ww, cam, moveX, moveY)) {
		pp.update(moveX, moveY);
		cam.update(moveX, moveY, pp);
	}

	//we'd add functionality to make plaer not go through NPS

	/*hh.doArray([&pp](Opponent* a) {
		if (a->main.collision(pp.main)) {
			pp.takeDamage(a->damage);
			return true;
		}
		});*/

	hh.collisionToHero(pp, cam);

	/*hh.doArray([&bullets](Opponent* a) {
		for (int i = 0; i < bullets.used(); i++) {
			if (bullets[i].fired && a->main.collision(bullets[i].bullet)) {
				a->takeDamage(bullets[i].damage);
				bullets[i].stop();
			}
		}
		});*/

	hh.collisionToBullets(bullets, pp);

	hh.collisionNPCBulletsToHero(pp, cam);

	float max = 0;

	int TargetX = INT_MIN;
	int TargetY = INT_MIN;

	hh.closestToHero(pp, cam, TargetX, TargetY);

	tempElapsedtime += dt;
	//tempElapsedtime = dt;

	if (tempElapsedtime > 1.f && TargetX != INT_MIN) {
		Bullet* bull = new Bullet();
		bull->getDirection(pp, cam, TargetX, TargetY);
		bull->setImageWidthAndHeight(cam.gallery.getImageWidthAndHeight(bull->bullet.imageindex));
		bullets.add(bull);

		tempElapsedtime = 0.f;
	}


}


void saveAll(Camera& cam, Hero& pp, Horde& hh, BulletManager& bullets) {
	std::string fileOutput;
	fileOutput += cam.SaveCamera();
	fileOutput += pp.SaveHero();
	fileOutput += hh.SaveHorde();
	fileOutput += bullets.SaveBullet();

	std::ofstream outfile("saveOutput.txt");

	outfile.write(fileOutput.c_str(), fileOutput.size());
	outfile.close();

}

void splitLine(std::string input) {
	std::stringstream ssin(input);
	std::string temp;

	ssin >> temp;

	if (temp == "Camera:") {

	}
}


//we should also save width and height
bool addtoHorde(Horde& hh, std::string line, Camera& cam) {
	std::stringstream ssin(line);
	int index, X, Y, currHealth;
	std::string name;
	ssin >> name;
	if (name == "DONE")return false;
	ssin >> index;
	ssin >> X;
	ssin >> Y;
	ssin >> currHealth;
	Opponent* enemy = hh.createOldEnemy(index, X, Y, name);
	enemy->setImageWidthAndHeight(cam.gallery.getImageWidthAndHeight(enemy->main.imageindex));

	enemy->currHealth = currHealth;
	hh.horde.add(enemy);
	return true;
}

void loadFromFile(std::string filename, Camera& cam, Hero& hero, Horde& hh, BulletManager& bullets) {
	std::ifstream infile;
	infile.open(filename);
	std::string line;

	// assume file is open
	while (std::getline(infile, line)) {
		std::stringstream ssin(line);
		//while (ssin.good()) {
		std::string temp;
		ssin >> temp;
		if (temp == "Camera:") {
			ssin >> cam.WorldX;
			ssin >> cam.WorldY;
			ssin >> cam.width;
			ssin >> cam.height;
		}
		else if (temp == "Hero:") {
			ssin >> hero.main.x;
			ssin >> hero.main.y;
			ssin >> hero.currHealth;
			ssin >> hero.areaAttack;
			ssin >> hero.topNEnemy;
		}
		else if (temp == "Horde:") {
			while (std::getline(infile, line)) {
				if (!addtoHorde(hh, line, cam))break;

			}
		}
		else {
			continue;
		}
	}
	infile.close();
}


int testTimer() {
	// Create a canvas window with dimensions 1024x768 and title “Tiles"
	GamesEngineeringBase::Window canvas;
	GamesEngineeringBase::Timer tim;

	//can be called inside camera
	canvas.create(1024, 768, "Charles GE");
	bool running = true; // Variable to control the main loop's running state.

	float ElapsedTime = 0.f;

	int X = 20;
	int Y = 20;
	canvas.clear();

	DrawHelp::drawPlainBackground(canvas, 0, 0, 0);

	for (int i = 0; i < 10; i++) {
		NumberDraw::drawNumber(i, canvas, X, Y, 255, 255, 255);
		X += 20;
	}

	X = 20;
	Y += 20;

	for (int i = 0; i < 10; i++) {
		NumberDraw::drawNumberScaled(1, i, canvas, X, Y, 255, 255, 255);
		X += 20;
	}

	X = 20;
	Y += 20;

	for (int i = 0; i < 10; i++) {
		NumberDraw::drawNumberScaled(2, i, canvas, X, Y, 255, 255, 255);
		X += 20;
	}

	X = 20;
	Y += 20;

	for (int i = 0; i < 10; i++) {
		NumberDraw::drawNumberScaled(3, i, canvas, X, Y, 255, 255, 255);
		X += 20;
	}

	while (running)
	{
		// Check for input (key presses or window events)
		canvas.checkInput();
		// Clear the window for the next frame rendering
		// Update game logic

		if (canvas.keyPressed(VK_ESCAPE)) break;

		// Display the frame on the screen. This must be called once the frame is finished in order to display the frame.
		canvas.present();
	}
	return 0;
};


int fixedLevel(GamesEngineeringBase::Window& canvas, bool loadlastSave) {
	GamesEngineeringBase::Timer tim;
	bool running = true; // Variable to control the main loop's running state.

	Camera cam(0, 0, 1024, 768);

	World bb;
	bb.load("world_matrix.txt"); // her should set thje world constaints

	Hero hero(canvas.getWidth() / 2, canvas.getHeight() / 2);
	hero.setImageWidthAndHeight(cam.gallery.getImageWidthAndHeight(hero.main.imageindex));

	Horde horde;
	BulletManager bullets;
	PickupManager pickups;

	TimeDisplay timedisplay(487, 20, 2);

	int frameSkip = 0;
	float time = 0.f;

	if (loadlastSave) {
		loadFromFile("saveOutput.txt", cam, hero, horde, bullets);
	}

	int frameCount = 0;
	float FPStimeELapsed = 0.f;
	int nextScoreLevel = 100;
	while (running)
	{
		// Check for input (key presses or window events)
		canvas.checkInput();
		// Clear the window for the next frame rendering
		canvas.clear();
		// Update game logic

		if (canvas.keyPressed(VK_ESCAPE)) break;

		if (canvas.keyPressed('X')) {
			saveAll(cam, hero, horde, bullets);
			break;
		}

		float dt = tim.dt();
		int move = static_cast<int>(500.f * dt);

		timedisplay.update(dt);

		FPStimeELapsed += dt;
		frameCount++;
		if (FPStimeELapsed > 1.f) {
			float FPS = frameCount / FPStimeELapsed;
			std::cout << "FPS: " << FPS << "\n";
			FPStimeELapsed = 0;
			frameCount = 0;
		}

		if (hero.getScore() >= nextScoreLevel) {
			int Y = cam.WorldY + (rand() % cam.height);
			int X = cam.WorldX + (rand() % cam.width);
			std::cout << "New Pickup has been added at" << X << " " << Y << "\n";
			nextScoreLevel += 100;
			Pickup* pickup = new Pickup(3, X, Y);
			pickup->setImageWidthAndHeight(cam.gallery.getImageWidthAndHeight(pickup->pickup.imageindex));
			pickups.add(pickup);
		}

		int x = 0;
		int y = 0;
		if (canvas.keyPressed('W')) y -= move;
		if (canvas.keyPressed('S'))  y += move;
		if (canvas.keyPressed('A')) x -= move;
		if (canvas.keyPressed('D')) x += move;

		areaElapsedtime += dt;
		if (canvas.keyPressed('F')) {
			if (areaElapsedtime > 2.f) {
				horde.AreaofEffect(hero, cam);
				areaElapsedtime = 0.f;
				hero.drawArea = true;
			}
		}

		bullets.update(cam);
		horde.update(dt, cam, hero);

		divine(cam, hero, horde, bullets, x, y, canvas, bb, dt);
		pickups.collisionToHero(hero, cam);

		// Draw(); 

		cam.drawBackground(canvas, bb);
		hero.drawAreaofEffect(canvas);
		horde.draw(canvas, cam);
		hero.draw(canvas, cam.gallery);
		//hero.slashAnimation(canvas);
		bullets.draw(canvas, cam);
		pickups.draw(canvas, cam);

		timedisplay.draw(canvas);

		// Display the frame on the screen. This must be called once the frame is finished in order to display the frame.
		canvas.present();
	}
	return 0;
}



int LevelSelector(int index, GamesEngineeringBase::Window& canvas) {
	switch (index) {
	case 0:
		fixedLevel(canvas, false);
		break;
	case 1:
		fixedLevel(canvas, true);
		break;
	case 2:
		break;
	case 3:
		return -1;
	}
	return 0;
}


//rename to main
int main() {
	// Create a canvas window with dimensions 1024x768 and title “Tiles"
	GamesEngineeringBase::Window canvas;
	GamesEngineeringBase::Timer tim;

	//can be called inside camera
	canvas.create(1024, 768, "Charles GE");
	bool running = true; // Variable to control the main loop's running state.

	MenuSystem menu;

	GamesEngineeringBase::Image Backimage;
	Backimage.load("UI/TitleScreen.png");

	TimeDisplay timedisplay(487, 20, 2);

	while (running)
	{
		// Check for input (key presses or window events)
		canvas.checkInput();
		// Clear the window for the next frame rendering
		canvas.clear();
		// Update game logic

		if (canvas.keyPressed(VK_ESCAPE)) break;

		DrawHelp::drawPlainBackground(canvas, 0, 0, 0);

		float dt = tim.dt();
		timedisplay.update(dt);

		bool ButtonPressed = false;
		if (canvas.keyPressed('W')) {
			menu.moveUp();
			ButtonPressed = true;
		}
		if (canvas.keyPressed('S')) {
			menu.moveDown();
			ButtonPressed = true;
		}
		menu.buttonPress = ButtonPressed;

		if (canvas.keyPressed(VK_RETURN)) {
			if (LevelSelector(menu.getIndex(), canvas) == -1)break;
		}

		DrawHelp::drawImage(canvas, Backimage, 0, 0);
		menu.draw(canvas);

		timedisplay.draw(canvas);

		// Display the frame on the screen. This must be called once the frame is finished in order to display the frame.
		canvas.present();
	}
	return 0;
}


