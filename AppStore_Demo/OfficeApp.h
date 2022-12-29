#ifndef OFFICEAPP_H
#define OFFICEAPP_H

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "App.h"

class OfficeApp: public App{
private:
    vector<string> files;
public:
    OfficeApp(const char* ,  string,  float,  Designer &, vector<Review> rev , float, vector<string> );
    void Show();
    void Write2File();
    ~OfficeApp();
    
    vector<string> GetFiles() const {
        return files;
    }

    void SetFiles(vector<string> files) {
        this->files = files;
    }

};

#endif /* OFFICEAPP_H */

