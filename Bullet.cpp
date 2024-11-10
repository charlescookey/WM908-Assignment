#include "Bullet.h"

#include <cmath>

Bullet::Bullet() {
	bullet = Plane(0, 0, ImageIndex::ObjectBullet);
}
/// <summary>
/// Sets the width and height
/// </summary>
/// <param name="WH">Vec2 holding width and height</param>
void Bullet::setImageWidthAndHeight(Vec2 WH) {
	bullet.setWidthAndHeight(WH);
}
/// <summary>
/// Saves the Bullet Output
/// </summary>
/// <returns>string output</returns>
std::string Bullet::SaveBullet() {
	std::string result;
	result += "Bullet: " + std::to_string(directionX) + " " + std::to_string(directionY) + " " + std::to_string(fired) + " " + std::to_string(speed) + " " + std::to_string(damage) + "\n";
	return result;
}
/// <summary>
/// Gets the direction to travel to from origin to destination
/// </summary>
/// <param name="pp">Origin Character</param>
/// <param name="cam">Camera</param>
/// <param name="target">Destination Character</param>
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
/// <summary>
/// Gets the direction to travel to from origin to Position XY
/// </summary>
/// <param name="pp">Origin Character</param>
/// <param name="cam">Camera</param>
/// <param name="TargetX">Position X</param>
/// <param name="TargetY">Position Y</param>
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
/// <summary>
/// Gets the direction to travel to from origin to Position XY
/// </summary>
/// <param name="pp">Origin Character</param>
/// <param name="TargetX">Position X</param>
/// <param name="TargetY">Position Y</param>
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
/// <summary>
/// Returns the nearest round number, if positive rounds up, if negative rounds down
/// </summary>
/// <param name="f"></param>
/// <returns></returns>
int Bullet::nearestRoundInt(float f) {
	if (f > 0)return static_cast<int>(std::ceil(f));
	return static_cast<int>(std::floor(f));
}
/// <summary>
/// Updates the bullets X and Y, also checks if still in frame
/// </summary>
/// <param name="cam">Camara</param>
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
/// <summary>
/// Stops the bullet
/// </summary>
void Bullet::stop() {
	fired = false;
	//remove from array
}
/// <summary>
/// Draws the bullet to canvas
/// </summary>
/// <param name="canvas">Canavs to draw to</param>
/// <param name="cam">Camera</param>
void Bullet::draw(GamesEngineeringBase::Window& canvas, Camera& cam) {
	if (fired)
		cam.drawInCamera(canvas, bullet);
}