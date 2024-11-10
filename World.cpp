#include "World.h"


#include <fstream>
#include <string>
#include <sstream>

World::World() {
}


World::~World() {
	for (int i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
}

void World::load(std::string filename) {
	std::ifstream infile(filename);
	int tilenum;
	std::string line;

	//rows and col should be rerad from file;


	arr = new int* [rows];
	background = new Tile * [rows];
	for (int i = 0; i < rows; ++i) {
		arr[i] = new int[cols];
		background[i] = new Tile[cols];
	}
	//infile >> tilenum;
	//std::cout << tilenum << "\n";

	int i = 0; int j = 0;
	while (std::getline(infile, line)) {
		std::stringstream ssin(line);
		while (ssin.good() && i < cols) {
			ssin >> arr[i][j++];
		}
		i++;
		j = 0;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//background[i][j] = new Plane(i * 32, j * 32, filearray[arr[i][j] - 1]);
			int _temp = arr[i][j];
			bool canPass = _temp == 4 ? false : true;
			ImageIndex temp = static_cast<ImageIndex>(_temp);
			background[i][j] = Tile(i * 32, j * 32, temp, canPass);
		}
	}
	infile.close();

}
//make one with vec2;
bool World::passable(int x, int y) {
	//add checks to enbsure no overflow
	return background[x / 32][y / 32].ifCanPass();
}

Tile& World::at(unsigned int  X, unsigned int Y) {
	return background[X][Y];
}

