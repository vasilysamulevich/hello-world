#include "Cell.h"

int Cell::size=10;

Cell::Cell():content(pass){};

Cell::Cell(cell_type to_set):content(to_set){};

Cell::~Cell(){};

Cell::cell_type Cell::get_content()
{
    return content;
}

void Cell::set_content(cell_type to_set)
{
    content = to_set;
} 
