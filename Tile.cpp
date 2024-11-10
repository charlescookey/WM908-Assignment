#include "Tile.h"

Tile::Tile(int _x, int _y, ImageIndex _imageindex, bool _canPass) {
	imageindex = _imageindex;
	x = _x;
	y = _y;
	canPass = _canPass;
};
Tile::Tile() {
	x = 0;
	y = 0;
	imageindex = ImageIndex::BASE;
};

void Tile::setWidthAndHeight(Vec2 WH) {
	width = WH.x;
	height = WH.y;
}

bool Tile::ifCanPass() {
	return canPass;
}
