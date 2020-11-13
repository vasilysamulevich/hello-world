#pragma once
#include "Pair.h"
#include "Element.h"
class Teleport : public Element
{
public:
    enum type {entrance,quit};
    Teleport(type content=quit, Pair coords=Pair());
    void operator+(Player &player);
    void print();

private:
    type content;
    Pair coords;
};
