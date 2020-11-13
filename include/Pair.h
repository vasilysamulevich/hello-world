#pragma once
#include <iostream>
class Pair{
public:
    int x;
    int y;
    Pair(int first=-1, int second=-1);
    bool checkBounds(int height, int width);
    void print();
};

