#include "Hero.h"

#include "DrawHelp.h"

Hero::Hero(int x, int y) {
	movespeed = 200;
	maxHealth = 100;
	currHealth = maxHealth;

	main = Plane(x, y, CharacterCleric);

	/*slash = Plane(x, y, "slash/Slash (1).png");
	temp = "slash/Slash (";
	for (int i = 1; i <= 34; i++) {
		name = temp + std::to_string(i) + ").png";
		slashAnimations[i - 1] = new GamesEngineeringBase::Image();
		slashAnimations[i - 1]->load(name);
	}*/
}

std::string Hero::SaveHero() {
	std::string result;
	result += "Hero: " + std::to_string(main.x) + " " + std::to_string(main.y) + " " + std::to_string(currHealth) + " " + std::to_string(areaAttack) + " " + std::to_string(topNEnemy) + "\n";
	return result;

}

bool Hero::OldCollision(GamesEngineeringBase::Window& canvas, World& ww, Camera& cam) {



	int cameraX = main.x + 20;
	int cameraY = main.y + 10;

	int worldX = cameraX + cam.WorldX;
	int worldY = cameraY + cam.WorldY;

	int offset = 40;


	for (int i = 0; i < 20; i++) {
		if (ww.passable(worldX + i, worldY) == 4) {
			canvas.draw(cameraX + i, cameraY, 255, 0, 0);
		}
		else
			canvas.draw(cameraX + i, cameraY, 0, 255, 0);

		if (ww.passable(worldX + i, worldY + offset) == 4)
			canvas.draw(cameraX + i, cameraY + offset, 255, 0, 0);
		else
			canvas.draw(cameraX + i, cameraY + offset, 0, 255, 0);
	}
	return true;

}

//onlu need canvas to draw debug , can remove later
void Hero::drawCollisionWithTerrain(GamesEngineeringBase::Window& canvas, World& ww, Camera& cam, int X, int Y) {

	int moveSpeed = 5;

	int upX = main.x + cam.WorldX + (main.width / 2);
	int upY = main.y + cam.WorldY - moveSpeed;

	int downX = main.x + cam.WorldX + (main.width / 2);
	int downY = main.y + cam.WorldY + main.height + moveSpeed;


	int leftX = main.x + cam.WorldX + 40 + moveSpeed;
	int left1Y = main.y + cam.WorldY + 10;
	int left2Y = main.y + cam.WorldY + 50;

	int rightX = main.x + cam.WorldX + 10;// -moveSpeed;
	int right1y = main.y + cam.WorldY + 10;
	int right2Y = main.y + cam.WorldY + 50;


	if (!ww.passable(upX, upY))
		cam.drawDebugPointInCameraRed(canvas, upX, upY);
	else
		cam.drawDebugPointInCameraBlue(canvas, upX, upY);


	if (!ww.passable(downX, downY))
		cam.drawDebugPointInCameraRed(canvas, downX, downY);
	else
		cam.drawDebugPointInCameraBlue(canvas, downX, downY);


	if (!ww.passable(leftX, left1Y))
		cam.drawDebugPointInCameraRed(canvas, leftX, left1Y);
	else
		cam.drawDebugPointInCameraBlue(canvas, leftX, left1Y);

	if (!ww.passable(leftX, left2Y))
		cam.drawDebugPointInCameraRed(canvas, leftX, left2Y);
	else
		cam.drawDebugPointInCameraBlue(canvas, leftX, left2Y);

	if (!ww.passable(rightX, right1y))
		cam.drawDebugPointInCameraRed(canvas, rightX, right1y);
	else
		cam.drawDebugPointInCameraBlue(canvas, rightX, right1y);

	if (!ww.passable(rightX, right2Y))
		cam.drawDebugPointInCameraRed(canvas, rightX, right2Y);
	else
		cam.drawDebugPointInCameraBlue(canvas, rightX, right2Y);
}


//dont need canvas here
bool Hero::collisionWithTerrain( World& ww, Camera& cam, int X, int Y) {

	int moveSpeed = 5;

	//colliion points
	int upX = main.x + cam.WorldX + (main.width / 2);
	int upY = main.y + cam.WorldY - moveSpeed;

	int downX = main.x + cam.WorldX + (main.width / 2);
	int downY = main.y + cam.WorldY + main.height + moveSpeed;


	int leftX = main.x + cam.WorldX + 40 + moveSpeed;
	int left1Y = main.y + cam.WorldY + 10;
	int left2Y = main.y + cam.WorldY + 50;

	int rightX = main.x + cam.WorldX + 10;// -moveSpeed;
	int right1y = main.y + cam.WorldY + 10;
	int right2Y = main.y + cam.WorldY + 50;

	if (Y < 0 && !ww.passable(upX, upY))
		return false;


	if (Y > 0 && !ww.passable(downX, downY))
		return false;


	if (X > 0 && !ww.passable(leftX, left1Y))
		return false;

	if (X > 0 && !ww.passable(leftX, left2Y))
		return false;

	if (X < 0 && !ww.passable(rightX, right1y))
		return false;

	if (X < 0 && !ww.passable(rightX, right2Y))
		return false;
}

/*

void Hero::slashCoolDown(float dt) {
	timeElapsed += dt;

	if (timeElapsed > slashCooldown) {
		slashCheck = !slashCheck;
		int animationFrames = 0;
		timeElapsed = 0.f;

	}
}

void Hero::slashAnimation(GamesEngineeringBase::Window& canvas) {
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



void Hero::drawAreaofEffect(GamesEngineeringBase::Window& canvas) {
	if (!drawArea)return;

	cirleFrames++;
	Vec2 center(main.x + main.width / 2, main.y + main.height);
	Circle cir(center, areaAttack);
	DrawHelp::drawCircle(canvas, cir, 255, 0, 0);

	if (cirleFrames == 3) {
		drawArea = false;
		cirleFrames = 0;
	}
}

void Hero::takePickup(int type) {
	switch (type) {
	case 1:
		currHealth += 5;
		break;
	case 2:
		topNEnemy++;
		break;
	case 3:
		areaAttack += 10;
		//cap it at min of screen width and height
		break;

	}
}

void Hero::addToScore(int i) {
	score += i;
	//std::cout << "New Score is " << score << "\n";
}
