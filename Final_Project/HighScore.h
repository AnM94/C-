#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <time.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <panel.h>
#include <curses.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <utility>
#include <exception>
#include <algorithm>
#include <bits/stdc++.h>

#define SCORES_BOARD 9
#define BOARD_TABLE 10

using namespace std;

class HighScore{
private:
	int score;
	string name;
	string tmp_name;
	HighScore **AllScores;
public:
    vector<HighScore> tmpv;
	HighScore() {}
	HighScore(string , int );
	void CreateBoardFromFile(HighScore &);
	void Write2File();
	void PrintScores();
	
	HighScore& operator<< (string );
    void operator<< (int );
	
	string GetName() {return name;}
	
	int GetScore() {return score;}
	
	HighScore** GetAllScores() const {
        return AllScores;
    }

    void SetAllScores(HighScore **newAllScores){
    	AllScores=new HighScore *[5];
    	memcpy(AllScores,newAllScores,5*sizeof(HighScore *));
    }																  
};


#endif

