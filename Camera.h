#pragma once
#include "Gallery.h"
#include "World.h"
#include "Character.h"

class Camera {
public:
	Gallery gallery;
	bool moveLeft = true;
	bool moveRight = true;
	bool moveUp = true;
	bool moveDown = true;

	int WorldX;
	int WorldY;

	int width;
	int height;

	int ScreenSizeX = 1024;
	int ScreenSizeY = 768;
	int WorldSizeX = 3200;
	int WorldSizeY = 3200;

	/// <summary>
	/// Constructor with Speicied start positon, width and height
	/// </summary>
	/// <param name="x">Start X</param>
	/// <param name="y">Start Y</param>
	/// <param name="_width">Camera Width</param>
	/// <param name="_height">Camera Height</param>
	Camera(int x, int y, int _width, int _height);
	/// <summary>
	/// Save Camera
	/// </summary>
	/// <returns>String output of camera</returns>
	std::string SaveCamera();
	/// <summary>
	/// Given a directiona and spped, return the speed in the specified direction
	/// </summary>
	/// <param name="dir">Direction</param>
	/// <param name="speed">Speed</param>
	/// <returns>if speed is 1 , returns -1 or 1 </returns>
	int speed(int dir, int speed);
	/// <summary>
	/// Updates the main character
	/// </summary>
	/// <param name="x">Increment X</param>
	/// <param name="y">incremnt Y</param>
	/// <param name="main">Main Character</param>
	void update(int x, int y, Character& main, float dt);
	/// <summary>
	/// Draws a point in the Camera frame in Blue
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="X">Position X</param>
	/// <param name="Y">Position Y</param>
	void drawDebugPointInCameraRed(GamesEngineeringBase::Window& canvas, int X, int Y);
	/// <summary>
	/// Draws a point in the Camera frame in Red
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="X">Position X</param>
	/// <param name="Y">Position Y</param>
	void drawDebugPointInCameraBlue(GamesEngineeringBase::Window& canvas, int X, int Y);


	/// <summary>
	/// Draw a Plane Reference in camera
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="p">Plane reference</param>
	void drawInCamera(GamesEngineeringBase::Window& canvas, Plane& p);

	/// <summary>
	/// Draw a Tile Reference in camera
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="p">Tile reference</param>
	void drawInCamera(GamesEngineeringBase::Window& canvas, Tile& p);

	/// <summary>
	/// Draw a Plane Pointer in camera
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="p">Plane pointer</param>
	void drawInCamera(GamesEngineeringBase::Window& canvas, Plane* p);

	/// <summary>
	/// Draw a Tile Pointer in camera
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="p">Tile pointer</param>
	void drawInCamera(GamesEngineeringBase::Window& canvas, Tile* p);


	/// <summary>
	/// Draw a Character Reference in camera
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="p">Character reference</param>
	void drawInCamera(GamesEngineeringBase::Window& canvas, Character& p);

	//test var
	int frameSkip = 0;
	/// <summary>
	/// Draw a World Reference in camera
	/// </summary>
	/// <param name="canvas">canavs to draw to</param>
	/// <param name="p">World reference</param>
	void drawBackground(GamesEngineeringBase::Window& canvas, World& world);
	/// <summary>
	/// Check if inside camera frame
	/// </summary>
	/// <param name="plane">Plane to check</param>
	/// <returns>true if inside</returns>
	bool inbounds(Plane& plane);
};