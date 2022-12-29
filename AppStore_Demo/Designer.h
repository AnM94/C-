#ifndef DESIGNER_H
#define DESIGNER_H

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std; 

class Designer{
private:
    string code;
    char* name;
    string email;
public:
    
    Designer();
    Designer(string, const char*, string );
    
    string GetCode() const { return code; }

    void SetCode(string code) { this->code = code; }

    string GetEmail() const { return email; }

    void SetEmail(string email) { this->email = email; }

    char* GetName() const { return name; }

    void SetName(char* n) {
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }
};
     
#endif /* DESIGNER_H */

