#ifndef MEDIADIRECTOR_H
#define MEDIADIRECTOR_H

#include <stack>
#include "MediaBuilder.h"
#include <stdio.h>
#include <iostream>


class MediaDirector
{
    public:
        MediaDirector();
        virtual ~MediaDirector();
        void setMediaBuilder(std::stack<MediaBuilder*> *mbs);
        void concrete(std::string);
        void buildComb(std::string,MediaBuilder*);
        void buildShpae(std::string,MediaBuilder*);
        void pushBuilder(MediaBuilder*);

    protected:

    private:
        std::stack<MediaBuilder*> *mb;
        std::stack<MediaBuilder*> stmp;

};

#endif // MEDIADIRECTOR_H
