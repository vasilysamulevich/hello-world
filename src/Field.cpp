#include "Field.h"


Field::Field(Pair_i toSet) {
    if(toSet.x <0 || toSet.y <0)
        throw std::runtime_error("Wrong bounds");
    height=toSet.x;
    width=toSet.y;

}


Pair_i Field::get_size(){
    return Pair_i(height,width);

} 

Cell& Field::get_cell(Pair_i coords){ //Добавить класс Coord
    if((coords.x >=width || coords.y >= height) || (coords.x<0 || coords.y<0)){
        throw std::runtime_error("Wrong bounds");
    }

    Cell& temp=*(cells+coords.x*width+coords.y);
    return temp; 

}




Field::Field(std::string* source,int height):  width(source[0].length()),height(height){
    if(height <0)
        throw std::runtime_error("Wrong bounds");

    cells=new Cell[height*width];
    

    for(int i=0; i<height;i++){
        if(source[i].length()!=width){
            throw std::runtime_error("Wrong bounds");
        }

    for (int j=0;j<width;j++){
            Pair_i current(i,j);
            switch(source[i][j]){
                case ' ':
                    get_cell(current).set_content(Cell::pass);
                break;
            
                case 'w':
                    get_cell(current).set_content(Cell::unpass);
                break;
                
                default:
                    throw std::runtime_error("Unknown character");
            
             }
        }
    }
}


Field::~Field(){
    delete [] cells;

}



 
