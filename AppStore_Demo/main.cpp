#include "Designer.h"
#include "Paixnidi.h"
#include "Review.h"
#include "OfficeApp.h"
#include "App.h"
#include "AppSystem.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    char name[]={"qube"};
    Designer d("1111",name,"sasasa@ffff.com");
    
    char name1[]={"RockStar"};
    Designer d1("1111",name1,"rockstar@games.com");
    
    Review r(4,"anton","cool game");
    Review r1(5,"nicole","Addicted Game! Great Graphics"); 
    Review r2(3,"Sergey","It's not working on my smartphone!");	
    vector< Review >  Reviews1;
    Reviews1.push_back(r);
    Reviews1.push_back(r1);
       
    char code_paixnidi[]={"121250"};   
      
    Paixnidi p(code_paixnidi,"Crash",5.0, d1, Reviews1, 1.99, true,"arcade"); 
    
    p.AddReview(r2);
    p.Show();
    cout<<"------------------------------------------------"<<endl;

    char code_officeApp[]={"191051"};
    
    vector<string> files;
    string s="Text Files"; string s1="Word files"; string s2="Excel Files";
    files.push_back(s); files.push_back(s1); files.push_back(s2);
   
    vector< Review >  Reviews2;
    Review r3(5,"George","Really Usefull! Great Features");
    Review r4(3,"Tomy","Helpfull App. Needs Improvments!");
    Reviews2.push_back(r3);
    Reviews2.push_back(r4);
    
    OfficeApp O(code_officeApp, "Payroll", 4.3, d, Reviews2, 12.99, files);
    O.Show();
        
    cout<<"------------------------------------------------"<<endl;
    Review r5(5,"Josh","There is room for improvment!");
    O.AddReview(r5);
    O.Show();
    O.AverageStars();
    cout<<"------------------------------------------------"<<endl;


    
    char code_officeApp1[]={"123456"};
    OfficeApp O1(code_officeApp1, "Interviews", 3.3, d, Reviews2, 0, files);
    char code_paixnidi1[]={"654321"};
    Paixnidi p1(code_paixnidi,"Driving Simulator",5.0, d1, Reviews1, 1.99, true,"Racing");
    Review r6(5,"Alex","Top 5 of my favorite games!");
    p1.AddReview(r6);
    
    
    vector <App*> Apps;
    Apps.push_back(&p);
    Apps.push_back(&O);
    Apps.push_back(&O);
    Apps.push_back(&p);
    Apps.push_back(&O1);//Δωρεάν OfficeApp
    Apps.push_back(&p1);
    AppSystem AS(Apps);
    AS.ShowData(cout);
    cout<<"------------------------------------------------"<<endl;

    AS.FopFsg();
    cout<<"------------------------------------------------"<<endl;
    
    AS.AddReview(r6,5);
    cout<<"##############################################################"<<endl;
    AS.ShowData(cout);
    AS.FopFsg();
    cout<<"---------------------------"<<endl;
    try{
        AS.WriteAll();
    }catch(const char *msg){
        cout<<msg<<endl;
    }    
    
    exit(0);
}

