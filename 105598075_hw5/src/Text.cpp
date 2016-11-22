#include "Text.h"

Text::Text(Rectangle* r,std::string s):rec(r),information(s){}

Text::~Text(){}

std::string Text::getInformation()const{
    return information;
}
