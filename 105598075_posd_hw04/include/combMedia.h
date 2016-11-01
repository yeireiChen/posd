#ifndef COMBMEDIA_H
#define COMBMEDIA_H


#include <vector>
#include "Media.h"

class combMedia:public Media
{
     public:
        combMedia();
        virtual ~combMedia();
        double area() const;
        double perimeter() const;
        void accept(MediaVisitor*);
        void add(Media*);

    protected:

    private:
        std::vector<Media*> cMedia;
};

#endif // COMBMEDIA_H
