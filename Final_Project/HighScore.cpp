#include "HighScore.h"

HighScore::HighScore(string n, int s):name(n),score(s){tmp_name="";}   

HighScore& HighScore::operator <<(string tmp){
    tmp_name=tmp;
    return *this;
}

void HighScore::operator <<(int score){
    if(tmp_name.length()>0){       
    	if(tmp_name.length()>10){
    		tmp_name=tmp_name.substr(0,10);
		}
        HighScore H(tmp_name,score);
        HighScore::CreateBoardFromFile(H);
    }
}

void HighScore::PrintScores(){
	init_pair(SCORES_BOARD, COLOR_WHITE, COLOR_BLUE);
	init_pair(BOARD_TABLE, COLOR_BLUE, COLOR_BLUE);
	attron(COLOR_PAIR(9));
	mvprintw(11,33,"TOP SCORES");
	attroff(COLOR_PAIR(9));
	for(int i=0;i<5;i++){
		mvprintw(12+i,34,"%d. %s, %d",i+1,(AllScores[i]->GetName()).c_str(),AllScores[i]->GetScore());
	}
	
	for(int x=33;x<54;x++){
			attron(COLOR_PAIR(10));
			if(x>42) mvprintw(11,x,"-");
			
			mvprintw(17,x,"-");
			attroff(COLOR_PAIR(10));  
	}
	
	for(int y=12;y<17;y++){
		attron(COLOR_PAIR(10));
		mvprintw(y,33,"|");
		mvprintw(y,53,"|");
		attroff(COLOR_PAIR(10));
	}
	
}

void HighScore::Write2File(){
	std::ofstream os("HighScore.bin", ios::out | ios_base::binary | ios::trunc);
	if(!os) throw "Error in Writing Scores!";
	for(int i=0;i<5;i++){
            os<<AllScores[i]->GetName()<<" "<<AllScores[i]->GetScore()<<endl;
		
	}
	os.close();
	HighScore::PrintScores();
}

bool maxScore(HighScore &h1, HighScore &h2)
{
    return (h1.GetScore() > h2.GetScore());
}

void HighScore::CreateBoardFromFile(HighScore &H){
    std::ifstream is("HighScore.bin",ios::in | ios::binary );
   	if(!is) throw "Error in Reading Scores!";
   	AllScores=new HighScore *[5];

    string n; int s;
	int i=0, pos=0;
	do{
        n=""; s=0;
        is>>n>>s;
        HighScore tmp(n,s);
        tmpv.push_back(tmp);
        i++;
	}while(i<5);
    is.close();
    for(i=0;i<tmpv.size();i++){
    	if(H.score==tmpv[i].score){
    		mvprintw(18,33,"Your SCORE is the same as: %s's",tmpv[i].name.c_str());
			H.score=0;	
		}
	}
    tmpv.insert(tmpv.begin()+pos,H);
    sort(tmpv.begin(),tmpv.end(),maxScore);
    tmpv.pop_back();

    for(int i=0;i<5;i++){
        AllScores[i]=const_cast<HighScore*>(&tmpv[i]);  
    }
        
    HighScore::Write2File();    
}
