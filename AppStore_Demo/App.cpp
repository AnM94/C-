#include "App.h"

using namespace std;

App::App(const char* code, string le, float v, Designer &d, vector<Review> rev , float p) :
lektiko(le), version(v), D(d), reviews(rev), price(p)
{
    app_code=new char[strlen(code)+1];
    strcpy(app_code,code);
}

void App::Show(){
        cout <<"App Code: "<<app_code<<", Name: "<<lektiko<<", Version :"<<version<<endl
            <<"Designer's Name:"<<D.GetName()<<", Designer's Code: "<<D.GetCode()<<", Designer's Email: "<<D.GetEmail()<<endl
            <<"Price: "<<price<<endl;
        cout<<"Reviews: "<<endl;
        for(int i=0;i<reviews.size();i++){
            cout<<"Name: "<<reviews[i].GetName()<<", Stars: "<<reviews[i].GetStars()
                    <<", Comment: "<<reviews[i].GetComment()<<endl;
        }
}

float App::AverageStars(){
    float avg=0;
    float sum=0;
    for (int i=0;i<(App::reviews.size());i++){
        sum=sum+(reviews[i].GetStars());
    }
    avg=sum/(App::reviews.size());

    return avg;
}

void App::AddReview(const Review &R){
    App::reviews.push_back(R);
}

void App::Write2File(){
    std::ofstream os("AllApps.bin", ios::out | ios_base::binary | ios::app);
    if(!os) throw "Error in Writing App!";
    os<<this->app_code<<" "<<this->lektiko<<" "<<this->price<<" "<<this->version<<endl;
    os<<this->D.GetName()<<" "<<this->D.GetCode()<<" "<<this->D.GetEmail()<<endl;
    for(int i=0;i<this->reviews.size();i++){
        os<<this->reviews[i].GetName()<<" "<<this->reviews[i].GetStars()<<" "<<this->reviews[i].GetComment()<<endl;
    }
    os.close();
}

App::~App(){
    delete[] app_code;
    if(!reviews.empty())
        reviews.clear();
}
