#ifndef SHAPEMEDIA_H
#define SHAPEMEDIA_H


#include "Media.h"
#include "Shape.h"

class ShapeMedia:public Media
{
    public:
        ShapeMedia(Shape*);
        virtual ~ShapeMedia();
        double area() const;
        double perimeter() const;
        void accept(MediaVisitor*);
        Shape* getShape() const;

    protected:

    private:
        Shape* shape;
};

#endif // SHAPEMEDIA_H
