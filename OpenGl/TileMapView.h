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
	int altura;
	int largura;
	int x;
	int y;

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

*/
	void tileWalking(int pLargura, int pAltura, int direcao, int &col, int &lin) {
			switch (direcao) {
			case 1:
				col--;
				lin++;
				y += pAltura;
				break;
			case 2:
				lin++;
				x += pLargura /2;
				y += pAltura / 2;
				break;
			case 3:
				col++;
				lin++;
				x = pLargura;
				break;
			case 4:
				lin++;
				x += pLargura / 2;
				y -= pAltura /2;
				break;
			case 5:
				col++;
				lin--;
				y -= pAltura;
				break;
			case 6:
				lin--;
				x -= pLargura / 2;
				y -= pAltura / 2;
				break;
			case 7:
				col--;
				lin--;
				x -= pLargura;
				break;
			case 8:
				col--;
				x -= pLargura / 2;
				y += pAltura / 2;
				break;
			}
	}


	void calcTilePosition(int col, int lin, int largura, int altura) {
		x = (col * largura) + (lin * (largura / 2));
		y = lin * (largura / 2);
	}

	void pontoPertenceTile(int x, int y, int tileHeight, int tileWidth) {
		double c, r;
		c = (x * tileHeight + y * tileWidth) / (double)(tileHeight * tileWidth) /*- 10*/;
		r = (x * tileHeight - y * tileWidth) / (double)(tileHeight * tileWidth) /*+ 10*/;

		if (c <= 0)
			c--;
		if (r <= 0)
			r--;
		printf("Pontos: c: %d   r:%d\n", (int)c, (int)r);
		//printf("Pontos: xMouse:%d yMouse:%d\n", x, y);
		//printf("Pontos: x:%d y:%d\n", col, row);
	}
};

TileMapView::TileMapView(int a, int l) {
	altura = a;
	largura = l;
};