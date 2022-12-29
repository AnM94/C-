#include "Designer.h"

using namespace std;

Designer::Designer(){
    code="";    
    name=NULL;
    email="";
}

Designer::Designer(string code,const char* n, string email){
    this->code=code;    
    name=new char[strlen(n)+1];
    strcpy(name,n);
    this->email=email;
}