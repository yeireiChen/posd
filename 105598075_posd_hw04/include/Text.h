#ifndef TEXT_H
#define TEXT_H

#include "Rectangle.h"

class Text
{
    public:
        Text(Rectangle*,std::string);
        virtual ~Text();
        std::string getInformation()const;

    protected:

    private:
        std::string information;
        Rectangle* rec;
};

#endif // TEXT_H
