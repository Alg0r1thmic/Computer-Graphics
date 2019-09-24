#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "shape.h"

class ShapeFactory
{
public:
    ShapeFactory();
    virtual Shape * createShape()=0;
};
class Factory:public ShapeFactory
{
public:
    Factory() {}
    Shape * createShape(){

    }
};
#endif // SHAPEFACTORY_H
