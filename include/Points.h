#include "Element.h"
class Points{
    int scores;
public:
    Points(int scores=50);
    void operator+(Player& player);
    void print();
};
