#include "Bullet.h"

#include <cmath>

Bullet::Bullet() {
	bullet = Plane(0, 0, ImageIndex::ObjectBullet);
}

void Bullet::setImageWidthAndHeight(Vec2 WH) {
	bullet.setWidthAndHeight(WH);
}

std::string Bullet::SaveBullet() {
	std::string result;
	result += "Bullet: " + std::to_string(directionX) + " " + std::to_string(directionY) + " " + std::to_string(bullet.x) + " " + std::to_string(bullet.y)  + "\n";
	return result;
}

void Bullet::setProperties(float dirX, float dirY, int X, int Y) {
	directionX = dirX;
	directionY = dirX;

	bullet.x = X;
	bullet.y = Y;
};

void Bullet::getDirection(Character& pp, Camera& cam, Character& target) {
	fired = true;
	bullet.x = pp.main.x + cam.WorldX;
	bullet.y = pp.main.y + cam.WorldY;

	float dx = target.main.x - bullet.x;
	float dy = target.main.y - bullet.y;

	float lenght = std::sqrtf((dx * dx) + (dy * dy));

	directionX = dx / lenght;
	directionY = dy / lenght;
}

void Bullet::getDirection(Character& pp, Camera& cam, int TargetX, int TargetY) {
	fired = true;
	bullet.x = pp.main.x + cam.WorldX;
	bullet.y = pp.main.y + cam.WorldY;

	float dx = TargetX - bullet.x;
	float dy = TargetY - bullet.y;

	float lenght = std::sqrtf((dx * dx) + (dy * dy));

	directionX = dx / lenght;
	directionY = dy / lenght;
}

void Bullet::getDirection(Character& pp, int TargetX, int TargetY) {
	fired = true;
	bullet.x = pp.main.x;
	bullet.y = pp.main.y;

	float dx = TargetX - bullet.x;
	float dy = TargetY - bullet.y;

	float lenght = std::sqrtf((dx * dx) + (dy * dy));

	directionX = dx / lenght;
	directionY = dy / lenght;
}

int Bullet::nearestRoundInt(float f) {
	if (f > 0)return static_cast<int>(std::ceil(f));
	return static_cast<int>(std::floor(f));
}

void Bullet::update(Camera& cam ,float dt) {
	if (!fired)return;

	float move = static_cast<float>(speed);
	move *= dt;

	bullet.x += nearestRoundInt(directionX * move);
	bullet.y += nearestRoundInt(directionY * move);

	if (!cam.inbounds(bullet)) {
		fired = false;
	}
}

void Bullet::stop() {
	fired = false;
	//remove from array
}

void Bullet::draw(GamesEngineeringBase::Window& canvas, Camera& cam) {
	if (fired)
		cam.drawInCamera(canvas, bullet);
}