#ifndef ENGINE_H
#define ENGINE_H

#include <stdlib.h>
#include <panel.h>
#include <curses.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <utility>
#include <exception>
#include <algorithm>
#include "Potter.h"
#include "Gnome.h"
#include "Traal.h"

#define ESCAPE_MSG 5
#define SCORE 6
#define WALL 8

using namespace std;

class Engine{
private:
	int columns;
	int rows;
	int score;
	int round;
public:
	vector<string> map;
	vector<pair<int,int> > StonesVec;
	Engine(int, int, int, vector<string> );
	void OpenMap();
	void PutStones();
	void PutParchment(vector<pair<int,int> > );
	int Score();
	bool isPositionValid(int, int);
	bool PotterOnStone(int, int);
	void StartGame(); 
	
	int GetScore() {return score;}
};

#endif
