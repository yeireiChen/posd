#ifndef MEDIAVISITOR_H_INCLUDED
#define MEDIAVISITOR_H_INCLUDED

class ShapeMedia;
class combMedia;

class MediaVisitor {

public:
    virtual void visitShapeMedia(ShapeMedia*) =0;
    virtual void visitCombMedia(combMedia*) =0;
};

#endif // MEDIAVISITOR_H_INCLUDED
