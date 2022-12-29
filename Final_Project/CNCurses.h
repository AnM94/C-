#ifndef CNCURSES_H
#define CNCURSES_H

#include <panel.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define WIN_MSG 7
#define LOSE_MSG 8
#define INFO_MSG 9

using namespace std;

namespace CNCurses{
	void init();
	bool initQuestion();
	void initRound2();
	char* init2(int );
	void exit();

}

#endif
