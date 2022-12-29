#include "CNCurses.h"

void CNCurses::init(){
	initscr();	
	mvprintw (6,43,"LET'S PLAY A GAME!");
    mvprintw (7,39,"press enter to continue....");
	refresh ();
	getch ();
	clear ();
	noecho(); 
	curs_set(0);  
    keypad (stdscr,TRUE);
    start_color();
}

void CNCurses::initRound2(){
	initscr();
	start_color();
	init_pair(INFO_MSG, COLOR_BLACK, COLOR_WHITE);	
	mvprintw (6,38,"GET READY FOR SECOND ROUND!");
	attron(COLOR_PAIR(9));
	mvprintw (7,24,"You will have to catch 15 Stones, and the Map will change!");
	attroff(COLOR_PAIR(9));
    mvprintw (8,39,"press enter to continue....");
	refresh ();
	getch ();
	clear ();
	noecho(); 
	curs_set(0);  
    keypad (stdscr,TRUE);
}

bool CNCurses::initQuestion(){
	initscr();	
	echo(); 
	curs_set(1);
	init_pair(WIN_MSG, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(7));
	mvprintw (5,45,"YOU WON!!");
	attroff(COLOR_PAIR(7));
	mvprintw (6,40,"Do you want round 2?(y/n)");
	refresh ();
	int ch=getch();
	clear ();
	if(ch==121) return true;
	else if(ch==110) return false;
}

char* CNCurses::init2(int score){
	initscr();	
	echo(); 
	curs_set(1); 
	init_pair(WIN_MSG, COLOR_WHITE, COLOR_GREEN);
	init_pair(LOSE_MSG, COLOR_BLACK, COLOR_RED);
	char* name;
	if(score<200){
		attron(COLOR_PAIR(8));
		mvprintw (6,38,"YOU LOSE!!");
		attroff(COLOR_PAIR(8));
	}
	else{
		attron(COLOR_PAIR(7));
		mvprintw (6,38,"YOU WON!!");
		attroff(COLOR_PAIR(7));
	}
	mvprintw (7,35,"YOUR SCORE IS: %d",score);
	mvprintw (8,34,"Enter your name: ");
	refresh ();
	mvgetstr(8,51,name);
	if ((name != NULL) && (name[0] == '\0')) throw "Name field is empty";
	if (strlen(name)>10){ 
		mvprintw(21,30, "Name can't contain more than 10 letters.\n\t\t\t\t It will be trimmed.");
		
	}
	mvprintw (9,34,"let's play again....");
	refresh();
	return name;
}

void CNCurses::exit()
	{
		erase ();
		refresh ();
		endwin ();
	}
