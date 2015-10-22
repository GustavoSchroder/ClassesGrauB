#pragma once

#include "Image.h"

class Tile {
private:
	int id;
	Image image;
public:
	int getId() {
		return id;
	}
	Image getImage() {
		return image;
	}
};
