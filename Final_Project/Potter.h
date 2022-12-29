#ifndef POTTER_H
#define POTTER_H
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <panel.h>
#include <curses.h>

#include "Moving.h"

#define PLAYER_PAIR 1
#define PLAYER 'M'

class Potter:public Moving{
	
public:
	int columns;
	int rows;
	int tmpx;
	int tmpy;
	vector <string> map;
	Potter(int ,int ,vector <string> ); 
	void PutPotter();
	void Move();
	int GetX(){return tmpx;	}
	int GetY(){return tmpy;	}
};

#endif
