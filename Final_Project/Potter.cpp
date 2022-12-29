#include "Potter.h"

Potter::Potter(int c, int r, vector<string> m):columns(c),rows(r),map(m){tmpy=0; tmpx=0;}

void Potter::PutPotter(){
	do{
		 tmpy=rand()%(rows-1)+1;
		 tmpx=rand()%(columns-1)+1;
	}while(map[tmpy][tmpx]=='*');
	move(tmpy,tmpx); attron(COLOR_PAIR(1));	addch(PLAYER);	attroff(COLOR_PAIR(1));	
}

void Potter::Move(){
 	init_pair(PLAYER_PAIR, COLOR_CYAN, COLOR_BLUE);
 	
 	move(tmpy,tmpx);
 	attron(COLOR_PAIR(1));
	addch (PLAYER);
	attroff(COLOR_PAIR(1));
	int ch; 
	ch = getch ();
	if(ch!=27)
	{	
		move(tmpy, tmpx);
		addch (' ');
		if(ch!=32){
			switch (ch)
			{
			case KEY_UP :if(map[tmpy-1][tmpx]!='*') tmpy--; break; 
			case KEY_DOWN :if(map[tmpy+1][tmpx]!='*') tmpy++; break; 
			case KEY_LEFT:if(map[tmpy][tmpx-1]!='*') tmpx--; break; 
			case KEY_RIGHT:if(map[tmpy][tmpx+1]!='*') tmpx++; break;
			}
		}
		move(tmpy, tmpx);
		attron(COLOR_PAIR(1));
		addch (PLAYER);
		attroff(COLOR_PAIR(1));
		
	}else{
		throw "You Pressed Escape!";
	}	
}



