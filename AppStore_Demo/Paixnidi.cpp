#include "Paixnidi.h"

using namespace std; 

Paixnidi::Paixnidi(const char* code, string le, float v, Designer &d, vector<Review> rev , float p, bool onL, string cat) :
App(code,le,v,d,rev,p), onLine(onL), category(cat){} 

void Paixnidi::Show(){
    cout<<"This is a game!"<<endl;
    App::Show();
    cout<<"Online:"<<onLine<<", Category: "<<category<<endl;
}

void Paixnidi::Write2File(){
    App::Write2File();
    std::ofstream os("AllApps.bin", ios::out | ios_base::binary | ios::app);
    if(!os) throw "Error in Writing Paixnidi!";
    os<< onLine << " "<< category<<endl;
    os<<"--------------------------------------------"<<endl;
    os.close();
}

