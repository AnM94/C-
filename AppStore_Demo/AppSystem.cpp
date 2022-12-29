#include "AppSystem.h"

AppSystem::AppSystem(vector <App*> Apps): Applications(Apps){}

void AppSystem::ShowData(ostream &x){
    if(!Applications.empty()){
        for (int i=0;i<Applications.size();i++){
            x<<"("<<i+1<<")"<<endl;
            Applications[i]->Show();
            x<<typeid(*Applications[i]).name()<<endl; 
            x<<"------------------"<<endl;
        }
    }
}

void AppSystem::MaliciousApp(string name){
    int pos=0;
    for(int i=0;i<Applications.size();i++){
        if(Applications[i]->D.GetName()==name){
            pos++;
            Applications.erase(Applications.begin()+i);
            cout<<"Application no"<<i+1<<" removed"<<endl;
            cout<<"------------------"<<endl;
        }
    }
    if(pos==0){
        cout<<"Give a valid Designer's name!"<<endl;
        cout<<"------------------"<<endl;
    }    
}

void AppSystem::AddReview(const Review &R, int i){
    int pos=i;
    if(Applications.size()>pos){
        Applications[pos]->App::AddReview(R);
    }else{
        cout<<"Give a valid position!"<<endl;
        cout<<"------------------"<<endl;
    }
}

void AppSystem::FopFsg(){
    string s="";
    for(int i=0;i<Applications.size();i++){
        s=typeid(*Applications[i]).name();
        if(s.substr(1)=="Paixnidi"){
            float avg=Applications[i]->AverageStars();
            if(avg>4)    
                cout<<"Game '"<<Applications[i]->GetLektiko()<<"' has Average Stars: "<<avg<<endl;  
        }else if(s.substr(1)=="OfficeApp"){
            if(Applications[i]->GetPrice()==0)
                cout<<"OfficeApp '"<<Applications[i]->GetLektiko()<<"' is free to use!"<<endl;
        }
		//Otherwise
		/*y=dynamic_cast <Paixnidi *> Applications[i]; //κάνω type casting στο 'Applications[i]' και το εκχωρώ στο 'y'
		  if(y!=NULL){ //Αν δεν είναι NULL σημαίνει ότι είναι τύπου Paixnidi
			    float avg=Applications[i]->AverageStars();
                if(avg>4)    
					cout<<"Game '"<<Applications[i]->GetLektiko()<<"' has Average Stars: "<<avg<<endl;  
          }else{//Αν είναι NULL σημαίνει ότι είναι τύπου OfficeApp
				if(Applications[i]->GetPrice()==0)
		        cout<<"OfficeApp '"<<Applications[i]->GetLektiko()<<"' is free to use!"<<endl;
	    }*/
	}
}    

void AppSystem::WriteAll(){
    for (int i=0;i<Applications.size();i++){
            Applications[i]->Write2File();
        }
}

AppSystem::~AppSystem(){
    for(int i=0;i<Applications.size();i++){
        delete Applications[i];
    }
    Applications.clear();
}

