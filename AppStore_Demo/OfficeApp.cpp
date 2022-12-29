#include "OfficeApp.h"

using namespace std;

OfficeApp::OfficeApp(const char* code, string le, float v, Designer &d, vector<Review> rev , float p, vector<string> f):
    App(code,le,v,d,rev,p), files(f){}

void OfficeApp::Show(){
    cout<<"This is an office app!"<<endl;
    App::Show();
    cout<<"File Types: ";
    for(int i=0;i<files.size();i++){
        cout<<files[i]<<", ";
    }
    cout<<endl;
}

void OfficeApp::Write2File(){
    App::Write2File();
    std::ofstream os("AllApps.bin", ios::out | ios_base::binary | ios::app);
    if(!os) throw "Error in Writing Office App!";
    
    for(int i=0;i<this->files.size();i++){
            os<<files[i]<<",";   
    }
    
    os<<endl<<"--------------------------------------------"<<endl;
    os.close();
}

OfficeApp::~OfficeApp(){
    if(!files.empty())
        files.clear();
}

