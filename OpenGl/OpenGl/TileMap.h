#pragma once

#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Tile.h"

class TileMap {
private:
	int coluna;
	int linha;
//	Tile map[];
public:
	TileMap(int c, int l);

	int getTileId(int x, int y) {
		//map[x][y].getId();
	}

	int getColuna() {
		return coluna;
	}
	int getLinha() {
		return linha;
	}
	int setColuna(int coluna) {
		this->coluna = coluna;
	}
	int setLinha() {
		this->linha = linha;
	}
};

TileMap::TileMap(int c, int l) 
{
	coluna = c;
	linha = l;
//	map[c*l];
};