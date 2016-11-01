#ifndef CIRCLE_H
#define CIRCLE_H
#include <Shape.h>

class Circle:public Shape
{
    public:
        Circle(double ,double ,double );
        ~Circle();

        std::string shapeName;

        double area() const;
        double perimeter() const;
        std::string getShapeN() const;
    protected:

    private:

        double cx,cy,r,pi;
};

#endif // CIRCLE_H
