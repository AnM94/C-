#include "Gnome.h"

Gnome::Gnome(int c, int r,vector <string> m):columns(c),rows(r),map(m){ f1=false; f2=false; tmpy=0; tmpx=0; random=2;}

void Gnome::PutGnome(){
	do{
		 tmpy=rand()%(rows-1)+1;
		 tmpx=rand()%(columns-1)+1;
	}while(map[tmpy][tmpx]=='*');
	move(tmpy,tmpx); attron(COLOR_PAIR(2)); addch (GNOME); attroff(COLOR_PAIR(2));
}

bool Gnome::isMoveValid(int r){
	if(r==1){
		if(map[tmpy-1][tmpx]!='*') return true; else return false;
	}else if(r==2){
		if(map[tmpy+1][tmpx]!='*') return true; else return false;
	}else if(r==3){
		if(map[tmpy][tmpx-1]!='*') return true; else return false;
	}else if(r==4){
		if(map[tmpy][tmpx+1]!='*') return true; else return false;
	}
}

void Gnome::Move(){
 	init_pair(GNOME_PAIR, COLOR_YELLOW, COLOR_RED);

	if(f1==true){move(tmpy,tmpx); addch('p');}
	else if(f2==true){move(tmpy,tmpx); addch('P');
	}else{ 
	move(tmpy,tmpx); attron(COLOR_PAIR(2)); addch (GNOME);	attroff(COLOR_PAIR(2));
	move(tmpy, tmpx);  addch (' ');}
	f1=false; f2=false;

	if(Gnome::isMoveValid(random)==false){
		do{
			random=rand()%4+1;	
		}while(Gnome::isMoveValid(random)==false);
	}	
	switch (random)
	{
	case 1:		
			tmpy--;
			if(mvinch(tmpy,tmpx)==112){
				f1=true; 
			}else if(mvinch(tmpy,tmpx)==80){
				f2=true; 
			}
			break;		
	case 2:
			tmpy++;
			if(mvinch(tmpy,tmpx)==112){
				f1=true; 
			}else if(mvinch(tmpy,tmpx)==80){
				f2=true; 
			}
			break;
	case 3:
			tmpx--;
			if(mvinch(tmpy,tmpx)==112){
				f1=true; 
			}else if(mvinch(tmpy,tmpx)==80){
				f2=true; 
			}
			break;
	case 4:
			tmpx++;
			if(mvinch(tmpy,tmpx)==112){
				f1=true;  
			}else if(mvinch(tmpy,tmpx)==80){
				f2=true; 
			}
			break;
	}
	move(tmpy,tmpx); attron(COLOR_PAIR(2)); addch (GNOME); attroff(COLOR_PAIR(2));
}  
