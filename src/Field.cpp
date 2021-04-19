#include "Field.h"

int Field::get_cell_size()
{
    return cell_size;
}

Field::Field(Pair_i toSet,int cell_size):cell_size(cell_size) {
    if(toSet.x <0 || toSet.y <0)
        throw std::runtime_error("Wrong bounds");
    height=toSet.y;
    width=toSet.x;
    cells=new Cell[height*width];

}


Pair_i Field::get_field_size(){
    return Pair_i(width,height);

} 

Cell* Field::get_cell(Pair_i coords){ //Добавить класс Coord
    if((coords.x >=width || coords.y >= height) || (coords.x<0 || coords.y<0)){
        return nullptr;
    }

    Cell* temp=cells+coords.y*width+coords.x;
    return temp; 

}




Field::Field(std::string* source,int height,int cell_size):  width(source[0].length()),height(height),cell_size(cell_size){
    if(height <0)
        throw std::runtime_error("Wrong bounds1");

    cells=new Cell[height*width];
    

    for(int i=0; i<height;i++){
        if(source[i].length()!=width){
            throw std::runtime_error("Wrong bounds2");
        }

    for (int j=0;j<width;j++){
            Pair_i current(j,i);
            switch(source[i][j]){
                case ' ':
                    get_cell(current)->set_content(Cell::pass);
                break;
            
                case 'w':
                    get_cell(current)->set_content(Cell::unpass);
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


Pair_i Field::convert_to_discrete(Pair_d continuous_coords){
    if(continuous_coords.x<0 || continuous_coords.y <0) //костыль
        return Pair_i(-1,-1);
    return Pair_i(continuous_coords.x/cell_size, continuous_coords.y/cell_size);

}


bool Field::check_row(Pair_d start,Pair_d finish){ //const?
    if(start.x > finish.x || start.y > finish.y){ //сделать функцию swap
        Pair_d temp=start;
        start=finish;
        finish=temp;
    }

    Pair_i dStart=convert_to_discrete(start);
    Pair_i dFinish=convert_to_discrete(finish);
    Pair_i direction(0,0); 
    if(dStart.x < dFinish.x){
        direction.x=1;
    }
    else{
        direction.y=1;
    }
    
    while(dStart.x <=dFinish.x && dStart.y <=dFinish.y){ //???
    Cell* current_cell=get_cell(dStart);
    if(current_cell==nullptr)
        return false;

    if(current_cell->get_content()==Cell::unpass)
        return false;

    dStart=dStart+direction;  
    }
    return true;
}



bool Field::check_rectangle(Pair_d start,Pair_d finish){
    if(start.x > finish.x){
        double temp=start.x;
        start.x=finish.x;
        finish.x=temp;

    }

    if(start.y > finish.y){
        double temp=start.y;
        start.y=finish.y;
        finish.y=temp;
    } //создать метод?

    Pair_d RU_counter=Pair_d(finish.x,start.y);
    while(RU_counter.y <= finish.y){
        if(!check_row(start,RU_counter))
            return false;
        start.y=start.y+cell_size;
        RU_counter.y=RU_counter.y+cell_size;        

    }
    return true;    
}



 
