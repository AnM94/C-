#ifndef PAIXNIDI_H
#define PAIXNIDI_H

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include "App.h"

class Paixnidi: public App {
private:
    bool onLine;
    string category;
public:
    Paixnidi(const char* ,  string,  float,  Designer &, vector<Review> rev , float, bool , string);
    void Show();
    void Write2File();


    
    string GetCategory() const { return category; }

    void SetCategory(string category) { this->category = category; }

    bool IsOnLine() const { return onLine; }

    void SetOnLine(bool onLine) { this->onLine = onLine; }
};


#endif /* PAIXNIDI_H */

