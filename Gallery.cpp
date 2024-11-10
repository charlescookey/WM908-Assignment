#include "Gallery.h"

#include <fstream>



Gallery::Gallery() {
	for (int i = 0; i < 58; i++) {
		images[i].data = NULL;
	}
};

void Gallery::loadImages(std::string filename) {
	std::ifstream infile(filename);
	std::string line;

	int i = 1;
	while (std::getline(infile, line)) {
		if (line == "")break;
		images[i++].load(line);
	}

	infile.close();

}

Vec2 Gallery::getImageWidthAndHeight(ImageIndex imageindex) {
	return Vec2(images[imageindex].width, images[imageindex].height);
}

void Gallery::draw(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, Plane& plane) {
	int index = static_cast<int>(imageindex + offset);
	for (unsigned int i = 0; i < images[index].width; i++)
		if (plane.x + i < canvas.getWidth() && plane.x + i >= 0)
			for (unsigned int j = 0; j < images[index].height; j++)
				if (plane.y + j < canvas.getHeight() && plane.y + j >= 0)
					if (images[index].alphaAt(i, j) > 200)
						canvas.draw(plane.x + i, plane.y + j, images[index].at(i, j));
}

void Gallery::backDraw(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, Plane& plane) {
	int index = static_cast<int>(imageindex + offset);
	int _i = 0;
	for (unsigned int i = 0; i < images[index].width; i++) {
		_i = images[index].width - i;
		if (plane.x + _i < canvas.getWidth() && plane.x + _i >= 0) {
			for (unsigned int j = 0; j < images[index].height; j++) {
				if (plane.y + j < canvas.getHeight() && plane.y + j >= 0)
					if (images[index].alphaAt(i, j) > 200)
						canvas.draw(plane.x + _i, plane.y + j, images[index].at(i, j));
			}
		}

	}
}

void Gallery::backDrawAt(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, int X, int Y) {
	int index = static_cast<int>(imageindex + offset);
	int _i = 0;
	for (unsigned int i = 0; i < images[index].width; i++) {
		_i = images[index].width - i;
		if (X + _i < canvas.getWidth() && X + _i >= 0) {
			for (unsigned int j = 0; j < images[index].height; j++) {
				if (Y + j < canvas.getHeight() && Y + j >= 0)
					if (images[index].alphaAt(i, j) > 200)
						canvas.draw(X + _i, Y + j, images[index].at(i, j));
			}
		}

	}
}

void Gallery::drawAt(GamesEngineeringBase::Window& canvas, ImageIndex& imageindex, int offset, int X, int Y) {
	int index = static_cast<int>(imageindex + offset);
	for (unsigned int i = 0; i < images[index].width; i++)
		if (X + i < canvas.getWidth() && X + i >= 0)
			for (unsigned int j = 0; j < images[index].height; j++)
				if (Y + j < canvas.getHeight() && Y + j >= 0)
					if (images[index].alphaAt(i, j) > 200)
						canvas.draw(X + i, Y + j, images[index].at(i, j));
}
