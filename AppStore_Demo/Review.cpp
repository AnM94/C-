#include "Review.h"

Review::Review(){
    stars=0;
    name="";
    comment="";
}

Review::Review(int stars, string name, string comment){
    this->stars=stars;
    this->name=name;
    this->comment=comment;
}
