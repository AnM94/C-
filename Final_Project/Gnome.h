#ifndef GNOME_H
#define GNOME_H

#include "Moving.h"

#define GNOME_PAIR 2
#define GNOME 'G'

class Gnome:public Moving{
	public:
	int columns;
	int rows;
	int random;
	bool f1;
	bool f2;
	int tmpx;
	int tmpy;
	vector <string> map;
	Gnome(int ,int, vector <string> );
	void PutGnome();
	void Move();
	bool isMoveValid(int );
	
	int GetX(){return tmpx;	}
	int GetY(){return tmpy;	}
};

#endif
