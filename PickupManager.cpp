#include "PickupManager.h"



PickupManager::PickupManager() {
}

PickupManager::~PickupManager() {
}

void PickupManager::add(Pickup* b) {
	pickups.add(b);
}

std::string PickupManager::SavePickups() {
	std::string result = "Pickups: \n";
	for (int i = 0; i < pickups.used; i++)
		if (!pickups[i]->taken) {
			result += pickups[i]->SaveBullet();
		}
	return result;
}

void PickupManager::draw(GamesEngineeringBase::Window& canvas, Camera& cam) {
	for (int i = 0; i < pickups.used; i++)
		if (pickups[i] != nullptr && !pickups[i]->taken) {
			cam.drawInCamera(canvas, pickups[i]->pickup);
		}
}

Pickup& PickupManager::operator[](unsigned int index) {
	return *pickups[index];
}

int PickupManager::used() {
	return pickups.used;
}

//Should add cam here for accurate position
void PickupManager::collisionToHero(Hero& hero, Camera& cam) {
	int collisionX = hero.main.x + cam.WorldX;
	int collisionY = hero.main.y + cam.WorldY;
	for (int i = 0; i < pickups.used; i++) {
		if (pickups[i]->taken) {
			pickups.remove(i);
			continue;
			//Not ideal ass last wont be checked
		};
		if (pickups[i]->pickup.collision(collisionX, collisionY, hero.main.width, hero.main.height)) {
			hero.takePickup(pickups[i]->type);
			pickups[i]->taken = true;
			break;
			///remove from 


		}
	}

}
