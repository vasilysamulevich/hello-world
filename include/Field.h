#include <iostream>
#include "Cell.h"
#include "Pair.hpp"
class Field{
private:
    Cell* cells;
    int height;
    int width;
    
public:
    Pair_i get_size();
    Field(Pair_i size);
    Field(std::string* string_representation,int height);
    ~Field();
    Cell& get_cell(Pair_i coords);
    
};
