#include "CNCurses.h"
#include "Engine.h"
#include "Moving.h"
#include "Potter.h"
#include "Gnome.h"
#include "Traal.h"
#include "HighScore.h"

using namespace std;

vector<string> OpenFile(const string &filename){
	vector<string> m;
	string line;
    ifstream in;
    in.exceptions(ifstream::badbit);
    try{
    	in.open (filename.c_str(), ios::in);
    	do
    	{
        	getline(in,line);
            m.push_back(line);
    	}
    	while (!in.eof());
	}catch(const ifstream::failure& e){
		mvprintw(10,39,"Error opening map file");
		mvprintw(11,39,e.what());
		refresh();
	}
    in.close ();
    return m;
}

int main(int argc, char *argv[])
{  		
    int row_size=0,col_size=0;
    vector<string> map;
    string Arg_Filename(argv[1]);
	map=OpenFile(Arg_Filename);
	row_size=map.size();
    col_size=map[0].length();
    int score=0;
    bool restart=false;
    int round=1;
    do{
    	if(round==2){
    		map.clear();
    		string Arg_Filename_2(argv[2]);
    		map=OpenFile(Arg_Filename_2);
			row_size=map.size();
    		col_size=map[0].length();
		}
    	Engine E(col_size,row_size,round,map);
    	if(round==1) CNCurses::init();
    	else if(round==2) CNCurses::initRound2();
		E.StartGame();
		score=E.GetScore();
   		CNCurses::exit();

		if(round==1 && score==200){
			if(CNCurses::initQuestion()){
				restart=true;
				round++;
			}
			CNCurses::exit();
		}else if(round==2){
			restart=false;
			score=score+200;
		}
	}while(restart==true);
	
	HighScore Hs; 
	try{
		Hs<<CNCurses::init2(score)<<score;
	}catch(const char *err){
		mvprintw(21,30,err);
		free((char*)err);
	}
	getch();   
    CNCurses::exit();
	
	exit(0);
}
