#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H

#include "Media.h"
#include "Text.h"
class textMedia:public Media
{
    public:
        textMedia(Text*);
        virtual ~textMedia();
        double area() const{}
        double perimeter() const{}
        void accept(MediaVisitor*){}
        Text* getText() const;


    protected:

    private:
        Text* txt;
};

#endif // TEXTMEDIA_H
