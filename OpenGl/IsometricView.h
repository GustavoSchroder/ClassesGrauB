#pragma once

#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "TileSet.h"

CONST INT N = 1;
CONST INT NE = 2;
CONST INT E = 3;
CONST INT SE = 4;
CONST INT S = 5;
CONST INT SW = 6;
CONST INT W = 7;
CONST INT NW = 8;

using namespace std;

class IsometricView {
private:
	int larguraTile;
	int alturaTile;
	int coluna;
	int linha;
	int x;
	int y;
public:
	void tileWalking(int pLargura, int pAltura, int direcao) {
		switch (direcao)
		{
		case(1): {
				coluna++;
				linha += 2;
			}
		case(2): {
			coluna++;
			linha--;
			}
		case(3): {
			coluna++;
		}
		case(4) : {
			linha++;
		}
		case(5) : {
			coluna--;
			linha += 2;
		}
		case(6) : {
			coluna--;
			linha++;
		}
		case(7) : {
			coluna--;
		}
		case(8) : {
			linha--;
		}
		}
	}
	void mouseMap(int x, int y) {
		int x0, y0;
		int coluna = x / 32;
		int linha = y / 32;

		coluna = ((coluna * 32) + (linha*(linha / 16)));
		linha = ((linha * 32)*linha);

		if (coluna > larguraTile) {
			coluna = larguraTile;
		}
		if (linha > alturaTile) {
			linha = alturaTile;
		}

		// fine adjusment
		if (coluna == larguraTile) {
			coluna--;
		}
		if (linha == alturaTile) {
			linha--;
		}
		calcTilePosition(linha, coluna);

		// Verifica se clicou em algum dos tiles
		if (linha < 0 || coluna < 0 || linha > alturaTile || coluna > larguraTile) {
			linha = coluna = -1;
			return;
		}

		if (y < this->y && x < this->x + 32) {
			tileWalking(larguraTile, alturaTile, 6);
		}
		if (y < this->y && x > this->x + 32 && x < this->x + 64) {
			tileWalking(alturaTile, larguraTile, 4);

		}
	}
	void calcTilePosition(int col, int lin) {
		x = (col - lin) * larguraTile;
		y = (col + lin) * alturaTile;
	}
};