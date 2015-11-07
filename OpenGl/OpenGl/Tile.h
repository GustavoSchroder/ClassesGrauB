#pragma once

#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
class Tile {
	
private:
	int id;
public:
	Tile(int nId);
	int getId() {
		return id;
	}
	void setID(int nId) {
		id = nId;
	}
};

Tile::Tile(int nId) {
	id = nId;
};