#include "Pair.h"

Pair::Pair(int first, int second): x(first), y(second){}
void Pair::print(){
    std::cout<<x<<" "<<y<<'\n';    
}

bool Pair::checkBounds(int height, int width){

    if (x < 0 || x >=height || y <0 || y >=width)
        return 0;
    return 1;
}

