#ifndef MOVING_H
#define MOVING_H

#include <iostream>

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <panel.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;

class Moving{
public:
	int tmpy;
	int tmpx;
	virtual void Move()=0;
};


#endif
