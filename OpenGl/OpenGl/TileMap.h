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
	Tile map[10][10]; 
	int coluna;
	int linha;
public:
	int getTileId(int x, int y) {
		map[x][y].getId();
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