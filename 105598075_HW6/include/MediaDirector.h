#ifndef MEDIADIRECTOR_H
#define MEDIADIRECTOR_H

#include <stack>
#include "MediaBuilder.h"
#include <stdio.h>
#include <iostream>
#include <map>


class MediaDirector
{
    public:
        MediaDirector();
        virtual ~MediaDirector();
        void setMediaBuilder(std::stack<MediaBuilder*> *mbs);
        void concrete(std::string);
<<<<<<< HEAD
        void buildComb(std::vector<Media*>*,MediaBuilder*);
=======
<<<<<<< HEAD
        void buildComb(std::vector<Media*>*,MediaBuilder*);
=======
        void buildComb(std::string,std::vector<Media*>*,MediaBuilder*);
>>>>>>> e9174e45616b41952ca6b74d1a113054fa3fb436
>>>>>>> origin/master
        void buildShpae(std::string,std::vector<std::string>*,MediaBuilder*);

    protected:

    private:
        std::stack<MediaBuilder*> *mb;
        std::stack<MediaBuilder*> stmp;

};

#endif // MEDIADIRECTOR_H
