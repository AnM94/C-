#ifndef APPSYSTEM_H
#define APPSYSTEM_H

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <typeinfo>
#include <string>
#include <fstream>
#include "App.h"

using namespace std;

class AppSystem{
private:
    vector <App*> Applications;
public:
    AppSystem(vector <App*> );
    void ShowData(ostream & );
    void AddReview(const Review & , int );
    void MaliciousApp(string ); 
    void FopFsg();
    void WriteAll();
    ~AppSystem();
};

#endif /* APPSYSTEM_H */

