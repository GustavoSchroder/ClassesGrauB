#pragma once

#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "IsometricView.h"
#include "TileMap.h"
class Tile {
private:
	int id;
public:
	int getId() {
		return id;
	}
};
