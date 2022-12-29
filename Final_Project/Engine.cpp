#include "Engine.h"

Engine::Engine(int c, int r, int ro, vector<string> m):columns(c),rows(r),round(ro),map(m){score=0;}

void Engine::OpenMap(){	
    init_pair(WALL, COLOR_WHITE, COLOR_WHITE);
    int i=0, y=0 ,x=0;
	do{
		for(x=0;x<columns;x++){
			if(map[y][x]==' '){
				move(y,x); addch(' ');
			}else if(map[y][x]=='*'){
				attron(COLOR_PAIR(8));
				move(y,x); addch('*'); attroff(COLOR_PAIR(8));
			}
		}
    	refresh();
    	i++; y++;
	}while(i<rows);
}

void Engine::PutStones(){
	int x=0, y=0, i=0;
    std::vector<pair<int,int> >::iterator it;
	int numberOfStones;
	if(round==1) numberOfStones=10;
	else if(round==2) numberOfStones=15;
	do{
		y=rand()%(rows-1)+1;
		x=rand()%(columns-1)+1;
    	if(map[y][x]!='*'){
    		StonesVec.push_back(make_pair(y,x));
            it = unique (StonesVec.begin(), StonesVec.end());
            StonesVec.resize(distance(StonesVec.begin(),it));
		}
	}while(StonesVec.size()!=numberOfStones);
	do{
		move(StonesVec[i].first,StonesVec[i].second);
		addch('p');
		i++;
	}while(i<numberOfStones);
}

void Engine::PutParchment(vector<pair<int,int> > MovingObjects){
	int x=0, y=0, i=0;
	do{
		y=rand()%(rows-1)+1;
		x=rand()%(columns-1)+1;
    	if(map[y][x]!='*'){
    	 	for(int j=0;j<MovingObjects.size();j++){
    	 		if((y!=MovingObjects[j].first) && (x!=MovingObjects[j].second)){
					StonesVec.push_back(make_pair(y,x));
					move(y, x); addch ('P');
					i++;
				}
			}
		}
	}while(i<1); 
}

int Engine::Score(){
		init_pair(SCORE, COLOR_WHITE, COLOR_CYAN);
		if(round==1){
			if(score<100){
				score=score+10;
				attron(COLOR_PAIR(6));
				mvprintw(rows,0,"SCORE: %d",score); attroff(COLOR_PAIR(6));
			}else{
				score=score+100;
				attron(COLOR_PAIR(6));
				mvprintw(rows,0,"SCORE: %d",score); attroff(COLOR_PAIR(6));
			}
		}else if(round==2){
				if(score<150){
				score=score+10;
				attron(COLOR_PAIR(6));
				mvprintw(rows,0,"SCORE: %d",score); attroff(COLOR_PAIR(6));
			}else{
				score=score+100;
				attron(COLOR_PAIR(6));
				mvprintw(rows,0,"SCORE: %d",score); attroff(COLOR_PAIR(6));
			}
		}
		return score;
}

bool Engine::isPositionValid(int y, int x){
	bool f=true;
	for(int i=0;i<StonesVec.size();i++){
		if(y==StonesVec[i].first && x==StonesVec[i].second){
			f=false;
		}
	}
	return f;
}

bool Engine::PotterOnStone(int y, int x){
	bool f=false;
	for(int i=0;i<StonesVec.size();i++){
		if(y==StonesVec[i].first && x==StonesVec[i].second){
			StonesVec.erase(StonesVec.begin()+i);
			f=true;
		}
	}
	return f;
}

void Engine::StartGame(){
	int f=false,f2=false;    
	int score=0, score1=100, score2=200;
	if (round==2){ score1=150; score2=250;}
	init_pair(ESCAPE_MSG, COLOR_WHITE, COLOR_MAGENTA);
	Engine::OpenMap(); 
	Engine::PutStones();
	Potter P(columns,rows,map);
    Gnome G(columns,rows,map);
    Traal T(columns,rows,map);
    do{
		P.PutPotter();
	}while(isPositionValid(P.GetY(),P.GetX())==false);
	do{
		G.PutGnome(); 
	}while((isPositionValid(G.GetY(),G.GetX())==false) && (G.GetY()!=P.GetY()) && (G.GetX()!=P.GetX()));	
    do{
		T.PutTraal();
	}while((isPositionValid(T.GetY(),T.GetX())==false) && (T.GetY()!=G.GetY()) && (T.GetY()!=P.GetY())
	&& (T.GetY()!=P.GetY()) && (T.GetX()!=P.GetX()));
	
	do{
		try{
			P.Move();
			if(Engine::PotterOnStone(P.GetY(),P.GetX())) score=Engine::Score();			
		}catch(const char *escape){
			attron(COLOR_PAIR(5));
			mvprintw(10,30,escape);
			attroff(COLOR_PAIR(5));
			refresh(); sleep(1);
			f2=true;		
		}
		G.Move();
		T.Move();
		if((G.GetX()==P.GetX() && G.GetY()==P.GetY()) || (T.GetX()==P.GetX() && T.GetY()==P.GetY())) f2=true;
		if(score==score1){f=true;}
	}while(f==false && f2==false);
	
	if(f2==false){
		f=false;  
		vector<pair<int,int> > MovingObjects;
		MovingObjects.push_back(make_pair(P.GetY(),P.GetX()));
		MovingObjects.push_back(make_pair(T.GetY(),T.GetX()));
		MovingObjects.push_back(make_pair(G.GetY(),G.GetX()));
		Engine::PutParchment(MovingObjects);
		do{
			try{
				P.Move();
				if(Engine::PotterOnStone(P.GetY(),P.GetX())) score=Engine::Score();
			}catch(const char *escape){
				attron(COLOR_PAIR(5));
				mvprintw(10,30,escape);
				attroff(COLOR_PAIR(5));
				refresh(); sleep(1);
				f2=true;		
			}
			G.Move();
			T.Move();	
			if((G.GetX()==P.GetX() && G.GetY()==P.GetY()) || (T.GetX()==P.GetX() && T.GetY()==P.GetY())) f2=true;
			if(score==score2){f=true;}
		}while(f==false && f2==false);
	}	
}




