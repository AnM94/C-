#ifndef TRAAL_H
#define TRAAL_H

#include "Moving.h"

#define TRAAL_PAIR 3
#define TRAAL 'T'

class Traal:public Moving{
	public:
	int columns;
	int rows;
	int random;
	int steps;
	bool f1;
	bool f2;
	int tmpx;
	int tmpy;
	vector <string> map;
	Traal(int ,int, vector <string> );
	void PutTraal();
	void Move();
	bool isMoveValid(int );
	
	int GetX(){return tmpx;	}
	int GetY(){return tmpy;	}
};

#endif
