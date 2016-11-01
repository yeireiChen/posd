#include "ComboMediaBuilder.h"

ComboMediaBuilder::ComboMediaBuilder():combo(0){}

ComboMediaBuilder::~ComboMediaBuilder(){}

void ComboMediaBuilder::buildComboMedia(){
    combo = new combMedia();
}

void ComboMediaBuilder::buildShapeMedia(Shape* t){
    if(!combo)
            throw std::string("null point ex") ;
        combo->add(new ShapeMedia(t));
}

void ComboMediaBuilder::buildAddComboMedia(combMedia * cm){
        combo->add(cm);
    }
Media* ComboMediaBuilder::getMedia(){

    return combo;
}
