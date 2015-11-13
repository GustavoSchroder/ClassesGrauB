#pragma once

#include "Tile.h"
#include "TileMap.h"

class TileSet
{
public:
	Tile getTileById(int id) {
		return tile[id];
	}
private:
	Tile tile[];
};