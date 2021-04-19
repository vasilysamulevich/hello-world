#pragma once
#include <iostream>
#include "Cell.h"
#include "Pair.hpp"
class Field{
private:
    Cell* cells;
    int height;
    int width;
    int cell_size;    
public:
    Pair_i get_field_size();
    int get_cell_size();  
    Field(Pair_i size,int cell_size);
    Field(std::string* string_representation,int height,int cell_size);
    Pair_i convert_to_discrete(Pair_d continuous_coords);
    bool check_row(Pair_d start,Pair_d finish); //только для вертикальных и горизонтальных линий
    bool check_rectangle(Pair_d start,Pair_d finish);
    ~Field();
    Cell* get_cell(Pair_i coords);

    
    
};
