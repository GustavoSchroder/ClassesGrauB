#pragma once

#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "TileSet.h"


using namespace std;

class IsometricView {
private:
	int larguraTile;
	int alturaTile;
	int x;
	int y;
public:
	void tileWalking(int pLargura, int pAltura, int direcao) {
		switch (direcao)
		{
		case(1): {
				x++;
				y += 2;
			}
		case(2): {
			x++;
			y--;
			}
		case(3): {
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
	void mouseMap() {
		// faz logica
	}
	void calcTilePosition(int col, int lin) {
		x = (col * larguraTile) + (lin * (larguraTile / 2));
		y = lin * (larguraTile / 2);
	}
};