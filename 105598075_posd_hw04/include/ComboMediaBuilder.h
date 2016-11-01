#ifndef COMBOMEDIABUILDER_H
#define COMBOMEDIABUILDER_H

#include <MediaBuilder.h>
#include <combMedia.h>

class ComboMediaBuilder:public MediaBuilder
{
    public:
        ComboMediaBuilder();
        virtual ~ComboMediaBuilder();

        void buildComboMedia();
        void buildShapeMedia(Shape*);
        Media* getMedia();

        void buildAddComboMedia(combMedia*);
    protected:

    private:
        combMedia* combo;
};

#endif // COMBOMEDIABUILDER_H
