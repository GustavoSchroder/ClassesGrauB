#pragma once
#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Tile.h"
#include "TileMap.h"

class TileMapView {
private:
	int largura;
	int altura;
	int x;
	int y;
	TileMap *tm;

public:
	TileMapView(int a, int l);

	CONST INT N = 1;
	CONST INT NE = 2;
	CONST INT E = 3;
	CONST INT SE = 4;
	CONST INT S = 5;
	CONST INT SW = 6;
	CONST INT W = 7;
	CONST INT NW = 8;

	void tileWalking(int pLargura, int pAltura, int direcao) {
		switch (direcao)
		{
		case(1) : {
			x++;
			y += 2;
		}
		case(2) : {
			x++;
			y--;
		}
		case(3) : {
			x++;
		}
		case(4) : {
			y++;
		}
		case(5) : {
			x--;
			y += 2;
		}
		case(6) : {
			x--;
			y++;
		}
		case(7) : {
			x--;
		}
		case(8) : {
			y--;
		}
		}
	}

	void calcTilePosition(int col, int lin) {
		x = (col * largura) + (lin * (largura / 2));
		y = lin * (largura / 2);
	}

};

TileMapView::TileMapView(int a, int l) {
	altura = a;
	largura = l;
	tm = new TileMap(a, l);
};