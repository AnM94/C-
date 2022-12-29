#ifndef REVIEW_H
#define REVIEW_H

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class Review{
private:
    int stars;
    string name;
    string comment;
public:
    Review();
    Review(int, string, string );
    
    string GetComment() const { return comment; }

    void SetComment(string comment) { this->comment = comment; }

    string GetName() const { return name; }

    void SetName(string name) { this->name = name; }

    int GetStars() const { return stars; }

    void SetStars(int stars) { this->stars = stars; }
};

#endif /* REVIEW_H */

