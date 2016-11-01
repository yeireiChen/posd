
#include "combMedia.h"
#include <vector>

using namespace std;

combMedia::combMedia(){}

combMedia::~combMedia(){}

double combMedia::area()const{

    double temp=0;
    for(Media* a : cMedia){
        temp+=a->area();
    }

    return temp;
}

double combMedia::perimeter()const{

    double temp=0;
    for(Media* a : cMedia){
        temp+=a->perimeter();
    }

    return temp;
}

void combMedia::add(Media* a){

    cMedia.push_back(a);
}

void combMedia::accept(MediaVisitor* visit){
    for (Media *m: cMedia)
            m->accept(visit);
        visit->visitCombMedia(this);
}
