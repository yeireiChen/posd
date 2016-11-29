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
        void concrete(std::string content);

    protected:

    private:
        std::stack<MediaBuilder*> *mb;

};

#endif // MEDIADIRECTOR_H
