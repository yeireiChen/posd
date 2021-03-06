#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <sstream>

class Triangle :public Shape
{
    public:
        Triangle(double,double,double,double,double,double);
        virtual ~Triangle();

        std::string shapeName;

        double area() const ;
        double perimeter() const;
        void showArea() const;
        void showPerimeter() const;
        std::string getShapeN() const;
        std::string getDec() const;

        bool getSuccess() const;

    protected:

    private:
        double fx,fy,sx,sy,tx,ty,fWidth,sWidth,tWidth;
        bool t;
};

#endif // TRIANGLE_H
