#include "BulletManager.h"


BulletManager::BulletManager() {
}

BulletManager::~BulletManager() {
}

void BulletManager::add(Bullet* b) {
	bullets.add(b);
}

std::string BulletManager::SaveBullet() {
	std::string result = "Bullets: \n";
	for (int i = 0; i < bullets.used; i++)
		if (bullets[i]->fired) {
			result += bullets[i]->SaveBullet();
		}
	return result;
}

void BulletManager::update(Camera& cam , float dt) {

	for (int i = 0; i < bullets.used; i++)
		if (bullets[i]->fired) {
			bullets[i]->update(cam, dt);
		}
		else {
			bullets.remove(i);
		}
};

void BulletManager::draw(GamesEngineeringBase::Window& canvas, Camera& cam) {
	for (int i = 0; i < bullets.used; i++)
		if (bullets[i] != nullptr && bullets[i]->fired) {
			cam.drawInCamera(canvas, bullets[i]->bullet);
		}
}

Bullet& BulletManager::operator[](unsigned int index) {
	return *bullets[index];
}

int BulletManager::used() {
	return bullets.used;
}

