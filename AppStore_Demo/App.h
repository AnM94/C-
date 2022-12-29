#ifndef APP_H
#define APP_H

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Review.h"
#include "Designer.h"

class App{
protected:
    char* app_code;
    string lektiko;
    float version;
    Designer &D;
    vector<Review> reviews;
    float price;
public:
    App(const char* , string , float , Designer & , vector<Review> , float ) ;
    virtual void Show();
    float AverageStars();
    void AddReview(const Review & );
    friend class AppSystem; 
    virtual void Write2File();
    virtual ~App();
    
    Designer GetD() const { return D; }

    void SetD(Designer D) { this->D = D; }

    char* GetApp_code() const { return app_code; }

    void SetApp_code(char* code) {
        app_code=new char[strlen(code)+1];
        strcpy(app_code,code);
    }

    string GetLektiko() const { return lektiko; }

    void SetLektiko(string lektiko) { this->lektiko = lektiko; }

    float GetPrice() const { return price; }

    void SetPrice(float price) { this->price = price; }

    float GetVersion() const { return version; }

    void SetVersion(float version) { this->version = version; }

    vector<Review> GetReviews() const { return reviews; }

    void SetReviews(vector<Review> reviews) { this->reviews = reviews; }

};

#endif /* APP_H */

